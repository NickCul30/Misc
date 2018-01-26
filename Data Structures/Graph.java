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

class Node<T>{
	private ArrayList<Node<T>> connect;
	private T data;

	// Constructor
	public Node(T d){
		connect = new ArrayList<Node<T>>();
		data = d;
	}

	// Adds a connection to the node
	public void add(Node<T> n){
		connect.add(n);
	}

	// Getters
	public T getData(){
		return data;
	}
	public ArrayList<Node<T>> getConnect(){
		return connect;
	}


	public String toString(){
		String str = data.toString() + ": ";
		for(Node<T> n : connect){
			str = str + n.getData().toString() + " ";
		}
		return str;
	}

	public boolean equals(Node<T> other){
		return true;
	}
}