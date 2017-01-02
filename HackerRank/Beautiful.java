// Beautiful Binary String
// Nicholas Culmone

import java.util.*;

public class Beautiful{
	public static void main(String[]args){
		Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        in.nextLine();
        String B = in.nextLine();
        boolean[] start = new boolean[n];

        for(int i=0;i<n-2;i++){
        	if(B.substring(i,i+3).equals("010")) start[i] = true;
        }

        boolean[] tmp = new boolean[n];
        if(start != tmp){
        	int count = 0;
        	for(int i=0;i<n-2;i++){
        		if(start[i] == true){
        			if(start[i+2] == true) start[i+2] = false;
        			count ++;
        		}
        	}
        	System.out.println("" + count);
        }
        else{
        	System.out.println("0");
        }
	}
}