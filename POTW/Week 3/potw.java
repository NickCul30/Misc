//POTW Week 3
//Nicholas Culmone

import java.util.*;
import java.awt.*;

public class potw{
	public static void main(String[]args){
		ArrayList<String[]>docs = new ArrayList<String[]>();

		Scanner kb = new Scanner(System.in);

		int n = kb.nextInt(); //get n
		kb.nextLine();

		for(int i=0;i<n;i++){ //get docs + put in arraylist of String[]
			String s = kb.nextLine();

			String[]words = s.split(" ");
			docs.add(words);
		}

		String term = kb.nextLine(); //get term
		double idfDocs = idf(term,docs);
		int c = 1;

		for(String[]doc : docs){ //perform formula & print
			double ans = tf(term,doc) * idfDocs;

			System.out.println(c + " " + ans);
			c++;
		}
	}

	//tf formula
	public static double tf(String term, String[] doc){
		double tot = 0;

		for(String s : doc){
			if(term.equals(s)) tot ++;
		}
		return tot;
	}

	//idf formula
	public static double idf(String term, ArrayList<String[]>docs){
		int count = 0;

		for(String[]doc : docs){
			if(Arrays.asList(doc).contains(term)) count ++;
		}

		return Math.log10(docs.size() / (double)(count));
	}
}