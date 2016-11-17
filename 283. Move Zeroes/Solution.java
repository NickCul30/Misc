
import java.util.*;
import java.awt.*;

public class Solution {
	public static void main(String[]args){
		int[]nums = {0,0,1,3,12};
		moveZeroes(nums);
		System.out.println(Arrays.toString(nums));
	}

    public static void moveZeroes(int[] nums) {
    	int count = 0;

        for(int i=0;i<nums.length - 1;i++){
        	if(nums[i] == 0){
        		count ++;
        		for(int j=0;j<nums.length-i-1;j++){
        			nums[j+i] = nums[j+i+1];
        		}
        		nums[nums.length-1] = 0;
        		if(i <= nums.length-count) i--;
        	}
        }
    }
}