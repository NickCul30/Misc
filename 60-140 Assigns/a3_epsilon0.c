//a3_epsilon0.c
//Nicholas Culmone

#include <stdio.h>
#include <math.h>

int main(){
	int n, den = 1, oldDen; //how many times it loops
	double e = 0, toAdd; //approx of epsilon

	//prompts user and gets input
	printf("Enter num: ");
	scanf("%d", &n);

	for(int i=1;i<n+1;i++){ //loops how many times user says
		oldDen = den;
		den = 1; //denominator for fraction to be added to e
		den = oldDen * i;

		toAdd = ((double)i)/den; //divides i by factorial of i

		if(isinf(toAdd)){ //edge case happens when i is large; dividing i/i! gives inf
			break;
		}
		else{
			e += toAdd;
		}
	}

	printf("%f", e); //prints approx of epsilon

	return 0;
}