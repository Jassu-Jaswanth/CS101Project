/* Made in windows 10 64-bit with VScode */

#include <simplecpp>
#include <cstdlib>
#include <ctime>
#include "levelManage.h"
#include "homepage.h"
#include "guide.h"

using namespace simplecpp;

int main(){
	srand((unsigned) time(0));
	initCanvas("Lasso", WINDOW_X, WINDOW_Y);
	XEvent e;
	int HPresponse = homepage();
	int levelCheck = 1;
	Mainpage:
		if(HPresponse == 1){
			switch (levelCheck){
				case 1:
					levelCheck = level_1(e);
					if(levelCheck == -1){ 
					    HPresponse = homepage();
						goto Mainpage;
					}
				case 2:
					levelCheck = level_2(e);
					if(levelCheck == -1){
					    HPresponse = homepage();
						goto Mainpage;
					}
                case 3:
                    levelCheck = level_3(e);
                    if(levelCheck == -1){
                        HPresponse = homepage();
                        goto Mainpage;
                    }
				default:
					HPresponse = homepage();
					goto Mainpage;
					break;
			}
		}
		else if(HPresponse == 2){
			if(help() == 0){
				HPresponse = homepage();
				goto Mainpage;
			}
		}
		else if(HPresponse == 0){
			return 0;
		}
	wait(3);
	return 0;
} // End main_program
