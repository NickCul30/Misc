// ProgressPie.java
// Nicholas Culmone

import java.util.*;
import java.awt.*;
import java.io.*;

public class ProgressPie{
	public static void main(String[]args) throws IOException{
		Scanner wordFile = new Scanner(new BufferedReader(new FileReader("progress_pie.txt")));

		int n = Integer.parseInt(wordFile.nextLine());
		boolean[]ans = new boolean[n];
		PrintWriter saveWrite = new PrintWriter("saveFile.txt", "UTF-8");

		for(int i=0;i<n;i++){
			String tmp = wordFile.nextLine();
			String[]s = tmp.split(" ");
			ans[i] = checkBlack(Integer.parseInt(s[0]),Integer.parseInt(s[1]),Integer.parseInt(s[2]));

			if(ans[i]) saveWrite.println("Case #" + (i+1) + ": black");
			else saveWrite.println("Case #" + (i+1) + ": white");
		}

		saveWrite.close();
	}

	public static boolean checkBlack(int p, int x, int y){
		if(p == 0 || Math.pow(x-50,2) + Math.pow(y-50,2) > 2500) return false;
		x -= 50;
		y -= 50;
		int x2 = (int)(Math.pow(x,2));
		int y2 = (int)(Math.pow(y,2));

		if(Math.sqrt(x2 + y2) == 0) return true;

		double tmp = (double)(y / Math.sqrt(x2 + y2));
		double ang = Math.acos(tmp);
		if(x < 0) ang = 2*Math.PI - ang;

		double pAng = (double)(2*Math.PI*p) / 100;

		if(pAng >= ang) return true;
		return false;
	}
}