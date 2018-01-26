// priorityQ.java
// Matt Farias
// The interface for the Priority Queue

public interface priorityQ<T> {
	void enqueue(T item, int priority);
	
	void enqueue(T item);

	T dequeue();

	T peek();

	void display();

	int size();

	boolean isFull();

	boolean isRegular();

	boolean isEmpty();
}
