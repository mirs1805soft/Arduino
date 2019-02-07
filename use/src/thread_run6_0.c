#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>
#include "request.h"
#include "run_base.h"
#include "theta.h"
#include "run6_0.h"
#include "uss.h"
#include "arduino.h"

void thread_run6_0(void *t){

	int length = 235;
	int side = 0;
	int rotvel = 20;
	int vel = 20;

	int time;
	int kakudo = 180 + 35;
	time = round(10*kakudo / rotvel);

	double kyori = sqrt(length*length + side*side);
	int idou = round(kyori); 
	int mae = theta(length, side);
	int time2 = round(10*mae / rotvel);

	printf("1\n");
	sleep(2);

	request_set_runmode(ROT,rotvel,kakudo);
	usleep(time * 100 * 1000);

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

	printf("2\n");

	request_set_runmode(ROT,rotvel,kakudo -35);
	usleep(time * 100 * 1000);

	printf("finish\n");

	return 0;
}
