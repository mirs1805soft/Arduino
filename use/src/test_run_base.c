#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "request.h"
#include "uss.h"
#include "stay.h"
#include "run_base.h"
#include "arduino.h"

#define go 60
#define vel 20

//extern int stop;

void thread_run_base(void *t){

	if(arduino_open() != 0) return -1;

	sleep(2);

	request_set_runmode(STR,10,150);

	while(1){
	printf("%d\n",stop);
	if(stop == 1){
		printf("tomare\n");
//		stay();
	}
	usleep(500*1000);
	}

//	return 0;
}
