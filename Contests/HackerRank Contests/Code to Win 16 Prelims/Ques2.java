
public class Ques2{
	public static void main(String[]args){
		System.out.println(countPalindromes("abccba"));
	}
	public static int countPalindromes(String s) {
		int count = 0;
		String tmp, rev;

		for(int i=1;i<=s.length();i++){
			for(int j=0;j<s.length()-i+1;j++){
				tmp = s.substring(j,j+i);
				rev = reverse(tmp);
				if(tmp.equals(rev)) count ++;
			}
		}
		return count;
    }

    public static String reverse(String input){
	    char[] in = input.toCharArray();
	    int begin=0;
	    int end=in.length-1;
	    char temp;
	    while(end>begin){
	        temp = in[begin];
	        in[begin]=in[end];
	        in[end] = temp;
	        end--;
	        begin++;
	    }
    	return new String(in);
    }
}