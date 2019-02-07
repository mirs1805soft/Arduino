#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>
#include "request.h"
#include "out.h"
#include "uss.h"
#include "arduino.h"

void thread_out(void *t){

	int side = 400;
	int down = 230;
	int rotvel = 20; 
	int rotr = -90;
	int rotrtime = 45;
	int vel = 20;

	if(arduino_open() != 0) return -1;	

//down

	run_state_t run_state1;
	int speed1,dist1;
	int total1 = 0;
	int sabun1 = 0;

	request_set_runmode(STR,vel,down);
	usleep(1000);
	while(1){
		request_get_runmode(&run_state1,&speed1,&dist1);
		sabun1 = dist1;
		if(stop == 1){
			request_get_runmode(&run_state1,&speed1,&dist1);
			request_set_runmode(STP,0,0);
			total1 += dist1;  
			sleep(3);
			request_set_runmode(STR,vel,down - total1);
		}
		request_get_runmode(&run_state1,&speed1,&dist1);
		if(run_state1 == STP){
			printf("tomattayo-\n");
			break;
		}
//		printf("total1=%d\n",sabun1);
	}

	printf("1\n");

	request_set_runmode(ROT,rotvel,rotr);
	usleep(rotrtime * 100 * 1000);

	printf("2\n");

//side

	run_state_t run_state2;
	int speed2,dist2;
	int total2 = 0;
	int sabun2 = 0;

	request_set_runmode(STR,vel,side);
	usleep(1000);
	while(1){
		request_get_runmode(&run_state2,&speed2,&dist2);
		sabun2 = dist2;
		if(stop == 1){
			request_get_runmode(&run_state2,&speed2,&dist2);
			request_set_runmode(STP,0,0);
			total2 += dist2;  
			sleep(3);
			request_set_runmode(STR,vel,side - total2);
		}
		request_get_runmode(&run_state2,&speed2,&dist2);
		if(run_state2 == STP){
			printf("tomattayo-\n");
			break;
		}
//		printf("total2=%d\n",sabun2);
	}

	printf("finish\n");

	return 0;
}