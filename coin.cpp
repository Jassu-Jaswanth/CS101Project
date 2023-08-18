#include <cstdlib>
#include "coin.h"
#include "lasso.h"

void Coin::initCoin() {
	coin_start_x = PLAY_X_START + LASSO_X_OFFSET + 50 + rand()%(WINDOW_X - PLAY_X_START - LASSO_X_OFFSET - 100); // initialising with random position
	coin_start_y = PLAY_Y_HEIGHT;
	coin_circle.reset(coin_start_x, coin_start_y, COIN_SIZE);
	coin_circle.setColor(COLOR("yellow"));
	coin_circle.setFill(true);
	addPart(&coin_circle);
}

void Coin::resetCoin() {
	double coin_speed = rand()%(MAX_RELEASE_SPEED-100) + 40;  // setting random speed with a minimum of 40
	double coin_angle_deg = 60 + rand()%60; // setting random angle with range of 60 to 120 degs
	coin_ax = 0;
	coin_ay = COIN_G;
	bool paused = true, rtheta = true;
	// resetting with random position.
	reset_all(PLAY_X_START + LASSO_X_OFFSET + 50 + rand()%(WINDOW_X - PLAY_X_START - LASSO_X_OFFSET - 100), coin_start_y, coin_speed, coin_angle_deg, coin_ax, coin_ay, paused, rtheta);
}
