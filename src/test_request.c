#include <stdio.h>
#include "arduino.h"
#include "request.h"

int main(){
	int mode, speed, dist;
	double volt;
	char buf[256];
	run_state_t state;
	
	if(arduino_open() != 0) return -1;
	
	while(1){
		printf("0:stop 1:straight 2:rotate 3:get_mode 4:get_volt\n");
		fgets(buf, sizeof(buf), stdin);
		sscanf(buf, "%d", &mode);
		
		switch(mode){
		case 0:
			request_set_runmode(STP, 0, 0);
			break;
		case 1:
			printf("speed? [cm/s]\n");
			fgets(buf, sizeof(buf), stdin);
			sscanf(buf, "%d", &speed);
			
			printf("dist? [cm]\n");
			fgets(buf, sizeof(buf), stdin);
			sscanf(buf, "%d", &dist);
			
			request_set_runmode(STR, speed, dist);
			break;
		case 2:
			printf("speed? [deg/s]\n");
			fgets(buf, sizeof(buf), stdin);
			sscanf(buf, "%d", &speed);
			
			printf("angle? [deg]\n");
			fgets(buf, sizeof(buf), stdin);
			sscanf(buf, "%d", &dist);
			
			request_set_runmode(ROT, speed, dist);
			break;
		case 3:
			request_get_runmode(&state, &speed, &dist);
			printf("state = %s\n",((state == STR) ? "STR" : (state == ROT) ? "ROT" : "STP"));
			break;
		case 4:
			request_get_batt(&volt);
			printf("batt = %4.2lf\n", volt);
			break;
		}
	}
	
	arduino_close();
	return 0;
}
