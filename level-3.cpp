#include <simplecpp>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "levelManage.h"
#include "lasso.h"
#include "numberCoin.h"

int level_3(XEvent &e){  // Third level start
    int stepCount = 0;
    float stepTime = STEP_TIME;
    float runTime = -1; // sec; -ve means infinite
    float currTime = 0;

    // Draw lasso at start position
    double release_speed = INIT_RELEASE_SPEED; // m/s
    double release_angle_deg = INIT_RELEASE_ANGLE_DEG; // degrees
    double lasso_ax = 0;
    double lasso_ay = LASSO_G;
    bool paused = true;
    bool rtheta = true;
    Lasso lasso(release_speed, release_angle_deg, lasso_ax, lasso_ay, paused, rtheta);

    Line b1(0, PLAY_Y_HEIGHT, WINDOW_X, PLAY_Y_HEIGHT);
    b1.setColor(COLOR("blue"));
    Line b2(PLAY_X_START, 0, PLAY_X_START, WINDOW_Y);
    b2.setColor(COLOR("blue"));

    string msg("Cmd: _");
    Text charPressed(PLAY_X_START+50, PLAY_Y_HEIGHT+20, msg);
    char coinScoreStr[256];
    char lassoHealthStr[25];
    sprintf(lassoHealthStr, "Health: %d", lasso.getHealth());
    sprintf(coinScoreStr, "Coins: %d", lasso.getNumCoins());
    Text coinScore(PLAY_X_START+50, PLAY_Y_HEIGHT+50, coinScoreStr);
    Text lassoHealth(PLAY_X_START+50, PLAY_Y_HEIGHT+50+20, lassoHealthStr);

    paused = true; rtheta = true;
    double coin_speed = COIN_SPEED;
    double coin_angle_deg = COIN_ANGLE_DEG;
    double coin_ax = 0;
    double coin_ay = COIN_G;
    numCoin coin(coin_speed, coin_angle_deg, coin_ax, coin_ay, paused, rtheta);
    Bomb bomb(coin_speed*1.25, coin_angle_deg+25, coin_ax, coin_ay, paused, rtheta);
    

    // After every COIN_GAP sec, make the coin jump
    double last_coin_jump_end = 0;
    double last_bomb_jump_end = 0;

    // When t is pressed, throw lasso
    // If lasso within range, make coin stick
    // When y is pressed, yank lasso
    // When l is pressed, loop lasso
    // When q is pressed, quit

    for(;;) {
        if((runTime > 0) && (currTime > runTime)) { break; }

        // XEvent e;
        bool pendingEv = checkEvent(e);
        if(pendingEv) {
            char c = charFromEvent(e);
            msg[msg.length()-1] = c;
            charPressed.setMessage(msg);
            switch(c) {
                case 't':
                    lasso.unpause();
                    break;
                case 'y':
                    lasso.yank();
                    break;
                case 'l':
                    lasso.loopit();
                    lasso.check_for_number(&coin);
                    lasso.check_for_bomb(&bomb);
                    wait(STEP_TIME*5);
                    break;
                case '[':
                    if(lasso.isPaused()) { lasso.addAngle(-RELEASE_ANGLE_STEP_DEG);	}
                    break;
                case ']':
                    if(lasso.isPaused()) { lasso.addAngle(+RELEASE_ANGLE_STEP_DEG); }
                    break;
                case '-':
                    if(lasso.isPaused()) { lasso.addSpeed(-RELEASE_SPEED_STEP); }
                    break;
                case '=':
                    if(lasso.isPaused()) { lasso.addSpeed(+RELEASE_SPEED_STEP); }
                    break;
                case 'q':
                    return -1;
                default:
                    break;
                }
            }

            lasso.nextStep(stepTime);

            coin.nextStep(stepTime);
            bomb.nextStep(stepTime);
            if(coin.isPaused()) {
                if((currTime-last_coin_jump_end) >= COIN_GAP) {
                    coin.unpause();
                }
            }
            if(bomb.isPaused()) {
            if((currTime-last_bomb_jump_end) >= COIN_GAP) {
                bomb.unpause();
            }
        }

        if(coin.getYPos() > PLAY_Y_HEIGHT) {
            coin.resetnumCoin();
            last_coin_jump_end = currTime;
        }


        if(bomb.getYPos() > PLAY_Y_HEIGHT) {
            bomb.resetBomb();
            last_bomb_jump_end = currTime;
        }

        sprintf(coinScoreStr, "Coins: %d/25", lasso.getNumCoins()); // Updates coin count
        coinScore.setMessage(coinScoreStr);
        sprintf(lassoHealthStr, "Health: %d/3", lasso.getHealth()); // Updates health
        lassoHealth.setMessage(lassoHealthStr);

        stepCount++;
        currTime += stepTime;
        wait(stepTime);

        if(lasso.getNumCoins() >= 25){  // checking for level completion
            Text levelComplete(WINDOW_X/2,WINDOW_Y/2,"LEVEL-3 COMPLETED");
            wait(1);
            Text nextLevel(WINDOW_X/2,WINDOW_Y/2 + 30,"YOU WON, Thanks for playing \n Stay tuned for newer updates :)");
            wait(3);
            return 4;
        }
        if(lasso.getHealth() <= 0){ // checking death of lasso
            Text dead(WINDOW_X/2,WINDOW_Y/2,"YOU LASSO GOT TORN DUE TO BOMBS");
            wait(2);
            return -1;
        }

    } // End for(;;)
} // Third level end