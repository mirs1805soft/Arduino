#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "arduino.h"
#include "request.h"

int kbhit(void)
{
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

int main(){
	int speed_str, speed_rot, dist;
	char buf[256];
	int key, yj;

	speed_str = 25;
	speed_rot = 30;
	dist = 500;
	
	if(arduino_open() != 0) return -1;
	system("clear");

	while(1){
		//system("clear");
		if(kbhit()){
			system("clear");
			key = getchar();
			switch(key){
				case 'w':
					printf("\rforward\n");
					request_set_runmode(STR, speed_str, dist);
					break;
				case 's':
					printf("\rback\n");
					request_set_runmode(STR, speed_str, -dist);
					break;
				case 'a':
					printf("\rleft\n");
					request_set_runmode(ROT, speed_rot, dist);
					break;
				case 'd':
					printf("\rright\n");
					request_set_runmode(ROT, speed_rot, -dist);
					break;
				case 'c':
					request_set_runmode(STP, 0, 0);
					printf("change speed\n");					
					printf("speed(STR)is : Currently = %d\n", speed_str);
					fgets(buf, sizeof(buf), stdin);
					sscanf(buf, "%d", &speed_str);
					fflush(stdin);
					printf("speed(ROT)is : Currently = %d\n", speed_rot);
					fgets(buf, sizeof(buf), stdin);
					sscanf(buf, "%d", &speed_rot);
					
					fflush(stdin);
					system("clear");
					break;
				case 'q':
					printf("end\n");
					arduino_close();
					return 0;
				case ' ':
					system("clear");
					request_set_runmode(STP, 0, 0);
					break;
				default:
					system("clear");
					request_set_runmode(STP, 0, 0);
					break;
			}
		}
		//usleep(1000);
	}
	
	arduino_close();
	return 0;
}
