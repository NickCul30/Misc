// 45. JumpGameII.java
// Nicholas Culmone
// July 27th 2022

public class JumpGameII {
    public static void main(String[]args){
        int[] nums = {2,3,0,1,4};
        int ans = jump(nums);

        System.out.println(ans);
    }

    public static int jump(int[] nums){
        int lng = nums.length;
        int[] jumps = new int[lng];

        for(int i=0; i<lng; i++){
            for(int j=1; i+j<lng && j<=nums[i]; j++){
                if(jumps[i]+1 < jumps[i+j] || jumps[i+j] == 0){
                    jumps[i+j] = jumps[i] + 1;
                }
            }
        }
        return jumps[lng-1];
    }
}
