// Tree Age
// Nicholas Culmone

import java.util.*;
import java.awt.*;

public class Solution5{
	public static ArrayList<Point>tmp = new ArrayList<Point>();

	public static void main(String[]args){
		Scanner kb = new Scanner(System.in);
		int n = kb.nextInt();
		kb.nextLine();

		char[][]tree = new char[n][n];
		boolean[][]isRing = new boolean[n][n];

		for(int i=0;i<n;i++){
			String tmp = kb.nextLine();
			tree[i] = tmp.toCharArray();
		}

		int count = 0;

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(tree[i][j] == 'x' && isRing[i][j] == false){
					findConnected(tree,i,j);
					count ++;
					for(Point p : tmp){
						isRing[p.x][p.y] = true;
					}
					tmp.clear();
				}
			}
		}

		System.out.println("" + count);
	}

	public static void findConnected(char[][]tree, int i, int j){
		tmp.add(new Point(i,j));
		if(i > 0 && !tmp.contains(new Point(i-1,j)) && tree[i-1][j] == 'x'){
			findConnected(tree,i-1,j);
		}
		if(j > 0 && !tmp.contains(new Point(i,j-1)) && tree[i][j-1] == 'x'){
			findConnected(tree,i,j-1);
		}
		if(i < tree[i].length-1 && !tmp.contains(new Point(i+1,j)) && tree[i+1][j] == 'x'){
			findConnected(tree,i+1,j);
		}
		if(j < tree[i].length-1 && !tmp.contains(new Point(i,j+1)) && tree[i][j+1] == 'x'){
			findConnected(tree,i,j+1);
		}
	}	
}