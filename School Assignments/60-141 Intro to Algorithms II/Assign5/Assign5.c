// Assign5.c
// Nicholas Culmone
// Implement a Linked List of structs that can be added to, remove elements from,
// save, and load from a text file among other functions.


// LIBRARY PACKAGES INCLUDED BELOW
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


// STRUCT DEFINITIONS FOLLOW
struct CourseInfo{
	int courseID;
	char courseName[30];
};
typedef struct CourseInfo courseInfo;

struct StudentInfo{
	char StudentID[10];
	char firstName[21];
	char lastName[26];
	int numCourses;
	struct CourseInfo courses[10];
	struct StudentInfo *next;
};
typedef struct StudentInfo studentInfo;


// FUNCTION PROTOTYPES FOLLOW
studentInfo *addStudent(studentInfo *stud, studentInfo *head);		// Adds a student in the correct spot in the LList, given its pointer
studentInfo *enterStudent();										// Creates a new student based on the input from stdin
void displayStudentInfo(studentInfo *List);							// Displays all students' information
studentInfo *deleteStudent(studentInfo *head, char id[10]);			// Deletes a student based on their ID
void searchStudentlName(studentInfo *head, char name[26]);			// Searches a student for their last name, then prints their info
studentInfo *searchStudentID(studentInfo *head, char id[10]);		// Searches a student based on their ID, returns its pointer
studentInfo *loadStudentInfo(char *fileName);						// Loads student information when specified a file name
void printStudent(studentInfo *cur);								// Prints a singular student's information
void saveStudentInfo(studentInfo *head, char *FileName);			// Saves all student information to a specified file name


// MAIN PROGRAM FOLLOWS
int main(){
	int userInp = -1;
	studentInfo *List, *new;
	char idInp[10], lName[26];

	List = loadStudentInfo("studentList.txt");

	while(userInp != 0){
		printf("\n0. Exit\n1. Add new student\n2. Delete a student\n3. Search for a student\n4. Display current students\n5. Save student information\n\nEnter Selection: ");
		scanf("%d", &userInp);

		switch(userInp){
			case 0: break;
			case 1:
				new = enterStudent();
				List = addStudent(new, List);
				break;
			case 2:
				printf("Student ID: ");
				scanf("\n%9[^\n]s", idInp);
				List = deleteStudent(List, idInp);
				break;
			case 3:
				printf("What is last name of student? ");
				scanf("\n%25[^\n]s", lName);
				searchStudentlName(List, lName);
				break;
			case 4:
				displayStudentInfo(List);
				break;
			case 5:
				saveStudentInfo(List, "studentList.txt");
				break;
			default:
				printf("\nInvalid input.\n");
				break;
		}
	}

	return 0;
}

// FUNCTION DEFINITIONS FOLLOW

/* 	Adds a student in the correct spot in the LList, when given its pointer and
	the pointer to the beginning of the LList
	Input: studentInfo *stud, studentInfo *head
	Output: the pointer to the beginning of the LList
*/
studentInfo *addStudent(studentInfo *stud, studentInfo *head){

	if(!head){
		head = stud;
		return head;
	}

	studentInfo *cur = head, *last = NULL;

	for(;strcmp(cur->StudentID,stud->StudentID) < 0 && cur->next;){
		last = cur;
		cur = cur->next;
	}

	if(strcmp(stud->StudentID,cur->StudentID) == 0){
		printf("Ignored duplicate student ID.");
		return head;
	}
	else if(strcmp(cur->StudentID,stud->StudentID) > 0){
		if(!last){
			head = stud;
			stud->next = cur;
		}
		else{
			last->next = stud;
			stud->next = cur;
		}
	}
	else{
		cur->next = stud;
	}
	return head;
}

/* 	Creates a new student based on the input from stdin
	Output: studentInfo *new (pointer to the new student)
*/
studentInfo *enterStudent(){
	char id[10], fName[21], lName[26];
	int n;
	courseInfo cours[10];
	printf("Student ID: ");
	scanf("\n%9[^\n]s", id);
	printf("First name: ");
	scanf("\n%20[^\n]s", fName);
	printf("Last name: ");
	scanf("\n%25[^\n]s", lName);
	printf("Number of courses: ");
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		char tmpN[30];
		int tmpID;
		printf("Course Name: ");
		scanf("\n%29[^\n]s", tmpN);
		printf("Course ID: ");
		scanf("%d", &tmpID);
		strcpy(cours[i].courseName, tmpN);
		cours[i].courseID = tmpID;
	}

	studentInfo *new = malloc(sizeof(studentInfo));
	strcpy(new->StudentID, id);
	strcpy(new->firstName, fName);
	strcpy(new->lastName, lName);
	new->numCourses = n;
	for(int i=0;i<10;i++){
		strcpy(new->courses[i].courseName, cours[i].courseName);
		new->courses[i].courseID = cours[i].courseID;
	}

	*(new->firstName) = toupper(*(new->firstName));
	*(new->lastName) = toupper(*(new->lastName));

	return new;
}

