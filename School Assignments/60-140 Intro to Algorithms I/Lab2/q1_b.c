//q1_b.c
//Nicholas Culmone
//prints 1.234 in a 9 digit field with following zeroes

#include <stdio.h>

int main(){
	float b = 1.234;
	int c = 0; //sets c to 0 so multiple 0's can be printed
	printf("%.5d%-3.3f",c,b); //prints

	return 0;
}