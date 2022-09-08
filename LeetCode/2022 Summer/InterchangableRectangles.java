// InterchangableRectangles.java
// Nicholas Culmone
// August 30th 2022

class Solution {
    public long interchangeableRectangles(int[][] rectangles) {
        float[] ratios = new float[rectangles.length];
        
        for(int i=0;i<rectangles.length;i++){
            ratios[i] = (float)(rectangles[i][0]) / (float)(rectangles[i][1]);
        }
        Arrays.sort(ratios);
        
        long total = 0;
        int start = 0;
        int end = 0;
        
        for(int i=1; i<ratios.length; i++){
            if(ratios[i] != ratios[start]){
                if(start != end){
                    // chooser
                    long n = end - start + 1;
                    long r = 2;
                    
                    total += choose(n,r);
                }
                start = i;
                end = i;
            }
            else{
                end = i;
            }
        }
        
        if(start != end){
            // chooser
            long n = end - start + 1;
            long r = 2;

            total += choose(n,r);
        }
        
        return total;
    }
    
    public static long choose(long total, long choose){
        if(total < choose)
            return 0;
        if(choose == 0 || choose == total)
            return 1;
        return choose(total-1,choose-1)+choose(total-1,choose);
    }
}