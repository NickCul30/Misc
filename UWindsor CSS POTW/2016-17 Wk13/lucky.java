// UWindsor CSS POTW Week 13 - Lucky Trees
// Nicholas Culmone

import java.util.*;
import java.awt.*;

public class lucky{
	public static void main(String[]args){
		BTree tree = new BTree();		
		Scanner kb = new Scanner(System.in);

		int l = kb.nextInt();
		kb.nextLine();

		for(int i=0;i<l;i++){
			String tmp = kb.nextLine();
			String[]vals = tmp.split(" ");
			tree = addVals(vals,tree);
		}

		int ans = getLucky(tree);

		if(ans == 0) System.out.print("not ");
		System.out.println("lucky");


	}

	public static int getLucky(BTree tree){
		return getLucky(tree.getRoot(),0);
	}

	public static int getLucky(BNode n, int tot){
		tot += n.getVal();

		if(n.getLeft() == null){
			if(tot == 13) return 1;
			return 0;
		}
		else{
			return getLucky(n.getLeft(),tot) + getLucky(n.getRight(),tot);
		}
	}

	public static BTree addVals(String[]vals, BTree tree){
		int hei = (int)(Math.log(vals.length) / Math.log(2));

		if(hei == 0){
			tree.setRoot(Integer.parseInt(vals[0]));
			return tree;
		}

		for(int i=0;i<vals.length;i++){
			int tmp = (int)Math.pow(2,hei-1), n = Integer.parseInt(vals[i]), iTmp = i;
			BNode spot = tree.getRoot();

			while(true){
				if(tmp <= iTmp){
					iTmp -= tmp;
					if(spot.getRight() == null){
						spot.setRight(new BNode(n,spot));
						break;
					}
					spot = spot.getRight();
				}
				else{
					if(spot.getLeft() == null){
						spot.setLeft(new BNode(n,spot));
						break;
					}
					spot = spot.getLeft();
				}
				tmp /= 2;
			}
		}
		return tree;
	}
}

class BTree{
	private BNode root;

	public BTree(){
		root = null;
	}

	public void setRoot(int v){
		root = new BNode(v,null);
	}
	public BNode getRoot(){
		return root;
	}

}

class BNode{
	private int val;
	private BNode left, right, parent;

	public BNode(int v, BNode p){
		val = v;
		parent = p;
		left = null;
		right = null;
	}

	public void setLeft(BNode n){
		left = n;
	}
	public void setRight(BNode n){
		right = n;
	}

	public BNode getLeft(){
		return left;
	}
	public BNode getRight(){
		return right;
	}
	public int getVal(){
		return val;
	}
}