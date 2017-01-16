//Nicholas Culmone
//Code to Win 2016

import java.util.*;

public class Ques1{
	public static void main(String[]args){
		int[] tmp = {2,0,1};
		finalPrice(tmp);
	}
	public static void finalPrice(int[] prices){
		int[] discount = new int[prices.length];
		int[] finalPrice = new int[prices.length];
		int current, total = 0;

		for(int i=0; i<prices.length-1; i++){
			current = prices[i];
			discount[i] = 0;
			for(int j=i+1;j<prices.length;j++){
				if(current >= prices[j] && prices[j] != 0){
					discount[i] = prices[j];
					break;
				}
			}
			finalPrice[i] = prices[i] - discount[i];
		}

		discount[prices.length - 1] = 0;
		finalPrice[prices.length - 1] = prices[prices.length- 1];

		for(int p : finalPrice) total += p;

		System.out.println(total);

		for(int i=0;i<discount.length;i++){
			if(discount[i] == 0){
				if(i == discount.length - 1) System.out.print(i);
				else System.out.print(i + " ");
			}
		}
	}
}