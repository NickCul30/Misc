//exprEval.c
//Nicholas Culmone

#include <stdio.h>

int main(){
	char op; //operator
	double num1, num2; //user entered nums

	//prompts user & gets input
	printf("Enter a simple expression: ");
	scanf("%lf %s %lf", &num1, &op, &num2);

	if(op == '+'){ //addition (no edge cases)
		printf("Output: %.2lf + %.2lf = %.2lf", num1, num2, num1 + num2);
	}
	else if(op == '-'){ //subtraction (no edge cases)
		printf("Output: %.2lf - %.2lf = %.2lf", num1, num2, num1 - num2);
	}
	else if(op == '*'){ //mult (no edge cases)
		printf("Output: %.2lf * %.2lf = %.2lf", num1, num2, num1 * num2);
	}
	else if(op == '/'){ //division
		if(num2 == 0){ //edge case: div by 0
			printf("Output: Division by zero");
		}
		else{
			printf("Output: %.2lf / %.2lf = %.2lf", num1, num2, num1 / num2);
		}
	}
	else{ //invalid operator
		printf("Output: Not valid operator");
	}
}