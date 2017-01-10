// LazyLoading.java
// Nicholas Culmone

import java.util.*;
import java.awt.*;
import java.io.*;

public class LazyLoading{
	public static void main(String[]args) throws IOException{
		Scanner input = new Scanner(new BufferedReader(new FileReader("lazy_loading.txt")));
		PrintWriter output = new PrintWriter("output.txt", "UTF-8");

		int d = Integer.parseInt(input.nextLine());
		for(int i=0;i<d;i++){

			int n = Integer.parseInt(input.nextLine());
			int h = n, l = 0;
			int[]nums = new int[n];

			for(int j=0;j<n;j++){
				nums[j] = Integer.parseInt(input.nextLine());
			}
			Arrays.sort(nums);
			int tot = 0, trips = 0;

			while(h > l){
				h--;
				tot = nums[h];
				while(tot < 50 && h > l){
					tot += nums[h];
					l++;
				}
				if(tot >= 50) trips ++;
			}

			output.println("Case #" + (i+1) + ": " + trips);
		}

		output.close();
	}
}