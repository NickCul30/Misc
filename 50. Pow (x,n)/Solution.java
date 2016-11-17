//Solution.java
//Nicholas Culmone
//September 21 2016
//50. Pow(x,n)

public class Solution {
    public static void main(String[]args){
        System.out.println(Math.abs(-248));
    }
    public double myPow(double x, int n) {
        int nAbs = Math.abs(n);
        double ans = 1;
        double oldAns = (double)(Integer.MAX_VALUE);
        if(n == Integer.MIN_VALUE) nAbs = Integer.MAX_VALUE;

        for(int i=0;i<nAbs;i++){
            ans *= x;
            if(ans == 0) return 0;
            else if(ans >= (double)(Double.POSITIVE_INFINITY)){
                if(n > 0) return Double.POSITIVE_INFINITY;
                else return 0;
            }
            else if(ans == Math.abs(oldAns)){
                if(x <= 0 && n % 2 == 1) return Math.abs(ans) * (-1);
                else return ans;
            }
            oldAns = ans;
        }
        if(n < 0 && ans != 0){
            ans = 1/ans;
        }
        return ans;
    }
}