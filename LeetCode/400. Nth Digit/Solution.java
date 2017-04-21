// Solution.java
// Nicholas Culmone
// 420 2017

import java.util.*;

public class Solution {
	public static void main(String[]args){
		System.out.println(findNthDigit(15));
	}

    public static int findNthDigit(int n){
        int p=0;

        while(n - 9 * Math.pow(10,p) * (p+1) > 0 ){
        	n -= 9 * Math.pow(10,p) * (p+1);
        	p++;
        }

        int dig = p - ((n-1) % (p+1));
        int num = (int)Math.pow(10,p) + (n-1)/(p+1);
        int ans=2;

        for(int i=0;i<=dig;i++){
        	ans = num % 10;
        	num /= 10;
        }
        return ans;
    }
}
