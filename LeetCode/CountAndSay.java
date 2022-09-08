// 38. CountAndSay
// Nicholas Culmone
// August 16th 2022
// LeetCode Medium

class Solution {
    public String countAndSay(int n) {        
        if(n == 1) return "1";
        
        String s = countAndSay(n-1);
        
        char curChar = s.charAt(0);
        int count = 0;
        String ans = "";
        
        for(int i=0; i<s.length(); i++){
            if(s.charAt(i) != curChar){
                ans += Integer.toString(count) + curChar;
                count = 0;
                curChar = s.charAt(i);
            }
            count++;
        }
        ans += Integer.toString(count) + curChar;
  
        return ans;
    }
}