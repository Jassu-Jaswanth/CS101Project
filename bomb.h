#ifndef __BOMB__
#define __BOMB__

#include "MovingObject.h"

class Bomb : public MovingObject{
	double bomb_start_x;
	double bomb_start_y;
	double release_speed;
	double release_angle_deg;
	double bomb_ax;
	double bomb_ay;

	// Moving parts
	Circle bomb_circle;

	public:
	Bomb(double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta) : MovingObject(speed, angle_deg, argax, argay, argpaused, rtheta) {
    	release_speed = speed;
    	release_angle_deg = angle_deg;
    	bomb_ax = argax;
    	bomb_ay = argay;
    	initBomb();
	}

	void initBomb();
	void resetBomb();
  
};  // end bomb class

#endif