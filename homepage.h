// Game opening page with start, help and exit buttons.

#ifndef __HOMEPAGE__
#define __HOMEPAGE__

#include <simplecpp>
#include "lasso.h"

int homepage(){     // homepage start
    for(;;){
        // Making of main title with combination of lines as alphabets.
        double cX = WINDOW_X/2;
        double cY = WINDOW_Y/2 - 100;
        double gap = 100; //letter gap
        double oX = cX - 250; //origin x
        double oY = cY - 50; //origin y

        Line l1(oX+10,oY+10,oX+10,oY+90); // letter L
        l1.setColor(COLOR("blue"));
        Line l2(oX+10,oY+90,oX+90,oY+90); // letter L
        l2.setColor(COLOR("blue"));
        Line a1(oX+gap+10,oY+10,oX+gap+90,oY+10); // letter A
        a1.setColor(COLOR("red"));
        Line a2(oX+gap+10,oY+10,oX+gap+10,oY+90); // letter A
        a2.setColor(COLOR("red"));
        Line a3(oX+gap+10,oY+50,oX+gap+90,oY+50); // letter A
        a3.setColor(COLOR("red"));
        Line a4(oX+gap+90,oY+10,oX+gap+90,oY+90); // letter A
        a4.setColor(COLOR("red"));

        Line s1(oX+gap*2+10,oY+10,oX+gap*2+90,oY+10); // letter S
        s1.setColor(COLOR("red"));
        Line s2(oX+gap*2+10,oY+50,oX+gap*2+90,oY+50); // letter S
        s2.setColor(COLOR("red"));
        Line s3(oX+gap*2+10,oY+10,oX+gap*2+10,oY+50); // letter S
        s3.setColor(COLOR("red"));
        Line s4(oX+gap*2+90,oY+50,oX+gap*2+90,oY+90); // letter S
        s4.setColor(COLOR("red"));
        Line s5(oX+gap*2+10,oY+90,oX+gap*2+90,oY+90); // letter S
        s5.setColor(COLOR("red"));
        Line S1(oX+gap*3+10,oY+10,oX+gap*3+90,oY+10); // letter S
        S1.setColor(COLOR("green"));
        Line S2(oX+gap*3+10,oY+50,oX+gap*3+90,oY+50); // letter S
        S2.setColor(COLOR("green"));
        Line S3(oX+gap*3+10,oY+10,oX+gap*3+10,oY+50); // letter S
        S3.setColor(COLOR("green"));
        Line S4(oX+gap*3+90,oY+50,oX+gap*3+90,oY+90); // letter S
        S4.setColor(COLOR("green"));
        Line S5(oX+gap*3+10,oY+90,oX+gap*3+90,oY+90); // letter S
        S5.setColor(COLOR("green"));

        Line o1(oX+gap*4+10,oY+10,oX+gap*4+90,oY+10); // letter O
        Line o2(oX+gap*4+10,oY+90,oX+gap*4+90,oY+90); // letter O
        Line o3(oX+gap*4+10,oY+10,oX+gap*4+10,oY+90); // letter O
        Line o4(oX+gap*4+90,oY+10,oX+gap*4+90,oY+90); // letter O
        
        Text start(WINDOW_X/2, WINDOW_Y/2, "START");  // start button
        Rectangle r1(WINDOW_X/2,WINDOW_Y/2,textWidth("START"), textHeight());
    
        Text help(WINDOW_X/2, WINDOW_Y/2 + 30, "HELP");  // instructions page button
        Rectangle r2(WINDOW_X/2, WINDOW_Y/2 + 30,textWidth("HELP"), textHeight());

        Text exit(WINDOW_X/2, WINDOW_Y/2 + 60, "Quit");  // exit button
        Rectangle r3(WINDOW_X/2,WINDOW_Y/2 + 60,textWidth("QUIT"), textHeight());
        int clickpos = getClick();
        int x = clickpos/65536;
        int y = clickpos%65536;
        if(  // start button response reciver
        x > WINDOW_X/2 - textWidth("START")/2 &&
        x < WINDOW_X/2 + textWidth("START")/2 &&
        y > WINDOW_Y/2 - textHeight()/2 &&
        y < WINDOW_Y/2 + textHeight()/2
        ){return 1;}
        if(  // Help button response reciever
        x > WINDOW_X/2 - textWidth("HELP")/2 &&
        x < WINDOW_X/2 + textWidth("HELP")/2 &&
        y > WINDOW_Y/2 - textHeight()/2 + 30 &&
        y < WINDOW_Y/2 + textHeight()/2 + 30
        ){return 2;}
        if(  // Exit button response reciever
        x > WINDOW_X/2 - textWidth("EXIT")/2 &&
        x < WINDOW_X/2 + textWidth("EXIT")/2 &&
        y > WINDOW_Y/2 - textHeight()/2 + 60 &&
        y < WINDOW_Y/2 + textHeight()/2 + 60
        ){return 0;}
    }
} // homepage end

#endif