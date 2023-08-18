// Code for instructions for "How to play the game controls and all".


#ifndef __HELP__
#define __HELP__

#include <simplecpp>
#include "lasso.h"

int help(){
    for(;;){
        Text t1(WINDOW_X/2,100+textHeight(),">> Catching a coin(yellow color) to increase your score");
        Text t2(WINDOW_X/2,100+textHeight()*2,">> Catching a bomb(red color) loses your health");
        Text t3(WINDOW_X/2,100+textHeight()*3,">> Catch the required number of coins to pass a level");
        Text t4(WINDOW_X/2,100+textHeight()*4,">> Lose your all lives u die");
        Text t5(WINDOW_X/2,100+textHeight()*5,">> Press ']' tilt/rotate the lasso direction in anti-clockwise");
        Text t6(WINDOW_X/2,100+textHeight()*6,">> Press '[' tilt/rotate the lasso direction in clockwise");
        Text t7(WINDOW_X/2,100+textHeight()*7,">> Press '=' to increase the throwing speed of your lasso");
        Text t8(WINDOW_X/2,100+textHeight()*7,">> Press '-' to increase the throwing speed of your lasso");
        Text t9(WINDOW_X/2,100+textHeight()*8,">> Press 'L' to loop an object into your lasso");
        Text t10(WINDOW_X/2,100+textHeight()*9,">> Press 'Y' to pull-back the lasso you had thrown");
        Text t11(WINDOW_X/2,100+textHeight()*10,">> Press 'T' to throw the lasso");
        Text t12(WINDOW_X/2,100+textHeight()*11,">> Press 'Q' to go back to homepage");
        Text t13(WINDOW_X/2,100+textHeight()*12,">> Some levels will have numbers popping, Catch the number gives you that many coins");
        Text t14(WINDOW_X/2,100+textHeight()*14,"BACK");
        Rectangle r(WINDOW_X/2,100+textHeight()*14,textWidth("BACK"),textHeight());

        int clickpos = getClick();
        int x = clickpos/65536;
        int y = clickpos%65536;
        if(  // Back button response reciever
        x > WINDOW_X/2 - textWidth("BACK")/2 &&
        x < WINDOW_X/2 + textWidth("BACK")/2 &&
        y > 100+textHeight()*14 - textHeight()/2 &&
        y < 100+textHeight()*14 + textHeight()/2
        ){return 0;}
    }
}
#endif