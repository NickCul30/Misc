//a2_4integers.c
//Nicholas Culmone

#include <stdio.h>

int main(){
	int nums[4];

	//user input
	printf("Enter four integers: ");
	scanf("%d %d %d %d", &nums[0], &nums[1], &nums[2], &nums[3]);

	int lowest = nums[0], highest = nums[0];

	//goes through every input, checks if higher or lower than highest & lowest
	//and changes the highest & lowest variables accordingly
	for(int i=1;i<4;i++){
		if(nums[i] > highest){
			highest = nums[i];
		}
		else if(nums[i] < lowest){
			lowest = nums[i];
		}
	}

	//prints high & low
	printf("Highest: %d\nLowest : %d",highest, lowest);	

	return 0;
}