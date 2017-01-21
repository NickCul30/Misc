// Yo-Yo Brah
// Nicholas Culmone

import java.util.*;

public class Solution3{
	public static void main(String[]args){
		Scanner kb = new Scanner(System.in);
		int n = kb.nextInt();
		kb.nextLine();

		char[][]pic = new char[n][n];

		for(int i=0;i<n;i++){
			String tmp = kb.nextLine();
			pic[i] = tmp.toCharArray();
		}

		char[][]rotated = new char[n][n];
		int rot = kb.nextInt() % 4;

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(rot == 3) rotated[i][j] = pic[j][n-i-1];
				else if(rot == 2) rotated[i][j] = pic[n-i-1][n-j-1];
				else if(rot == 1) rotated[i][j] = pic[n-j-1][i];
				else rotated[i][j] = pic[i][j];
			}
		}

		for(char[] c : rotated){
			for(char ch : c){
				System.out.print(ch);
			}
			System.out.println("");
		}
	}
}