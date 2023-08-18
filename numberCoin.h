#ifndef __NUMBER_COIN__
#define __NUMBER_COIN__

#include <simplecpp>
#include "MovingObject.h"

class numCoin : public MovingObject{
    double numCoin_start_x;
	double numCoin_start_y;
	double release_speed;
	double release_angle_deg;
	double numCoin_ax;
	double numCoin_ay;
    int coinValue;  // value of the number popping

    //Moving part
    Text number;

    public:
    numCoin(double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta) : MovingObject(speed, angle_deg, argax, argay, argpaused, rtheta){
        release_speed = speed;
        release_angle_deg = angle_deg;
        numCoin_ax = argax;
        numCoin_ay = argay;
        initnumCoin();
    }

    void initnumCoin();
    void resetnumCoin();
    int getCoinValue(){ return coinValue; }
};
#endif