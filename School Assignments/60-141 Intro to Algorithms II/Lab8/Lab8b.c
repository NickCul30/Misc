// Lab8b.c
// Nicholas Culmone
// Takes input from employee.dat and capitalizes all of the names

// LIBRARY PACKAGES INCLUDED BELOW
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// STRUCT DEFINITIONS FOLLOW
struct employee {
	char firstname[40];
	char lastname[40];
	int id;
	int GPA;
};
typedef struct employee Employee;

// FUNCTION PROTOTYPE STATEMENTS FOLLOW

void SaveEmpList(const Employee *EmpList, const char *FileName);	//Save the employee records from the list to the newly created text file specified by FileName
void ReadEmpList(Employee *EmpList, const char *FileName);			// Reads the employees from the dat file and stores them in EmpList
void WordCap(Employee *EmpList);									// Capitalizes the first letters of the first and last names of the employees

// MAIN PROGREAM FOLLOWS
int main() {
	Employee EmpList[3];
	ReadEmpList(EmpList, "employee.dat");
	WordCap(EmpList);
	SaveEmpList(EmpList, "employee.dat");
	return 0;
}

// FUNCTION DEFINITIONS FOLLOW

/* 	Reads the text file and saves its contents into EmpList
	Input: Employee *EmpList, const char *FileName
*/
void ReadEmpList(Employee *EmpList, const char *FileName){
	FILE *fPtr = fopen(FileName,"r");
	int i=0;

	while(!feof(fPtr)){
		fscanf(fPtr, "%d %s %s %d", &EmpList[i].id, EmpList[i].firstname, EmpList[i].lastname, &EmpList[i].GPA);
		i++;
	}
}

/* 	Capitalizes the first letter of each first and last name
	Input: Employee *EmpList
*/
void WordCap(Employee *EmpList){
	for(int i=0;i<3;i++){
		*EmpList[i].firstname = toupper(*EmpList[i].firstname);
		*EmpList[i].lastname = toupper(*EmpList[i].lastname);
	}
}

/* 	Saves EmpList to the text file
	Input: const Employee *EmpList, const char *FileName
*/
void SaveEmpList(const Employee *EmpList, const char *FileName){
	FILE *fPtr = fopen(FileName,"w");

	for(int i=0;i<3;i++){
		fprintf(fPtr, "%d %s %s %d\n", EmpList[i].id, EmpList[i].firstname, EmpList[i].lastname, EmpList[i].GPA);
	}
	fclose(fPtr);
}