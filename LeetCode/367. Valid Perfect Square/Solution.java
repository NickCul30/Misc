//367. Valid Perfect Square
//Nicholas Culmone

public class Solution {
	public static void main(String[]args){
		System.out.println(isPerfectSquare(4));
	}
    public static boolean isPerfectSquare(int num) {
    	if(num == Integer.MAX_VALUE) return false;
        int sqr = 0,test = 0;
        while(num > sqr){
        	sqr = test * test;
        	test ++;
        }
        if(sqr == num) return true;
        else return false;
    }
}