//Lab6.c
//Nicholas Culmone
//Manipulates and prints char arrays using the functions Reverse and ParseSentence

// LIBRARY PACKAGES INCLUDED BELOW
#include <stdio.h>

// FUNCTION PROTOTYPE STATEMENTS FOLLOW
void Reverse(char *str);				// Reverses the non-null contents of a char array
void Swap(char *ptr1, char *ptr2);		// Swaps the values pointed to by two given pointers ptr1, ptr2
void ParseSentence(char *str);			// Prints a char array, while ignoring ',' '.' ';' and starting a new line every space

// MAIN PROGREAM FOLLOWS
int main(){
	// Variable init - Part A
	char buffer1[] = {'t','h','i','s',' ','i','s',' ','t','h','e',' ','f','i','r','s','t',' ','b','u','f','f','e','r','\0'};
	char buffer2[] = "this is the second buffer";
	char buffer3[80];

	// Used as an error fix, since the line "scanf("%s", buffer3);" ends its scanning after a space is added
	scanf("%[^\n]s", buffer3);

	// Prints all three buffers using %s conversion
	printf("\n%s\n%s\n%s\n\n", buffer1, buffer2, buffer3);

	// Iterates over buffer3 until the null character is found and stops printing
	char *pBuffer = buffer3;
	char *cur = pBuffer;

	while(*cur != '\0'){
		printf("%c", *cur);
		cur ++;
	}

	printf("\n");
	// Advances pBuffer by 2 spots, then prints the rest of buffer3
	cur = pBuffer + 2;

	while(*cur != '\0'){
		printf("%c", *cur);
		cur ++;
	}

	Reverse(buffer3);
	printf("\n%s\n", buffer3);

	ParseSentence(buffer3);
	return 0;
}

// FUNCTION DEFINITIONS FOLLOW

/* 	Reverses the non-null elements of the char array, leaving the null ones intact
	Input: char *str
*/
void Reverse(char *str){
	char *start = str, *end = str;

	// Iterates through str until the last non-null character
	// is found; char *end is set to that pointer
	while(*end != '\0'){
		end ++;
	}
	end --;

	// Iterates through str swapping opposite chars, goes until end & start meet in the middle
	while(end > start){
		Swap(end,start);
		end --;
		start ++;
	}
}

/* 	Swaps the values pointed to by two pointers
	Input: char *ptr1, char *ptr2
*/
void Swap(char *ptr1, char *ptr2){
	char tmp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = tmp;
}

/* 	Prints a char array, while ignoring the delimiters ',' '.' ';'
	begins a new line every space, stops when the null char is reached
	Input: char *str
*/
void ParseSentence(char *str){
	while(*str != '\0'){
		if(*str == ' ') printf("\n");
		else if(*str != ',' && *str != '.' && *str != ';') printf("%c", *str);
		str ++;
	}
}