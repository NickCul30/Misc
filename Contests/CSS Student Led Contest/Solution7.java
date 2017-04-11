import java.util.*;

class Solution2{
	public static void main(String[]args){
		Scanner kb = new Scanner(System.in);
		int[] time1 = new int[3];
		int[] time2 = new int[3];

		String tmp1 = kb.nextLine();
		String[]stats = tmp1.split(":");
		for(int i=0;i<3;i++){
			time1[i] = Integer.parseInt(stats[i]);
		}

		tmp1 = kb.nextLine();
		String[]stats2 = tmp1.split(":");
		for(int i=0;i<3;i++){
			time2[i] = Integer.parseInt(stats2[i]);
		}

		int t1 = time1[0] * 3600 + time1[1] * 60 + time1[2];
		int t2 = time2[0] * 3600 + time2[1] * 60 + time2[2];

		int ans1 = Math.abs(t1-t2);
		int ans2 = 24*3600 - ans1;

		if(ans1 > ans2) System.out.println("" + ans2);
		else System.out.println("" + ans1);
	}
}