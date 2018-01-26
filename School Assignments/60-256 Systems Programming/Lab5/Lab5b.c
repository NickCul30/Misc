// Lab5b.c
// Nicholas Culmone
// Part 2 of Lab 5, uses two nested for loops to fork and assign processNums to each process

// INCLUDE SECTION
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdbool.h>

// FUNCTION PROTOTYPES FOLLOW
int sleepTime(char* nums[]);

// MAIN PROGRAM FOLLOWS
int main(int arg_c, char* arg_v[]){
	if(arg_c != 8) exit(1);

	int pid, processNum = 1;

	for(int i=0;i<2;i++){

		if(processNum == 1 && (pid = fork()) == 0){
			processNum += i + 1;

			for(int j=0;j<2;j++){

				if((processNum == 2 || processNum == 3) && (pid = fork()) == 0){
					processNum = processNum	* 2 + j;
				}
			}
		}
	}

	sleep(atoi(arg_v[processNum]));
	printf("process %d terminated. pid=%d\n", processNum, getpid());

	if(processNum == 1) sleep(sleepTime(arg_v));

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