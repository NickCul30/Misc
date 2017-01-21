/// Cost of Spam
// Nicholas Culmone

import java.util.*;

public class Solution2{
	public static void main(String[]args){
		Scanner kb = new Scanner(System.in);
		String s = kb.nextLine();

		int tot = 0;
		for(int i=0;i<s.length();i++){
			int c = s.charAt(i);
			if(c != 32){
				int tmp = c % 3;
				if(tmp == 0) tmp = 3;
				tot += tmp;
			}
			else tot ++;
		}

		System.out.println("" + tot);
	}
}