// Graph.java
// Nicholas Culmone
// A General Graph ADT using an ArrayList implementation

import java.util.*;

public class Graph<T>{
	private ArrayList<Node<T>> nodes;
	private int size;

	// Constructor
	public Graph(){
		nodes = new ArrayList<Node<T>>();
		size = 0;
	}

	// Adds a new Node to the graph
	public void add(T data){
		nodes.add(new Node<T>(data));
		size ++;
	}

	// Adds a one-way connection between two nodes
	public void addConnect(int s, int e){
		nodes.get(s).add(nodes.get(e));
	}

	// Getter
	public Node<T> get(int n){
		return nodes.get(n);
	}

	public String toString(){
		String str = "";
		for(Node<T> n : nodes){
			str = str + n.toString() + "\n";
		}
		return str;
	}
}