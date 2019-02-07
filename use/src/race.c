#include<stdio.h>
#include"arduino.h"
#include"request.h"
#include <unistd.h>
#include "uss.h"

int main(){
	int mode;
	double volt;
	long uss_l, uss_r, uss_f, uss_b;
	int speed1=70;  //直進
	int speed2=140;  //回転
	int kaiten_north=90;
	int kaiten_south=88;
	char buf[256];

	//run_state_t state;

	if(arduino_open() != 0) return -1;
	
	while(1){
		printf("0:stop 1:run_north 2:run_south 3:get_volt 4:uss_north 5:test_STR 6: test_ROT\n");
		fgets(buf,sizeof(buf),stdin);
		sscanf(buf,"%d",&mode);
	
		switch(mode){
			case 0:
				request_set_runmode(STR,0,0);
				break;
		
			case 1:
				request_set_runmode(STR,45,100);
				usleep(25*100*1000);
				request_set_runmode(STR,speed1,160);
				usleep(26*100*1000);				
				//request_set_runmode(STR,speed1,260);
				//usleep(42*100*1000);
				request_set_runmode(ROT,speed2,-95);//-90
				usleep(10*100*1000);//18
          			request_set_runmode(STR,speed1,240);
				usleep(38*100*1000);
				request_set_runmode(ROT,speed2,-47);//-47
                                usleep(7*100*1000);//10
				request_set_runmode(STR,speed1,230);
                                usleep(37*100*1000);
				request_set_runmode(ROT,speed2,-55);//-47
				usleep(8*100*1000);//7
				request_set_runmode(STR,speed1,160);
                                usleep(26*100*1000);
				//usleep(5*100*1000);
				request_set_runmode(STR,speed1,-323);//-313
                                usleep(50*100*1000);
				request_set_runmode(ROT,speed2,-100);//100
                                usleep(11*100*1000);//18
				request_set_runmode(STR,speed1,410);//420
				usleep(67*100*1000);
				request_set_runmode(ROT,speed2,93);//95
                                usleep(11*100*1000);//18
				request_set_runmode(STR,speed1,330);
				break;

			case 2:
				request_set_runmode(STR,45,100);
				usleep(25*100*1000);
				request_set_runmode(STR,speed1,180);
				usleep(29*100*1000);				
				//request_set_runmode(STR,speed1,260);
				//usleep(42*100*1000);
				request_set_runmode(ROT,speed2,100);//94
				usleep(13*100*1000);//18
          			request_set_runmode(STR,speed1,245);
				usleep(40*100*1000);
				request_set_runmode(ROT,speed2,46);
                                usleep(7*100*1000);//10
				request_set_runmode(STR,speed1,240);
                                usleep(39*100*1000);
				request_set_runmode(ROT,speed2,46);
				usleep(7*100*1000);//9
				request_set_runmode(STR,speed1,153);
                                usleep(28*100*1000);
				//usleep(5*100*1000);
				request_set_runmode(STR,speed1,-313);
                                usleep(51*100*1000);
				request_set_runmode(ROT,speed2,93);
                                usleep(13*100*1000);//18
				request_set_runmode(STR,speed1,405);
				usleep(65*100*1000);
				request_set_runmode(ROT,speed2,-90);//-89
                                usleep(11*100*1000);//18
				request_set_runmode(STR,speed1,350);
				break;
			case 3:
				request_get_batt(&volt);
				printf("batt = %4.2lf\n" , volt);
				break;

			case 4:
				while(1){
					request_set_runmode(STR,speed1,1000);
					sleep(2);
					if(uss_f < 100 && 0 < uss_f ){
						request_set_runmode(ROT,speed2,-kaiten_north);
						sleep(2);
					}
/*					request_set_runmode(STR,speed1,395);// 400 395
					sleep(5);
					request_set_runmode(ROT,speed2,-kaiten_north);
                      	          	sleep(2);
					request_set_runmode(STR,speed1,310);
		                  	      sleep(5);

					request_set_runmode(ROT,speed2,180);
					sleep(4);				

					request_set_runmode(STR,speed1,310);
                       		        sleep(5);
					request_set_runmode(ROT,speed2,kaiten_north);
                       		         sleep(2);
					request_set_runmode(STR,speed1,395);// 400 395
                	       	         sleep(6);
					request_set_runmode(ROT,speed2,kaiten_north);
                       		         sleep(2);
					request_set_runmode(STR,speed1,290);//270 290*/
					break;
				}
			case 5:
				request_set_runmode(STR,45,100);
				break;

			case 6:
				request_set_runmode(ROT,speed2,-88);
				break;
		}
	}
}



				
