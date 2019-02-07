#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "arduino.h"

extern void thread_run_base(void *t);
extern void thread_measure(void *t);
extern void thread_touch(void *t);

int main(void){

	if(arduino_open() != 0) return -1;

	int s;
	pthread_t tid_run, tid_uss;

	s = pthread_create(&tid_run, NULL, thread_run_base, NULL);
	if(s != 0){
		printf("create error!\n");
		return -1;
	}
	
	s = pthread_create(&tid_uss, NULL, thread_measure, NULL);
	if(s != 0){
		printf("create error!\n");
		return -1;
	}
	
	pthread_join(tid_run, NULL);
	pthread_join(tid_uss, NULL);

	return 0;
}