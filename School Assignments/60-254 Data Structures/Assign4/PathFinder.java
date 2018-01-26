// PathFinder.java
// Nicholas Culmone
// Applies a breadth first search in order to find the shortest path between
// two rooms, if possible.

import java.util.*;
import java.io.*;

public class PathFinder{
	public static void main(String[]args) throws IOException{

		Graph<Integer> house = new Graph<Integer>();

		// Reads the header of the file
		Scanner in = new Scanner(new BufferedReader(new FileReader("test.txt")));

		//in.nextLine();	// Uncomment this line if the file contains the "Input File" header

		String tmpS = in.nextLine();
		String tmpSt = in.nextLine();
		String tmpE = in.nextLine();

		int size = Integer.parseInt(tmpS);
		int start = Integer.parseInt(tmpSt);
		int end = Integer.parseInt(tmpE);

		for(int i=0;i<size;i++) house.add(i);

		// Reads the grid from the input file and
		// constructs the corresponding graph.
		for(int i=0;i<size;i++){
			String tmp = in.nextLine();
			String[] stats = tmp.split(",");

			for(int j=0;j<size;j++){

				if(stats[j].equals("1")){
					house.addConnect(i,j);
				}
			}
		}

		Queue<Node<Integer>> q = new Queue<Node<Integer>>();
		boolean[] visited = new boolean[size];
		int[] prev = new int[size];
		for(int i=0;i<size;i++) prev[i] = -1;

		q.enqueue(house.get(start));

		// Uses breadth first search to traverse through the graph.
		while(q.size() > 0){
			Node<Integer> v = q.dequeue();

			if(visited[v.getData()] == false){
				visited[v.getData()] = true;

				for(Node<Integer> w : v.getConnect()){
					if(visited[w.getData()] == false){
						q.enqueue(w);

						// When a node is found, for the first time only, its previous
						// node is set to the current node being explored
						if(prev[w.getData()] == -1) prev[w.getData()] = v.getData();
					}
				}
			}
		}

		ArrayList<Integer> shortPath = new ArrayList<Integer>();

		// Prints out the results of the search
		if(start == end) System.out.println(start);
		else if(prev[end] == -1) System.out.println("No path possible.");
		else{
			int spot = end;
			shortPath.add(end);
			while(prev[spot] != -1){
				shortPath.add(prev[spot]);
				spot = prev[spot];
			}
			
			for(int i=shortPath.size()-1;i>=1;i--){
				System.out.print(shortPath.get(i) + ", ");
			}
			System.out.println(shortPath.get(0));
		}
	}
}