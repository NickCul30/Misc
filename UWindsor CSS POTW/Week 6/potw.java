//potw.java
//Nicholas Culmone

import java.util.*;

public class potw{
	public static void main(String[]args){

		Scanner kb = new Scanner(System.in);
		int progs = kb.nextInt();
		kb.nextLine();
		String[]ids = kb.nextLine().split(" ");

		ArrayList<Integer>soFar = new ArrayList<Integer>();

		for(int i=0;i<progs;i++){
			int idTmp = Integer.parseInt(ids[i]);
			if(soFar.contains(idTmp)){
				System.out.println("" + idTmp);
				break;
			}
			else{
				soFar.add(idTmp);
			}
		}
	}
}