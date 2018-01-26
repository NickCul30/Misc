// Node.java
// Nicholas Culmone
// A general node class that works for a Linked List and
// Priority Queue ADTs, since it contains a general value,
// a Priority and a next node.

public class Node<T>{
	private T val;
	private int pri;
	private Node<T> next;

	// Constructor
	public Node(T val, int pri){
		this.val = val;
		this.pri = pri;
		next = null;
	}

	// Setters
	public void setPri(int p){
		pri = p;
	}
	public void setNext(Node<T> n){
		next = n;
	}

	// Getters
	// Matt: change the names from getX() to just X()
	public T val(){
		return val;
	}
	public int pri(){
		return pri;
	}
	public Node<T> next(){
		return next;
	}

	// Returns the value and priority of the node in a String
	public String toString(){
		return '"' + val.toString() + "\", pri: " + pri;
	}
}