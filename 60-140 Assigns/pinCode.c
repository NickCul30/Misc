//pinCode.c
//Nicholas Culmone

#include <stdio.h>

int main(){
	int pin,tmp,digit; //var setting

	for(int i=0;i<6;i++){ //loops 6 times, will exit early if pin is correct
		printf("Enter pin code (attempt %d): ", i+1); //prompt & gets input
		scanf("%d", &pin);
		tmp = pin;

		if(pin >= 10000 && pin < 100000){ //checks if num entered is 5 digits
			for(int j=0;j<5;j++){ //loops through all digits
				digit = tmp % 10; //gets digit by using mod 10
				tmp /= 10;

				if(digit % 3 != 0 || digit == 0){ //case when digit is invalid
					printf("Code %d is invalid!\n", pin);
					break;
				}
				else if(j==4){ //case when pin is valid
					printf("Code %d is a success!", pin);
					return 0;
				}
			}
		}
		else printf("Code %d is invalid\n", pin); //case when pin isn't 5 digits
	}
	printf("Intruder alert!"); //case when 6 incorrect pins were entered

	return 0;
}