//frac.c
//Nicholas Culmone
//adds, subtracts, multiplies, or divides two fractions that the user enters

#include <stdio.h>

int main(){
	int num1, den1, num2, den2, num, den; //variable setting
	char op;

	printf("Enter operation: "); //prompts user & gets input
	scanf("%d/%d%c%d/%d", &num1, &den1, &op, &num2, &den2);

	if(op == '+'){ //case when adding fractions
		den = den1 * den2;
		num = (num1 * den2) + (num2 * den1);
	}
	else if(op == '-'){ //case when subtracting fractions
		den = den1 * den2;
		num = (num1 * den2) - (num2 * den1);
	}
	else if(op == '*'){ //case when multipling fractions
		den = den1 * den2;
		num = num1 * num2;
	}
	else if(op == '/'){ //case when dividing fractions
		den = den1 * num2;
		num = den2 * num1;
	}
	else{ //invalid operator case
		printf("Invalid Operator");
		return 0;
	}

	if(den == 0){ //dividing by 0 case
		printf("Error: div by 0");
		return 0;
	}

	printf("Final answer: %d/%d", num, den); //prints final ans when no errors in input
	return 0;
}