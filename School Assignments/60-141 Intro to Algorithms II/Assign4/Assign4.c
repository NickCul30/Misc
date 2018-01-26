// Assign4.c
// Nicholas Culmone
// Read in lines that contain the values of course. Put these values into an array
// then be able to add more courses to it, print the courses, or search the course
// by using an id number or the course code

// LIBRARY PACKAGES INCLUDED BELOW
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// STRUCT DEFINITIONS FOLLOW
struct courseInfo{
	int courseId;
	char courseName[50];
	char courseCode[12];
	char Term[6];
};
typedef struct courseInfo CourseInfo;

// FUNCTION PROTOTYPE STATEMENTS FOLLOW
void loadCourseInfo(CourseInfo *courses);						// Handles the information of the courses from stdin
void displayCourseInfo(CourseInfo *courses);					// Prints the information of the courses in a formatted table
void searchCourseInfo(char *e, CourseInfo *courses);			// Search for a course based on the ID or the course code
void searchCourseInfoId(int id ,CourseInfo *courses);			// Searches for a course from a ID
void searchCourseInfoName(char *name ,CourseInfo *courses);		// Searches for a course from a code
void printCourse(CourseInfo c);									// Prints the contents of a singular course
void addCourseInfo(CourseInfo *courses);						// Adds a course to the array of courses

// VARIABLE DECLARATION
int filled = 0;

// MAIN PROGRAM FOLLOWS
int main(){
	CourseInfo courses[100];
	loadCourseInfo(courses);

	int userInp = -1;
	char stringInp[80];

	// Interactive menu
	while(userInp != 0){
		printf("\n0. Exit\n1. Add new course\n2. Search for course\n3. Display course information\n\nEnter Selection: ");
		scanf("%d", &userInp);

		switch(userInp){
			case 0: break;
			case 1:
				addCourseInfo(courses);
				break;
			case 2:
				printf("\nEnter a Course Code or Course ID: ");
				scanf("%s",stringInp);
				searchCourseInfo(stringInp, courses);
				break;
			case 3:
				displayCourseInfo(courses);
				break;
			default:
				printf("\nInvalid input.\n");
				break;
		}
	}
	
	return 0;
}

// FUNCTION DEFINITIONS FOLLOW

/* 	Loads the information of all the courses in the file input.csv and puts them into
	an array of struct CourseInfo
	Input: CourseInfo *courses
*/
void loadCourseInfo(CourseInfo *courses){
	FILE *fPtr = fopen("input.csv","r");
	int i;

	for(i=0;!feof(fPtr);i++){
		char name[50], fac[3], sec[3], term;
		int sub, level, year, j;
		fscanf(fPtr, "%49[^,],%2[^,],%d,%d,%2[^,],%c,%d\n", name, fac, &sub, &level, sec, &term, &year);

		for(j=0;*(name+j) != '\0'; j++){
			*(name + j) = toupper(*(name + j));
		}

		sprintf(courses[i].courseCode, "%s%d-%d-%s", fac, sub, level, sec);
		sprintf(courses[i].courseName, "%s", name);
		sprintf(courses[i].Term, "%c%d", term, year);
		courses[i].courseId = i+1;
		filled ++;
	}

	fclose(fPtr);
}

/* 	Adds a course to the array when given a csv input by the user
	Input: CourseInfo *courses
*/
void addCourseInfo(CourseInfo *courses){
	char name[50], fac[3], sec[3], term, tmp[50];
	int sub, level, year, i;

	printf("\nEnter CourseName,Faculty,Subject,Level,Section,Term,Year (csv): ");
	scanf("\n%49[^,],%2[^,],%d,%d,%2[^,],%c,%d", name, fac, &sub, &level, sec, &term, &year);
	sprintf(tmp, "%s%d-%d-%s", fac, sub, level, sec);

	for(i=0;*(name+i) != '\0'; i++){
		*(name + i) = toupper(*(name + i));
	}
	term = toupper(term);

	bool dupe = false;
	for(i=0;i<filled;i++){
		if(strcmp(name,courses[i].courseCode) == 0) dupe = true; 
	}

	if(!dupe){
		strcpy(courses[filled].courseCode, tmp);
		sprintf(courses[filled].courseName, "%s", name);
		sprintf(courses[filled].Term, "%c%d", term, year);
		courses[filled].courseId = filled + 1;
		filled ++;
	}
}

/* 	Prints all of the courses in the array in a table
	Input: CourseInfo *courses
*/
void displayCourseInfo(CourseInfo *courses){
	int longest = 0, i;

	for(i=0;i<filled;i++){
		if(strlen(courses[i].courseName) > longest) longest = strlen(courses[i].courseName);
	}
	printf("\nID\tName%*cCode\t\tTerm\n", longest - 1, ' ');
	for(i=0;i<filled;i++){
		int sp = longest + 3 - strlen(courses[i].courseName);
		printf("%d\t%s%*c%s\t%s\n", courses[i].courseId, courses[i].courseName, sp, ' ', courses[i].courseCode, courses[i].Term);
	}
}

/* 	Searches for a course in the array of courses when given an input by the user.
	This function determines whether its a course ID or course name that the user is
	searching for, then calls the appropriate function to search for that ID/name
	Input: char *e, CourseInfo *courses
*/
void searchCourseInfo(char *e, CourseInfo *courses){
	int tmp = atoi(e);
	if(tmp != 0 && tmp <= filled){
		searchCourseInfoId(tmp, courses);
	}
	else{
		searchCourseInfoName(e, courses);
	}
}

/* 	Called upon by searchCourseInfo when that function converts the string input into an
	integer and determines that the user is attempting to search for an ID
	Input: int id, CourseInfo *courses
*/
void searchCourseInfoId(int id ,CourseInfo *courses){
	int i;
	for(i=0;i<filled;i++){
		if(id == courses[i].courseId){
			printCourse(courses[i]);
			return;
		}
	}
	printf("\nCourse not found.\n");
}

/* 	Called upon by searchCourseInfo when that function determines that the user is 
	attempting to search for a course name
	Input: char *name, CourseInfo *courses
*/
void searchCourseInfoName(char *name ,CourseInfo *courses){
	int i;
	for(i=0;*(name+i) != '\0'; i++){
		*(name + i) = toupper(*(name + i));
	}
	for(i=0;i<filled;i++){
		if(strcmp(name,courses[i].courseName) == 0){
			printCourse(courses[i]);
			return;
		}
	}
	printf("\nCourse not found.\n");
}

/* 	Prints a singular course
	Input: CourseInfo c
*/
void printCourse(CourseInfo c){
	int sp = strlen(c.courseName) - 1;
	printf("\nID\tName%*c\tCode\t\tTerm\n", sp, ' ');
	printf("%d\t%s%*c\t%s\t%s\n", c.courseId, c.courseName, 3, ' ', c.courseCode, c.Term);
}