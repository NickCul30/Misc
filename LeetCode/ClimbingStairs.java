// 70. ClimbingStairs.java
// August 24th 2022
// Nicholas Culmone
// LeetCode

class Solution {
    public int climbStairs(int n) {
        int[]ways = new int[n];
        ways[0] = 1;
        if(n != 1) ways[1] = 2;
        
        for(int i=2; i<n; i++) ways[i] = ways[i-1] + ways[i-2];
        
        return ways[n-1];
    }
}