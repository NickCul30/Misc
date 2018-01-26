// Lab8c.c
// Nicholas Culmone
// Get input from kb and put it into a file using direct access

// LIBRARY PACKAGES INCLUDED BELOW
#include <stdio.h>
#include <string.h>

// STRUCT DEFINITIONS FOLLOW
struct employee {
	char firstname[40];
	char lastname[40];
	int id;
	float GPA;
};
typedef struct employee Employee;

// FUNCTION PROTOTYPE STATEMENTS FOLLOW

void InputEmpRecord(Employee *EmpList);									// Input the employee data interactively from the keyboard
void PrintEmpList(const Employee *EmpList);								// Display the contents of Employee records from the list
void SaveEmpList(const Employee *EmpList, const char *FileName);		// Save the employee records from the list to the newly created binaryfile specified by FileName

// MAIN PROGREAM FOLLOWS
int main() {
	Employee EmpList[4];
	InputEmpRecord(EmpList);
	PrintEmpList(EmpList);
	SaveEmpList(EmpList, "employeeDA.dat");
	return 0;
}

// FUNCTION DEFINITIONS FOLLOW

/* 	Takes the input from the keyboard and saves it into the array EmpList
	Input: Employee *EmpList
*/
void InputEmpRecord(Employee *EmpList){
	for(int i=0;i<4;i++){
		printf("\nEmployee #%d\n\nFirst Name: ", i+1);
		scanf("%s", EmpList[i].firstname);
		printf("Last Name: ");
		scanf("%s", EmpList[i].lastname);
		printf("ID: ");
		scanf("%d", &EmpList[i].id);
		printf("GPA: ");
		scanf("%f", &EmpList[i].GPA);
	}
}

/* 	Prints EmpList
	Input: const Employee *EmpList
*/
void PrintEmpList(const Employee *EmpList){
	for(int i=0;i<4;i++){
		printf("\n\nEmployee #%d\nFirst:\t%s\nLast:\t%s\nID:\t%d\nGPA:\t%f", i+1, EmpList[i].firstname, EmpList[i].lastname, EmpList[i].id, EmpList[i].GPA);
	}
}

/* 	Writes EmpList to a dat file
	Input: const Employee *EmpList, const char *FileName
*/
void SaveEmpList(const Employee *EmpList, const char *FileName){
	FILE *fPtr = fopen(FileName, "wb");

	for(int i=0;i<4;i++){
		char str[sizeof(Employee)] = {'\0'};
		sprintf(str, "%d %s %s %f\n", EmpList[i].id, EmpList[i].firstname, EmpList[i].lastname, EmpList[i].GPA);
		fwrite(str, sizeof(Employee), 1, fPtr);
	}
	fclose(fPtr);
}