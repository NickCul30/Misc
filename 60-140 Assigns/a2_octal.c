//a2_octal.c
//Nicholas Culmone
//A program that takes in a user's base 10 input and outputs the corresponding
//base 8 number

#include <stdio.h>
#include <math.h>

int main(){
	int num, rem, octal = 0, count = 0; //variable setting

	//prompts user and gets input
	printf("Enter a base 10 number between 0 and 32767: ");
	scanf("%d", &num);

	//goes until the all the digits have been accounted for
	while(num > 0){
		rem = num % 8; //gets the base 8 digit
		num /= 8; //divides num by 8
		octal += pow(10,count) * rem; //puts the digit at the front of the final base 8 number
		count ++;
	}

	printf("In octal your number is: %d", octal); //prints base 8 number

	return 0;
}