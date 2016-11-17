//potw.java
//Nicholas Culmone
//Week 4

import java.util.*;
import java.awt.*;

public class potw{
	public static void main(String[]args){
		Scanner kb = new Scanner(System.in);
		ArrayList<ArrayList<String>>squads = new ArrayList<ArrayList<String>>();

		int fShips = kb.nextInt();
		kb.nextLine();

		for(int i=0;i<fShips;i++){
			String fShip = kb.nextLine();
			String[]names = fShip.split(" ");
			boolean added = false;
			ArrayList<String> orig = new ArrayList<String>();

			for(ArrayList<String> s : squads){
				if((s.contains(names[0]) || s.contains(names[1])) && !added){
					s.add(names[0]);
					s.add(names[1]);
					orig = s;
					added = true;
				}
				else if(s.contains(names[0]) || s.contains(names[1])){
					for(String n : s){
						orig.add(n);
					}
					squads.remove(s);
				}
			}
			if(!added){
				ArrayList<String>tmp = new ArrayList<String>();
				tmp.add(names[0]);
				tmp.add(names[1]);
				squads.add(tmp);
			}
		}

		ArrayList<String[]> potShips = new ArrayList<String[]>();
		int findShips = kb.nextInt();
		kb.nextLine();

		for (int i=0;i<findShips;i++){
			String potShip = kb.nextLine();
			String[]names = potShip.split(" ");
			potShips.add(names);
		}

		for(String[] names : potShips){
			boolean nameFound = false;

			for(ArrayList<String> s : squads){
				if(s.contains(names[0]) && s.contains(names[1])){
					System.out.println("yes");
					nameFound = true;
					break;
				}
				else if(s.contains(names[0]) || s.contains(names[1])){
					System.out.println("no");
					nameFound = true;
					break;
				}
			}
			if(!nameFound) System.out.println("no");
		}
	}
}