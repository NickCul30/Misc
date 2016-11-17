//Solution.java
//Nicholas Culmone
//September 22 2016
//150. Evaluate Reverse Polish Notation

import java.awt.*;
import java.util.*;

public class Solution {
	public static void main(String[]args){
		String[]stuff = {"36", "4", "13", "+", "/"};
		System.out.println(evalRPN(stuff));
	}
    public static int evalRPN(String[] tokens) {
    	int[]nums = {};

        for(String s : tokens){
        	if(s.equals("+") || s.equals("-") || s.equals("*") || s.equals("/")){
        		nums = eval(nums,s);
        	}
        	else{
        		nums = push(nums,Integer.parseInt(s));
        	}
        }
        return nums[0];
    }
    public static int[] push(int[]strs, int t){
    	int[]tmp = new int[strs.length + 1];

    	tmp[0] = t;

    	for(int i=0;i<strs.length;i++){
    		tmp[i+1] = strs[i];
    	}

    	return tmp;
    }
	public static int[] pop2(int[]nums){
		int[]tmp = new int[nums.length - 2];

		for(int i=2;i<nums.length;i++){
    		tmp[i-2] = nums[i];
    	}

    	return tmp;
	}
	public static int[] eval(int[]nums, String operand){
		int toAdd = 0;

    	if(operand.equals("+")) toAdd = nums[1] + nums[0];
    	if(operand.equals("-")) toAdd = nums[1] - nums[0];
    	if(operand.equals("*")) toAdd = nums[1] * nums[0];
    	if(operand.equals("/")) toAdd = nums[1] / nums[0];

    	nums = pop2(nums);
    	nums = push(nums,toAdd);

    	return nums;
    }
}