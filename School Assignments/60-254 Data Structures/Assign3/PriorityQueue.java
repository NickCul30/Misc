// PriorityQueue.java
// Nicholas Culmone
// A general Priority Queue ADT implemented using a Linked List

public class PriorityQueue<T>{
	private LList<T> nodes;
	private Node<T> front;
	private Node<T> rear;

	// Constructor
	// Matt: make front and rear variables for PriorityQueue, so you don't have to
	// reference the LList every time
	public PriorityQueue(){
		nodes = new LList<T>();
		front = null;
		rear = null;
	}

	// Returns the size of the Priority Queue
	// Matt: instead of keeping a size variable in PriorityQueue,
	// just use the one that's already made in LList
	public int size(){
		return nodes.length();
	}

	// Adds a value to the queue
	public void enqueue(T val, int pri){
		if(pri < 5) pri = 5;
		Node<T> n = new Node<T>(val, pri);

		if(size() == 0){
			nodes.add(n,0);
			front = n;
			rear = n;
			return;
		}
		
		Node<T> cur = front;
		int c;
		for(c=0;c<size();c++){
			if(n.pri() > cur.pri()){
				break;
			}
			cur = cur.next();
		}
		nodes.add(n,c);

		if(n.next() == front) front = n;
		if(rear.next() == n) rear = n;
	}
	// Case when priority isn't specified
	// Matt: make two methods, one for just val, and one for val and
	// entered priority
	public void enqueue(T val){
		enqueue(val, 5);
	}

	// Removes the front element from the queue
	public Node<T> dequeue(){
		if(size() <= 0) return null;
		Node<T> tmp = front;

		front = front.next();
		if(front == null) rear = null;

		nodes.remove(0);
		return tmp;
	}

	// Looks at the front element in the queue
	public Node<T> peek(){
		return front;
	}

	// Checks if all the nodes have the same priority
	// Matt: Check only the front and end nodes, instead of iterating through
	// every node, as the Queue is sorted by priority.
	public boolean isRegular(){
		if(size() == 0 || front.pri() == rear.pri()) return true;
		return false;
	}

	// Checks if the queue is empty and returns the correspondng boolean value
	public boolean isEmpty(){
		if(size() == 0) return true;
		return false;
	}

	// Checks if the queue is full and returns the corresponding boolean value.
	// Matt: However, since this is a Linked List implementation, the queue is never full
	public boolean isFull(){
		return false;
	}

	// Returns all of the nodes and their priority in a String
	public String display(){
		String str = nodes.toString();
		return str;
	}
}