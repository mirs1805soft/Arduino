#include <stdio.h>
#include <unistd.h>
#include "request.h"
#include "arduino.h"

int main(){
	if(arduino_open() != 0) return -1;

	sleep(3);

	request_set_neck(-80);
	printf("10");
	sleep(10);
	request_set_neck(0);
	return -1;
}

