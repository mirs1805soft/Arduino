#include <stdio.h>
#include <unistd.h>
#include "request.h"
#include "uss.h"
#include "stay.h"
#include "run_base.h"


void run_base(){

	int vel = 20;
	int go = 10;	
	int a = 510;	

	request_set_runmode(STR,vel,go);
		usleep(a*1000);
		if(stop == 1){
			stay();
		}
	request_set_runmode(STR,vel,go);
		usleep(a*1000);
		if(stop == 1){
			stay();
		}
	request_set_runmode(STR,vel,go);
		usleep(a*1000);
		if(stop == 1){
			stay();
		}
	request_set_runmode(STR,vel,go);
		usleep(a*1000);
		if(stop == 1){
			stay();
		}
	request_set_runmode(STR,vel,go);
		usleep(a*1000);
		if(stop == 1){
			stay();
		}
	request_set_runmode(STR,vel,go);
		usleep(a*1000);
		if(stop == 1){
			stay();
		}
	request_set_runmode(STR,vel,go);
		usleep(a*1000);
		if(stop == 1){
			stay();
		}
	request_set_runmode(STR,vel,go);
		usleep(a*1000);
		if(stop == 1){
			stay();
		}
	request_set_runmode(STR,vel,go);
		usleep(a*1000);
		if(stop == 1){
			stay();
		}
	request_set_runmode(STR,vel,go);
		usleep(a*1000);
		if(stop == 1){
			stay();
		}
}
