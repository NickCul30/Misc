// Queue.java
// Nicholas Culmone
// A general queue ADT using a ArrayList implementation

import java.util.*;

public class Queue<T>{
	private ArrayList<T> nodes;
	private T start;
	private T end;

	// Constructor
	public Queue(){
		nodes = new ArrayList<T>();
		start = null;
		end = null;
	}

	// Adds an element to the end of the queue
	public void enqueue(T node){
		nodes.add(node);

		if(nodes.size() == 1){
			start = nodes.get(0);
			end = nodes.get(0);
		}
		else{
			end = nodes.get(nodes.size() - 1);
		}
	}

	// Removes and returns the front element
	public T dequeue(){
		if(nodes.size() == 0) return null;

		T node = start;
		nodes.remove(0);

		if(nodes.size() == 0){
			start = null;
			end = null;
		}
		else{
			start = nodes.get(0);
		}

		return node;
	}

	// Returns the size of the queue
	public int size(){
		return nodes.size();
	}

	public String toString(){
		String str = "";
		for(T node : nodes){
			str = str + node.toString() + " ";
		}
		return str;
	}
}