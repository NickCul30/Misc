//repDigit.c
//Nicholas Culmone

#include <stdio.h>
#include <stdbool.h>

int main(){
	int digit; //var init
	long n;

	while(1){
		//init arrays, makes all values in them false
		bool digitSeen[10] = {false}; //array for if the digit has been seen in the num
		bool digitRep[10] = {false}; //array for if the digit has been repeated in the num
		bool areRepeats = false;

		printf("\nEnter a number: "); //prompt user & gets input
		scanf("%ld", &n);

		if(n <= 0 ) return 0; //checks case when n <= 0, ends program if so

		while(n > 0){ //goes through every digit in n
			digit = n % 10; //splits the digit
			n /= 10;

			if(digitSeen[digit]){
				digitRep[digit] = true; //when a digit is repeated
				areRepeats = true;
			}
			digitSeen[digit] = true; //when a digit is seen for the first time
		}

		if(areRepeats){
			printf("Digits Repeated: "); //prints out the repeated digits when there are any
			for(int i=0;i<10;i++){
				if(digitRep[i]) printf("%d ", i);
			}
		}
		else printf("No digits are repeated"); //case when there are no repeated digits
	}

	return 0;
}