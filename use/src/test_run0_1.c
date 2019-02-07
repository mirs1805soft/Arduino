#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>
#include "arduino.h"
#include "request.h"
#include "run_base.h"
#include "theta.h"
#include "run0_1.h"

int main(void *t){

	int go = 5;
	int length = 91;
	int side = 127;
	int rotvel = 20;

	if(arduino_open() != 0) return -1;

	printf("1\n");

	int loop = 1;
	int time;
	int kakudo = theta(length, side) + 90;
	time = round(10*kakudo / rotvel);

	printf("kakudo=%d\n",kakudo);
	printf("time=%d\n",time);

	double kyori = sqrt(length*length + side*side);
	int idou = round(kyori); 
	int mae = theta(length, side);
	int time2 = round(10*mae / rotvel);

	printf("kyori=%f\n",kyori);
	printf("mae=%d\n",mae);
	printf("time2=%d\n",time2);

	sleep(2);

	request_set_runmode(ROT,rotvel,kakudo);
	usleep(time * 100 * 1000);
	
	printf("2\n");

	while(loop == idou/go){
		run_base();
		loop ++;
	}
	printf("3\n");

	request_set_runmode(ROT,rotvel,-mae);
	usleep(time2 * 100 * 1000);

	printf("4\n");

	return 0;
}
