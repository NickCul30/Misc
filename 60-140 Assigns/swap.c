//swap.c
//Nicholas Culmone

#include<stdio.h>

int main(){
	int a;
	int b;

    printf("Enter first number: ");
    scanf("%d", &a); //gets user input
    printf("Enter second number: ");
    scanf("%d", &b); //gets user input
    printf("\nBefore swapping the first number was %d and the second number was %d", a, b);
    int c = a; //swaps vars a & b by creating a tmp variable c
    a = b;
    b = c;
    printf("\nAfter swapping the first number was %d and the second number was %d", a, b);
	
	return 0;
}