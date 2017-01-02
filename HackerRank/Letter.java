// The Love-Letter Mystery 
// Nicholas Culmone

import java.util.*;

public class Letter{
	public static void main(String[]args){
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		in.nextLine();

		int[]ans = new int [n];

		for(int i=0;i<n;i++){
			String s = in.nextLine();
			int tot = 0;

			for(int j=0;j<s.length()/2;j++){
				tot += Math.abs((int)s.charAt(j) - (int)s.charAt(s.length()-j-1));
			}
			ans[i] = tot;
		}

		for(int i=0;i<n;i++) System.out.println("" + ans[i]);
	}
}