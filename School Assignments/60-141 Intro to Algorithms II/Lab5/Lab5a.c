
// LIBRARY PACKAGES INCLUDED BELOW
#include <stdio.h>

// MAIN PROGREAM FOLLOWS
int main(){

	//Variable init
	int a = 7;
	int *aPtr;

	//sets aPtr to the address of a
	aPtr = &a;

	//Prints the address of a
	printf("%p\n", &a);

	//Prints aPtr
	printf("%p\n", aPtr);

	//Prints the address of aPtr
	printf("%p\n", &aPtr);

	//Prints a
	printf("%d\n", a);

	//Gets the value pointed to by aPtr, printing a
	printf("%d\n", *aPtr);

	//Gets the address of the pointer, then gets the value of that, printing the pointer aPtr
	printf("%p\n", *&aPtr);

	//Gets the address of the value pointed to by aPtr
	printf("%p\n", &*aPtr);

	//Gets the value at the address of a, printing a
	printf("%d\n", *&a);

	//Tries to get the value pointed to by 'a' first, causing an error
	//printf("%d", &*a);

	return 0;
}