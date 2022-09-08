//231. Power of Two
//Nicholas Culmone

public class Solution{
	public static void main(String[]args){
		System.out.println(isPowerOfTwo(1));

	}
	public static boolean isPowerOfTwo(int n){
		int tmp = 0, tot = 0;

		if(n == 0 || n == Integer.MAX_VALUE) return false;
		while(n > tot){
			tot = (int)(Math.pow(2,tmp));
			tmp ++;
		}

		if(n == tot) return true;
		return false;
	}
}