// Node.java
// Nicholas Culmone
// A general Node ADT used for constructing graphs

import java.util.*;

public class Node<T>{
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