#include <stdio.h>
#include <unistd.h>
#include "request.h"
#include "arduino.h"

int main(){
	if(arduino_open() != 0) return -1;

	int neck_speed = 0;
	int neck_time = 0;

	printf("首の速度を指定\n");
	scanf("%d", &neck_speed);
	printf("\nモーターの駆動時間を指定\n");
	scanf("%d", &neck_time);
	printf("\n");

	request_set_neck(neck_speed);
	sleep(neck_time);
	request_set_neck(0);

	return -1;
}

