// 202. HappyNumber.java
// Nicholas Culmone
// August 17th 2022

import java.util.*;

class Solution {
    public boolean isHappy(int n) {
        ArrayList<Integer>hasDone = new ArrayList<Integer>();
        
        while(!hasDone.contains(n)){
            hasDone.add(n);
            int tmp = n;
            n=0;
            while(tmp > 0){
                n += Math.pow(tmp%10, 2);
                tmp /= 10;
            }
            if(n==1){
                return true;
            }
        }
        return false;
    }
}