#include <cstdlib>
#include "numberCoin.h"
#include "lasso.h"

void numCoin::initnumCoin(){
    numCoin_start_x = PLAY_X_START + LASSO_X_OFFSET + 50 + rand()%(WINDOW_X - PLAY_X_START - LASSO_X_OFFSET - 100); //initialising with random position
	numCoin_start_y = PLAY_Y_HEIGHT;
    int random9 = rand()%9;  // gets random value in between 0-9
    coinValue = random9;  // sets the random value
    number.reset(numCoin_start_x, numCoin_start_y, random9);
    number.setColor(COLOR("black"));
    addPart(&number);
}

void numCoin::resetnumCoin(){
    double numCoin_speed = rand()%(MAX_RELEASE_SPEED-100) + 40;  // setting random speed with a minimum of 40
	double numCoin_angle_deg = 60 + rand()%60; // setting random angle with range of 60 to 120 degs
	numCoin_ax = 0;
	numCoin_ay = COIN_G;
	bool paused = true, rtheta = true;
    int random9 = rand()%9;
    coinValue = random9;

    // randomising the popping position
    int x = PLAY_X_START + LASSO_X_OFFSET + 100 + rand()%(WINDOW_X - PLAY_X_START - LASSO_X_OFFSET - 100);
	reset_all(x, numCoin_start_y, numCoin_speed, numCoin_angle_deg, numCoin_ax, numCoin_ay, paused, rtheta);
    number.reset(x, numCoin_start_y, random9);
}