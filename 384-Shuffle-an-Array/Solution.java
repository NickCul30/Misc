//384. Shuffle an Array
//Nicholas Culmone

public class Solution {
    private int[]cur;
    private int[]orig;

    public Solution(int[] nums) {
        cur = new int[nums.length];
        orig = new int[nums.length];
        
        for(int i=0;i<nums.length;i++){
            cur[i] = nums[i];
            orig[i] = nums[i];
        }
    }
    
    /** Resets the array to its original configuration and return it. */
    public int[] reset() {
        for(int i=0;i<orig.length;i++) cur[i] = orig[i];
        return cur;
    }
    
    /** Returns a random shuffling of the array. */
    public int[] shuffle() {
        Random rand = new Random();
        ArrayList<Integer> tmp = new ArrayList<Integer>();
        for(int c : cur) tmp.add(c);
        
        for(int i=0;i<cur.length;i++){
            int  n = rand.nextInt(tmp.size());
            cur[i] = tmp.get(n);
            tmp.remove(n);
        }
        return cur;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int[] param_1 = obj.reset();
 * int[] param_2 = obj.shuffle();
 */