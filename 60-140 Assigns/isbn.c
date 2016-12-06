//isbn.c
//Nicholas Culmone
//The user enters the first 9 digits of an ISBN-10 number, and the program returns the
//tenth digit using the given method in order to find it.

#include <stdio.h>

int main(){
	int digits, current, total = 0; //variable init

	printf("Enter the first nine digits of ISBN: "); //prompt & user input
	scanf("%d", &digits);

	for(int i=0;i<9;i++){ //goes through every digit in the digits
		current = digits % 10; //gets the current base 10 digit by modding by 10
		total += (i + 2) * current; //adds to the total depending on its position in the digits
		digits /= 10; //divides by 10 so next digit can be found when digits are modded by 10
	}
	total = 11 - (total % 11); //gets the check digit


	if(total != 10) printf("\nCheck digit: %d" + total); //case when check digit is 0-9
	else printf("Check digit: X"); //case when check digit is 10 (X in Base 11)
	
	return 0;
}