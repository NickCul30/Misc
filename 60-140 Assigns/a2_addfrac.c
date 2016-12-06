//a2_addfrac.c
//Nicholas Culmone
//The user inputs two fractions to be added, prints the added fraction

#include <stdio.h>

int main(){
	int n1, d1, n2, d2; //numerator 1,2 & denominator 1,2

	//prompts user & gets input
	printf("Enter two fractions seperated by a plus sign: ");
	scanf("%d/%d+%d/%d", &n1, &d1, &n2, &d2); //seperates the numbers accordingly

	int commonDen = d1 * d2; //finds common denominator
	int numerator = (n1 * d2) + (n2 * d1); //finds numerator

	printf("The sum is %d/%d", numerator, commonDen); //prints answer (not simplified)

	return 0;
}