//Solution.java
//Nicholas Culmone
//September 21 2016
//67. Add Binary

import java.awt.*;
import java.util.*;

public class Solution {
	public static void main(String[]args){
		System.out.println(addBinary("0","0"));
	}
    public static String addBinary(String a, String b) {
        int len = a.length();
        int diff = Math.abs(len-b.length());

        if(diff == 0){}
        else if(b.length() > len){
        	len = b.length();
        	for(int j=0;j<diff;j++){
        		a = "0" + a;
        	}
        }
        else{
        	for(int j=0;j<diff;j++){
        		b = "0" + b;
        	}
        }

        String ans = "";
        int carry = 0;
        int newCarry = 0;
        int toAdd = 0;

        for(int i=len-1;i>=0;i--){
        	char a1 = a.charAt(i);
        	char b1 = b.charAt(i);

        	if(a1 == '1' && b1 == '1'){
        		newCarry = 1;
        		toAdd = carry;
        	}
        	else if(a1 == '1' || b1 == '1'){
        		if(carry == 1){
        			newCarry = 1;
        			toAdd = 0;
        		}
        		else{
        			newCarry = 0;
        			toAdd = 1;
        		}
        	}
        	else{
        		newCarry = 0;
        		toAdd = carry;
        	}

        	ans = Integer.toString(toAdd) + ans;
        	carry = newCarry;
        }
        if(carry == 1) ans = Integer.toString(carry) + ans;
        return ans;
    }
}