#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>
#include "request.h"
#include "in.h"
#include "uss.h"
#include "arduino.h"

void thread_in(void *t){

	int side = 340;
	int down = 147;
	int rotvel = 20; 
	int rotl = 90;
	int rotltime = 45;
	int vel = 20;

	if(arduino_open() != 0) return -1;	

//side

	run_state_t run_state1;
	int speed1,dist1;
	int total1 = 0;
	int sabun1 = 0;

	request_set_runmode(STR,vel,side);
	usleep(1000);
	while(1){
		request_get_runmode(&run_state1,&speed1,&dist1);
		sabun1 = dist1;
		if(stop == 1){
			request_get_runmode(&run_state1,&speed1,&dist1);
			request_set_runmode(STP,0,0);
			total1 += dist1;  
			sleep(3);
			request_set_runmode(STR,vel,side - total1);
		}
		request_get_runmode(&run_state1,&speed1,&dist1);
		if(run_state1 == STP){
			printf("tomattayo-\n");
			break;
		}
//		printf("total1=%d\n",sabun1);
	}

	printf("1\n");

	request_set_runmode(ROT,rotvel,rotl);
	usleep(rotltime * 100 * 1000);

	printf("2\n");

//down

	run_state_t run_state2;
	int speed2,dist2;
	int total2 = 0;
	int sabun2 = 0;

	request_set_runmode(STR,vel,down);
	usleep(1000);
	while(1){
		request_get_runmode(&run_state2,&speed2,&dist2);
		sabun2 = dist2;
		if(stop == 1){
			request_get_runmode(&run_state2,&speed2,&dist2);
			request_set_runmode(STP,0,0);
			total2 += dist2;  
			sleep(3);
			request_set_runmode(STR,vel,down - total2);
		}
		request_get_runmode(&run_state2,&speed2,&dist2);
		if(run_state2 == STP){
			printf("tomattayo-\n");
			break;
		}
//		printf("total2=%d\n",sabun2);
	}

	printf("3\n");

	request_set_runmode(ROT,rotvel,2 * rotl);
	usleep(2 * rotltime * 100 * 1000);

	printf("finish\n");

	return 0;
}
