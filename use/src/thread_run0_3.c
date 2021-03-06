#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>
#include "request.h"
#include "run_base.h"
#include "theta.h"
#include "run0_3.h"
#include "uss.h"
#include "arduino.h"

void thread_run0_3(void *t){

	int length = 87; 
	int side = 213;
	int rotvel = 20;
	int vel = 20;

	int time;
	int kakudo = 20 + theta(length, side);
	time = round(10*kakudo / rotvel);

	double kyori = sqrt(length*length + side*side);
	int idou = round(kyori); 
	int mae = 15 + theta(length, side);
	int time2 = round(10*mae / rotvel);

	printf("1\n");
	sleep(2);

	request_set_runmode(ROT,rotvel,-kakudo);
	usleep(time * 100 * 1000);

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

	request_set_runmode(ROT,rotvel,mae);
	usleep(time2 * 100 * 1000);
	sleep(1);

	printf("3\n");

	request_set_neck(255);
	sleep(20);
	request_set_neck(0);

	printf("up/n");
	sleep(10);

	request_set_neck(-255);
	sleep(20);
	request_set_neck(0);

	printf("down/n");

//	int time;
	kakudo = -10 + 180 - theta(length, side);
	time = round(10*kakudo / rotvel);
	
	kyori = sqrt(length*length + side*side)-60;//60
	idou = 20 + round(kyori);
	mae = 180 - theta(length, side);
	time2 = round(10*mae / rotvel);

	printf("1\n");

	sleep(2);

	request_set_runmode(ROT,rotvel,kakudo);
	usleep(time * 100 * 1000);
	      
	printf("2\n");
	sleep(1);
		
	run_state_t run2_state;
	int speed2,dist2;
	total = 0;
	sabun = 0;
		   
	request_set_runmode(STR,vel,idou);
	usleep(1000);
	while(1){
		request_get_runmode(&run2_state,&speed2,&dist2);
		sabun = dist2;
		if(stop == 1){
			request_get_runmode(&run2_state,&speed2,&dist2);
			request_set_runmode(STP,0,0);
			total += dist2;
			sleep(3);
			request_set_runmode(STR,vel,idou - total);
		}
		request_get_runmode(&run2_state,&speed2,&dist2);
		if(run2_state == STP){
			printf("tomattayo-\n");
			break;
		}
//		printf("total=%d\n",sabun);
	}
		
	printf("3\n");

	request_set_runmode(ROT,rotvel,-mae);

	return 0;
}