/* 	Displays all student's information to stdout, calls printStudent
	multiple times in order to do so.
	Input: studentInfo *List
*/
void displayStudentInfo(studentInfo *List){
	studentInfo *cur = List;

	for(int i=1;cur;cur = cur->next){
		printf("\nStudent %d:", i);
		printStudent(cur);
		i++;
	}
}

/* 	Deletes a student given their ID.
	Input: studentInfo *head, char id[10]
	Output: studentInfo *head (the pointer to the head in the LList)
*/
studentInfo *deleteStudent(studentInfo *head, char id[10]){
	studentInfo *cur = head, *last = NULL;

	for(;strcmp(cur->StudentID, id) != 0 && cur->next;){
		last = cur;
		cur = cur->next;
	}

	if(strcmp(cur->StudentID, id) == 0){
		if(cur == head){
			head = head->next;
			free(cur);
		}
		else{
			last->next = cur->next;
			free(cur);
		}
		printf("\nStudent information deleted.\n");
	}
	else{
		printf("\nStudent not found.\n");
	}

	return head;
}

/* 	Searches through the LList for the specified student with the same StudentID
	as the input id
	Input: studentInfo *head, char id[10]
	Output: studentInfo *cur (the student with the specified ID, or NULL if not found)
*/
studentInfo *searchStudentID(studentInfo *head, char id[10]){
	studentInfo *cur = head;

	for(;strcmp(cur->StudentID, id) != 0 && cur->next; cur = cur->next);

	if(strcmp(cur->StudentID, id) == 0) return cur;
	else return NULL;
}

/* 	Searches through the LList for the specified student with the same lastName
	as the input name, then prints that student's information
	Input: studentInfo *head, char name[26]
*/
void searchStudentlName(studentInfo *head, char name[26]){
	studentInfo *cur = head;
	*name = toupper(*name);

	for(;strcmp(cur->lastName, name) != 0 && cur->next;cur = cur->next);

	if(strcmp(cur->lastName, name) == 0){
		printStudent(cur);
	}
	else printf("Student not found.\n");
	return;
}

/* 	Loads student information from a specified filename, then returns the
	pointer to the head of the LList created from this info.
	Input: char *Filename
*/
studentInfo *loadStudentInfo(char *FileName){
	FILE *fPtr = fopen(FileName, "r");
	char id[10] = "";
	studentInfo *head, *cur = NULL;

	while(!feof(fPtr)){
		char fName[21], lName[26];
		int n;
		courseInfo cours[10];

		fscanf(fPtr, "\n%s\n%s\n%s\n%d\n", id, fName, lName, &n);
		if(strcmp(id, "***") == 0) break;
		for(int i=0;i<n;i++){
			fscanf(fPtr, "%s %d\n", cours[i].courseName, &(cours[i].courseID));
		}

		studentInfo *new = malloc(sizeof(studentInfo));
		strcpy(new->StudentID, id);
		strcpy(new->firstName, fName);
		strcpy(new->lastName, lName);
		new->numCourses = n;
		for(int i=0;i<10;i++){
			strcpy(new->courses[i].courseName, cours[i].courseName);
			new->courses[i].courseID = cours[i].courseID;
		}
		*(new->firstName) = toupper(*(new->firstName));
		*(new->lastName) = toupper(*(new->lastName));

		if(!cur){
			head = new;
			cur = new;
		}
		else{
			cur->next = new;
			cur = cur->next;
		}
	}

	fclose(fPtr);
	return head;
}

/* 	Prints the information to stdout of a singular student.
	Input: studentInfo *cur
*/
void printStudent(studentInfo *cur){
	printf("\n%s\n%s\n%s\n%d\n", cur->StudentID, cur->firstName, cur->lastName, cur->numCourses);
	for(int j=0;j<cur->numCourses;j++){
		printf("%s %d\n", cur->courses[j].courseName, cur->courses[j].courseID);
	}
}

/* 	Saves the LList of students to the text file with the line *** at the end
	Input: studentInfo *head, char *FileName
*/
void saveStudentInfo(studentInfo *head, char *FileName){
	FILE *fPtr = fopen(FileName, "w");
	studentInfo *cur = head;

	for(;cur;cur = cur->next){
		fprintf(fPtr, "%s\n%s\n%s\n%d\n", cur->StudentID, cur->firstName, cur->lastName, cur->numCourses);
		for(int i=0;i<cur->numCourses;i++){
			fprintf(fPtr, "%s %d\n", cur->courses[i].courseName, cur->courses[i].courseID);
		}
	}
	fprintf(fPtr, "***");
	fclose(fPtr);
}