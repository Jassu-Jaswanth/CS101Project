#include "bomb.h"
#include "lasso.h"
#include <ctime>
#include <cstdlib>

void Bomb::initBomb(){
	bomb_start_x = PLAY_X_START + LASSO_X_OFFSET + 50 + rand()%(WINDOW_X - PLAY_X_START - LASSO_X_OFFSET - 100); // initialising with random position
	bomb_start_y = PLAY_Y_HEIGHT;
	bomb_circle.reset(bomb_start_x, bomb_start_y, COIN_SIZE);
	bomb_circle.setColor(COLOR("red"));
  	bomb_circle.setFill(true);
  	addPart(&bomb_circle);
}

void Bomb::resetBomb(){
	double bomb_speed = rand() % (MAX_RELEASE_SPEED-100) + 40;  // setting random speed with a minimum of 40
	double bomb_angle_deg = 50 + rand()%80;  // setting random angle with range of 50 to 130 degs
	bomb_ax = 0;
	bomb_ay = COIN_G;
	bool paused = true, rtheta = true;
	// resetting with random popping position
	reset_all(PLAY_X_START + LASSO_X_OFFSET + 50 + rand()%(WINDOW_X - PLAY_X_START - LASSO_X_OFFSET - 100), bomb_start_y, bomb_speed, bomb_angle_deg, bomb_ax, bomb_ay, paused, rtheta);
}