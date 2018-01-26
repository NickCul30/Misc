// LList.java
// Nicholas Culmone
// A General Linked List ADT

public class LList<T>{
	private Node<T> head;
	private int length;

	// Constructor
	public LList(){
		head = null;
		length = 0;
	}

	// Getters
	public Node<T> head(){
		return head;
	}
	public int length(){
		return length;
	}

	// Adds a node in the position n
	public void add(Node<T> node, int n){
		if(n > length || n < 0) return;
		length ++;

		Node<T> cur = head;
		if(n == 0){
			node.setNext(head);
			head = node;
			return;
		}

		for(int i=1;i<n;i++){
			cur = cur.next();
		}

		node.setNext(cur.next());
		cur.setNext(node);
	}

	// Removes a node from position n
	public void remove(int n){
		if(n >= length || n < 0) return;
		length --;

		Node<T> cur = head, prev = null;
		for(int i=0;i<n;i++){
			prev = cur;
			cur = cur.next();
		}

		if(cur == head){
			head = cur.next();
			cur = null;
		}
		else{
			prev.setNext(cur.next());
			cur = null;
		}
	}

	// Returns the values of the nodes in a String
	public String toString(){
		String str = "";
		Node<T> cur = head;

		for(int i=0;i<length;i++){
			str = str + "\n" + cur.toString();
			cur = cur.next();
		}
		return str;
	}
}

class Node<T>{
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