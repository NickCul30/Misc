// The Great XOR
// Nicholas Culmone
// https://www.hackerrank.com/contests/w28/challenges/the-great-xor

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class GreatXOR {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int q = in.nextInt();
        long[]ans = new long[q];
        
        for(int a0 = 0; a0 < q; a0++){
            long x = in.nextLong();
            long i = 1;
            
            while(x > i){
                i = i*2 + 1;
            }
            ans[a0] = i - x;
        }
        
        for(long i : ans){
            System.out.println(i + "");
        }
    }
}