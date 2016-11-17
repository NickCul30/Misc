
public class Ques3{
	public static void main(String[]args){
		int[]tmp = {11,4,13,20,32,44,59,61,71,75,86,88};
		System.out.println(count(tmp,567601));
	}
	public static long count(int[] numbers, int k){
		long prod;
		long numLower = 0;

		for(int i=1;i<numbers.length+1;i++){
			for(int j=0;j<numbers.length-i+1;j++){
				prod = 1;
				for(int l=j;l<j+i;l++){
					System.out.print(numbers[l] + " ");
					prod *= numbers[l];
					if(prod >= k){
						break;
					}
				}
				if(k > prod){
					System.out.print(" y");
					numLower ++;
				}
				System.out.println("");
			}
		}
		return numLower;
	}
}