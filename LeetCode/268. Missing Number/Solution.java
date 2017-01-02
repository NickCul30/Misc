
public class Solution{
	public static void main(String[]args){
		int[] nums = {};
		System.out.println(missingNumber(nums));
	}
	public static int missingNumber(int[] nums){
		int tot = 0, fullTot = 0;

		for(int i=0;i<nums.length;i++){
			tot += nums[i];
			fullTot += i;
		}
		fullTot += nums.length;

		return fullTot - tot;
	}
}