//Solution.java
//Nicholas Culmone
//September 21 2016
//6. Zig Zag Conversion

import java.awt.*;
import java.util.*;

public class Solution {
    public static void main(String[]args){
        System.out.println(convert("ABC",2));
    }
    
    public static String convert(String s, int numRows) {
        String[]rows = new String[numRows];
        char[]charArray = s.toCharArray();
        int count = 0;
        int rowAdd = 0;
        boolean dirDown = true;

        while(count <= s.length()-1){
        	if(rows[rowAdd] == null) rows[rowAdd] = "" + charArray[count];
        	else rows[rowAdd] += charArray[count];

        	count ++;
        	if(numRows == 1){}
        	else if(rowAdd >= numRows-1){
        		rowAdd --;
        		dirDown = false;
        	}
        	else if(rowAdd <= 0){
        		rowAdd ++;
        		dirDown = true;
        	}
        	else{
        		if(dirDown) rowAdd ++;
	        	else rowAdd --;
        	}

        }

        String ans = "";

        for(String w : rows){
			if(w != null) ans += w;
        }
        return ans;
    }
}