//Lab7a.c
//Nicholas Culmone
//Write my own versions of some of the C library functions

// LIBRARY PACKAGES INCLUDED BELOW
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// FUNCTION PROTOTYPE STATEMENTS FOLLOW
int AtoI(const char *str);
int StrCmp(const char *str1, const char *str2);
char *StrCpy(char *destination, const char *source);
char *StrCat(char *destination, const char *source);
char *StrChr(char *str, int character);

// MAIN PROGREAM FOLLOWS
int main(){
	char t1[40] =     "test one ";
	const char t2[] = "test number two";
	char t3[] =       "also a test";

	printf("%s\n", StrCat(t1,t2));
	char *tmp = StrChr(t3,'s');
	printf("%s\n", tmp);
	printf("%s\n", StrCpy(t1,t3));
	printf("%d\n", StrCmp(t1,t3));
	printf("%d\n", AtoI("		 -14014"));

	return 0;
}

// FUNCTION DEFINITIONS FOLLOW

/*	Converts a string to an integer, by first ignoring any whitespace, then converting
	all of the following numerical digits, will also accept a negative or positive sign
	at the beginning of the string.
	Input: const char *str
	Output: int ans , the converted integer
*/
int AtoI(const char *str){
	int ans = 0, i, j;
	for(i=0;isspace(*(str+i));i++);

	if((*(str+i) < 48 || *(str+i) > 57) && *(str+i) != '+' && *(str+i) != '-') return 0;
	for(j=1;isdigit(*(str+i+j));j++);
	j--;

	int p = 0;
	for(;j>0;j--){
		if(*(str+i+j) == '-' || *(str+i+j) == '+') break;
		ans += pow(10,p) * (*(str+i+j) - '0');
		p++;
	}
	if(*(str+i) == '-') ans *= -1;
	else if(*(str+i) != '+') ans += pow(10,p) * (*(str+i) - '0');

	return ans;
}

/* 	Compares the values of two char arrays, iterates through every character
	until there is an inconsistency between them, if str2's char is greater
	than str1's, -1 will be returned.  If str1's char is greater
	than str2's, 1 will be returned. If the strings are the same 0 will be returned.
	Input: const char *str1, const char *str2
*/
int StrCmp(const char *str1, const char *str2){
	for(int i=0; *(str1+i) != '\0' || *(str2+i) != '\0';i++){
		if(*(str1+i) - *(str2+i) > 0) return 1;
		else if(*(str1+i) - *(str2+i) < 0) return -1;
	}
	return 0;
}

/* 	Copies the string to source to the start of destination, adds a
	'\0' character to the end of the string
	Input: char *destination, const char *source
	Output: char *destination
*/
char *StrCpy(char *destination, const char *source){
	for(int i=0; *(source+i) != '\0'; i++){
		*(destination + i) = *(source + i);
		*(destination + i + 1) = '\0';
	}

	return destination;
}

/* 	Appends source to the end of destination, then adds a '\0' to the end
	Input: char *destination, const char *source
	Output: char *destination
*/
char *StrCat(char *destination, const char *source){
	char *T = destination;
	for(;*T != '\0'; T++);

	for(int i=0;*(source+i) != '\0';i++){
		*T = *(source+i);
		T++;
	}
	*T = '\0';
	return destination;
}

/* 	Finds the first instance of character in str, and returns the pointer
	to that character
	Input: char *str, int character
	Output: a char pointer to the first instance of that char
*/
char *StrChr(char *str, int character){
	for(int i=0; *(str+i) != '\0'; i++){
		if(*(str+i) == character) return (str+i);
	}
	return NULL;
}