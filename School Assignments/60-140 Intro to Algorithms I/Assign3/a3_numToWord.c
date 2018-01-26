//a3_numToWord.c
//Nicholas Culmone

#include <stdio.h>

int main(){
	int n,first,second;
	printf("Enter a two-digit number: "); //prompts user & gets input
	scanf("%d", &n);

	if(n > 99 || n < 10){ //checks if number entered is not 2 digits
		printf("Invalid number");
		return 0;
	}

	//splits digits from n, first digit is stored in 'first', second in 'second'
	second = n % 10;
	first = (n - second) / 10;

	printf("You entered the number ");

	switch(first){ //switch for first digit
		case 2: printf("twenty"); break;
		case 3: printf("thrity"); break;
		case 4: printf("fourty"); break;
		case 5: printf("fifty"); break;
		case 6: printf("sixty"); break;
		case 7: printf("seventy"); break;
		case 8: printf("eighty"); break;
		case 9: printf("ninety"); break;

		case 1: //special case for 10 <= n <= 19
			switch(second){
				case 0: printf("ten"); break;
				case 1: printf("eleven"); break;
				case 2: printf("twelve"); break;
				case 3: printf("thirteen"); break;
				case 4: printf("fourteen"); break;
				case 5: printf("fifteen"); break;
				case 6: printf("sixteen"); break;
				case 7: printf("seventeen"); break;
				case 8: printf("eighteen"); break;
				case 9: printf("nineteen"); break;
			}
			return 0;
	}

	switch(second){ //switch for second digit
		case 1: printf("-one"); break;
		case 2: printf("-two"); break;
		case 3: printf("-three"); break;
		case 4: printf("-four"); break;
		case 5: printf("-five"); break;
		case 6: printf("-six"); break;
		case 7: printf("-seven"); break;
		case 8: printf("-eight"); break;
		case 9: printf("-nine"); break;
	}

	return 0;
}