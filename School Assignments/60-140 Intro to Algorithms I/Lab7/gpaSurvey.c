//gpaSurvey.c
//Nicholas Culmone

#include <stdio.h>

int main(){
	int stu, mark; //var setting
	int gpaFreq[4] = {0,0,0,0};

	printf("Enter the number of students: "); //prompt & user input
	scanf("%d", &stu);

	for(int i=0;i<stu;i++){ //loops until num of students entered all have valid marks
		printf("GPA of student #%d is: ", i+1); //prompt & user input
		scanf("%d", &mark);

		if(mark >= 1 && mark <= 4) gpaFreq[mark-1] ++; //if the mark is valid, adds to markFreq
		else{ //mark is invalid
			printf("Invalid number!\n");
			i--;
		}
	}

	printf("The total number of students is %d\n", stu); //prints out freqs of all marks
	for(int i=0;i<4;i++){
		printf("GPA %d --- %d student(s)\n", i+1, gpaFreq[i]);
	}

	return 0;
}