// Lab8a.c
// Nicholas Culmone
// Take input from the keyboard to define the employees,
// next take the input and write to a text file

// LIBRARY PACKAGES INCLUDED BELOW
#include <stdio.h>
#include <string.h>

// STRUCT DEFINITIONS FOLLOW
struct employee {
	char firstname[40];
	char lastname[40];
	int id;
	int GPA;
};
typedef struct employee Employee;

// FUNCTION PROTOTYPE STATEMENTS FOLLOW

void InputEmpRecord(Employee *EmpList);								//Input the employee data interactively from the keyboard
void PrintEmpList(const Employee *EmpList);							//Display the contents of Employee records from the list
void SaveEmpList(const Employee *EmpList, const char *FileName);	//Save the employee records from the list to the newly created text file specified by FileName

// MAIN PROGREAM FOLLOWS
int main() {
	Employee EmpList[3];
	InputEmpRecord(EmpList);
	PrintEmpList(EmpList);
	SaveEmpList(EmpList, "employee.dat");
	return 0;
}

// FUNCTION DEFINITIONS FOLLOW

/* 	Takes informaton from stdin and saves the values in the array EmpList
	Input: Employee *EmpList
*/
void InputEmpRecord(Employee *EmpList){
	for(int i=0;i<3;i++){
		printf("\nEmployee #%d\n\nFirst Name: ", i+1);
		scanf("%s", EmpList[i].firstname);
		printf("Last Name: ");
		scanf("%s", EmpList[i].lastname);
		printf("ID: ");
		scanf("%d", &EmpList[i].id);
		printf("GPA: ");
		scanf("%d", &EmpList[i].GPA);
	}
}

/* 	Prints the list of employees
	Input: const Employee *EmpList
*/
void PrintEmpList(const Employee *EmpList){
	for(int i=0;i<3;i++){
		printf("\n\nEmployee #%d\nFirst:\t%s\nLast:\t%s\nID:\t%d\nGPA:\t%d", i+1, EmpList[i].firstname, EmpList[i].lastname, EmpList[i].id, EmpList[i].GPA);
	}
}

/* 	Saves the contents of EmpList into a text file
	Input: const Employee *EmpList, const char *FileName
*/
void SaveEmpList(const Employee *EmpList, const char *FileName){
	FILE *fPtr = fopen(FileName,"w");

	for(int i=0;i<3;i++){
		fprintf(fPtr, "%d %s %s %d\n", EmpList[i].id, EmpList[i].firstname, EmpList[i].lastname, EmpList[i].GPA);
	}
	fclose(fPtr);
}