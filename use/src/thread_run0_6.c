#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>
#include "request.h"
#include "theta.h"
#include "run0_6.h"
#include "uss.h"
#include "arduino.h"

void thread_run0_6(void *t){

	int length = 240;
	int side = 0;
	int rotvel = 20;
	int vel = 20;

	int time;
	int kakudo = 180;
	time = round(10*kakudo / rotvel);

	double kyori = sqrt(length*length + side*side);
	int idou = round(kyori); 
//	int mae = theta(length, side);
//	int time2 = round(10*mae / rotvel);

	printf("1\n");
	sleep(2);

//	request_set_runmode(ROT,rotvel,kakudo);
//	usleep(time * 100 * 1000);

	printf("2\n");
//	sleep(1);

	run_state_t run_state;
	int speed,dist;
	int total = 0;
	int sabun = 0;

	request_set_runmode(STR,vel,idou);
	usleep(1000);
	while(1){
		request_get_runmode(&run_state,&speed,&dist);
		sabun = dist;
		if(stop == 1){
			request_get_runmode(&run_state,&speed,&dist);
			request_set_runmode(STP,0,0);
			total += dist;  
			sleep(3);
			request_set_runmode(STR,vel,idou - total);
		}
		request_get_runmode(&run_state,&speed,&dist);
		if(run_state == STP){
			printf("tomattayo-\n");
			break;
		}
//		printf("total=%d\n",sabun);
	}

//	printf("3\n");	

//	request_set_runmode(ROT,rotvel,-mae);
//	usleep(time2 * 100 * 1000);

	printf("finish\n");

	return 0;
}
