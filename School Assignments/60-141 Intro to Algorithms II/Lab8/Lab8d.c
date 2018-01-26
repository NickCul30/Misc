// Lab8d.c
// Nicholas Culmone

// LIBRARY PACKAGES INCLUDED BELOW
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// STRUCT DEFINITIONS FOLLOW
struct employee {
	char firstname[40];
	char lastname[40];
	int id;
	float GPA;
};
typedef struct employee Employee;

// FUNCTION PROTOTYPE STATEMENTS FOLLOW

int PrintCount(const char *FileName);				// Prints the contents of the File and counts the lines
void SortEmp(const char *FileName, int lines);		// Sorts the file based on GPA

// MAIN PROGREAM FOLLOWS
int main(){
	int i = PrintCount("EmployeeDA.dat");
	SortEmp("EmployeeDA.dat", i);
	printf("\n");
	PrintCount("EmployeeDA.dat");
	return 0;
}

// FUNCTION DEFINITIONS FOLLOW

/* 	Prints the contents of the file, and returns the amount of lines the file has in it
	Input: const char *FileName
	Output: int number of lines the file has
*/
int PrintCount(const char *FileName){
	int i=0;
	FILE *fPtr = fopen(FileName, "rb");
	char str[sizeof(Employee)] = {'\0'};

	while(fread(str, sizeof(Employee), 1, fPtr) == 1){
		printf("%s", str);
		i++;
	}
	fclose(fPtr);
	return i;
}

/* 	Sorts the text file in descending order by GPA
	Input: const char *FileName, int lines
*/
void SortEmp(const char *FileName, int lines){
	bool sorting = true;

	while(sorting){
		sorting = false;
		FILE *fPtr = fopen(FileName, "rb+");

		for(int i=0;i<3;i++){
			char s1[sizeof(Employee)] = {'\0'}, s2[sizeof(Employee)] = {'\0'};
			Employee e1, e2;
			fread(s1, sizeof(Employee), 1, fPtr);
			fread(s2, sizeof(Employee), 1, fPtr);
			sscanf(s1,"%d %s %s %f", &e1.id, e1.firstname, e1.lastname, &e1.GPA);
			sscanf(s2,"%d %s %s %f", &e2.id, e2.firstname, e2.lastname, &e2.GPA);
			if(e1.GPA < e2.GPA){
				sorting = true;
				fseek(fPtr, -2 * sizeof(Employee), SEEK_CUR);
				fwrite(s2, sizeof(Employee), 1, fPtr);
				fwrite(s1, sizeof(Employee), 1, fPtr);
			}


			fseek(fPtr, -sizeof(Employee), SEEK_CUR);
		}
		fclose(fPtr);
	}
}