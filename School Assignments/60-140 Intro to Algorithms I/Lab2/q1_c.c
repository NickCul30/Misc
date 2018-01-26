//q1_c.c
//Nicholas Culmone
//takes a time input in the form hh:mm:ss and seperates the input
//into hour minute and second variables

#include <stdio.h>

int main(){
	int hour, minute, second;
	printf("Enter Time: ");
    scanf("%d:%d:%d", &hour, &minute, &second); //gets user input

    printf("Hour: %d\nMinute: %d\nSecond: %d", hour, minute, second); //prints time

    return 0;
}