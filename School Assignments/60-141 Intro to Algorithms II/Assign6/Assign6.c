// Assign6.c
// Nicholas Culmone
// Reads a set of students who have 10 marks each, creates a file and saves the
// students' information into it, along with their GPA. Sorted in ascending order
// based on id.

// LIBRARY PACKAGES INCLUDED BELOW
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// STRUCT DEFINITIONS FOLLOW
struct StudentGrades{
	int studentID;
	float courseMarks[10];
	float GPA; 
};
typedef struct StudentGrades Student;

// FUNCTION PROTOTYPES FOLLOW
int numStudents(char *filename);		// Gets the number of students in the input file
float getGPA(Student stud);				// Gets the GPA of a given student


// MAIN PROGRAM FOLLOWS
int main(){
	int bytesOut = 0, numStud = numStudents("assign6.dat");

	FILE *fPtr = fopen("Assign6.dat", "r");
	FILE *fOut = fopen("Assign6out.dat", "w+");
	FILE *fResults = fopen ("Assign6results.dat", "w");

	fseek(fPtr, 0, SEEK_END);
	int bytesIn = ftell(fPtr);	
	fseek(fPtr, 0, SEEK_SET);
	
	char cur[1000];
	memset(cur, 0, sizeof(cur));

	for (int i=0;i<numStud;i++){
		Student tmp;
		fgets(cur,sizeof(cur), fPtr);

		char *linePtr = strtok(cur, "\n");
		while (linePtr != NULL){
			sscanf(cur, "%d %f %f %f %f %f %f %f %f %f %f", &(tmp.studentID), &(tmp.courseMarks[0]), &(tmp.courseMarks[1]), &(tmp.courseMarks[2]),&(tmp.courseMarks[3]), &(tmp.courseMarks[4]), &(tmp.courseMarks[5]),&(tmp.courseMarks[6]), &(tmp.courseMarks[7]), &(tmp.courseMarks[8]),&(tmp.courseMarks[9]));
			linePtr = strtok(NULL, "\n");
		}
		tmp.GPA = getGPA(tmp);
		
		fwrite(&tmp, sizeof(tmp), 1, fOut);
		bytesOut += sizeof(tmp);
	}

	Student s1;
	Student s2;
	fseek(fOut, 0, SEEK_SET);

	bool sorting = true;
	while(sorting){
		sorting = false;
		for(int i=0;i<numStud-1;i++){
			fseek(fOut, i * sizeof(Student), SEEK_SET);
			fread(&s1, sizeof(Student), 1 ,fOut);
     		fread(&s2, sizeof(Student), 1 ,fOut);
     		if (s1.studentID > s2.studentID){
     			fseek(fOut, i * sizeof(Student), SEEK_SET);
     			fwrite(&s2, sizeof(Student), 1, fOut);
     			fwrite(&s1, sizeof(Student), 1, fOut);
     			sorting = true;
     		}
		}
	}

    fseek(fOut, 0, SEEK_SET);
    for (int i=0; i< numStud;i++){
    	Student tmp;
	    fread(&tmp, sizeof(tmp), 1, fOut);
	    fprintf(fResults, "%d %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f\n", tmp.studentID, tmp.courseMarks[0], tmp.courseMarks[1], tmp.courseMarks[2],tmp.courseMarks[3], tmp.courseMarks[4], tmp.courseMarks[5],tmp.courseMarks[6], tmp.courseMarks[7], tmp.courseMarks[8],tmp.courseMarks[9], tmp.GPA);
    }
    fprintf(fResults, "Input File Size: %d\nOutput File Size: %d", bytesIn, bytesOut);

    fclose(fPtr);
    fclose(fOut);
    fclose(fResults);

    return 0;
}

// FUNCTION DEFINITIONS FOLLOW

/*	Gets the number of students in the input file 
	Input: char *filename
	Output: int numStud
*/
int numStudents(char *filename){
	int numStud = 0;
	int ch = 0;
	FILE *fPtr = fopen(filename, "r");

	if (fPtr == NULL){
		return 0;
	}

	while (!feof(fPtr)){
		ch = fgetc(fPtr);
		if (ch == '\n'){
			numStud++;
		}
	}

	fseek(fPtr, 0, SEEK_SET);
	if ((fPtr != NULL) && (numStud >= 0)) numStud++;
	fclose(fPtr);

	return numStud;
}

/* 	Gets the GPA mark of a student
	Input: Student stu
	Output: int avg
*/
float getGPA(Student stu){
	float tot = 0, avg; 
	for (int i=0;i<10;i++){
		tot += stu.courseMarks[i];
	}
	avg = tot/10 * .04;

	return avg;
}