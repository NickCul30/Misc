import java.util.*;

class Solution{
	public static void main(String []args){
		Scanner kb = new Scanner(System.in);

		int num = kb.nextInt();
		kb.nextLine();
		String tmp = kb.nextLine();
		String[]stats = tmp.split(" ");

		int[]nums = new int[num];
		int i=0;
		for(String s : stats){
			nums[i] = Integer.parseInt(s);
			i++;
		}

		Arrays.sort(nums);

		String ans = "Yes";
		for(int k=1;k<nums.length;k++){
			int sum = 0, size = (int)Math.pow(k,3);
			for(int j=0;j<k;j++){
				sum += nums[j];
			}

			if(sum < size){
				ans = "No";
				break;
			}
		}

		System.out.println(ans);
	}
}
