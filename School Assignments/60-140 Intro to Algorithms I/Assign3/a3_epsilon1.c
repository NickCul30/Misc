//a3_epsilon1.c
//Nicholas Culmone

#include <stdio.h>

int main(){
	float epsilon;

	printf("Enter a small float value for epsilon: "); //prompts user & gets input
	scanf("%f", &epsilon);

	float eps = 0, term = 1, i = 1, fact = 1; //var setting

	//loops until value added to the approx of epsilon is less than what the user entered
	while(term >= epsilon){
		eps += term;
		fact *= i;
		i++;
		term = 1 / fact;
	}

	printf("Approximation of e: %f", eps); //prints approximaton of e

	return 0;
}