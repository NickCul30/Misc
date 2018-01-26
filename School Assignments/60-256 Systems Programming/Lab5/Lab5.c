// Lab5.c
// Nicholas Culmone
// Part I of Lab5, doesn't use nested for-loops to complete the tasks

// INCLUDE SECTION
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

// FUNCTION PROTOTYPES FOLLOW
int sleepTime(char* nums[]);

// MAIN PROGRAM FOLLOWS
int main(int arg_c, char* arg_v[]){
	if(arg_c != 8) exit(1);

	int pid;

	if((pid = fork()) == 0){

		if((pid = fork()) == 0){ // Process #4
			sleep(atoi(arg_v[4]));
			printf("process 4 terminated. pid=%d\n", getpid());
		}
		else{

			if((pid = fork()) == 0){ // Process #5
				sleep(atoi(arg_v[5]));
				printf("process 5 terminated. pid=%d\n", getpid());
			}
			else{ // Process #2
				sleep(atoi(arg_v[2]));
				printf("process 2 terminated. pid=%d\n", getpid());
			}
		}
	}
	else{
		if((pid = fork()) == 0){

			if((pid = fork()) == 0){ // Process #6
				sleep(atoi(arg_v[6]));
				printf("process 6 terminated. pid=%d\n", getpid());
			}
			else{

				if((pid = fork()) == 0){ // Process #7
					sleep(atoi(arg_v[7]));
					printf("process 7 terminated. pid=%d\n", getpid());
				}
				else{ // Process #3
					sleep((atoi(arg_v[3])));
					printf("process 3 terminated. pid=%d\n", getpid());
				}
			}
		}
		else{ // Process #1
			sleep(atoi(arg_v[1]));
			printf("process 1 terminated. pid=%d\n", getpid());
			sleep(sleepTime(arg_v));
		}
	}

	return 0;
}
 
// FUNCTION DEFINITIONS FOLLOW

int sleepTime(char* nums[]){
	int max = 0;
	for(int i=1;i<8;i++){
		if(atoi(nums[i]) > max){
			max = atoi(nums[i]);
		}
	}

	return max - atoi(nums[1]) + 1;
}