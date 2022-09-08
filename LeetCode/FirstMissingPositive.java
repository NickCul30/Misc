// 41. First Missing Positive
// Nicholas Culmone
// August 2nd 2022
// LeetCode Hard Problem

public class FirstMissingPositive{
    public static void main(String[]args){
        int[] nums = {7,8,9,11,12};
        int ans = firstMissingPositive(nums);
        System.out.println(ans);
    }

    public static int firstMissingPositive(int[] nums) {
        int ans = 1;
        int[] order = new int[500001];

        for(int i=0; i<nums.length; i++){
            if(nums[i] > 0 && nums[i] <= 500000){
                order[nums[i] - 1] = 1;
            }
        }

        for(int i=0; i<500001; i++){
            if(order[i] == 0){
                ans = i+1;
                break;
            }
        }

        return ans;
    }
}