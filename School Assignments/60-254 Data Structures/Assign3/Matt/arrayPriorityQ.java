// arrayPriorityQ.java
// Matt Farias
// An array implementation of a Priority Queue

public class arrayPriorityQ<T> implements priorityQ<T> {
	private int maxSize;
	private T[] queueArray;
	private int[] priArray;
	private int numItems;
	private int defaultPriority;

	// Constructor
	@SuppressWarnings("unchecked")
	public arrayPriorityQ(int size) {
		maxSize = size;
		queueArray = (T[]) new Object[maxSize];
		priArray = new int[maxSize];
		numItems = 0;
		defaultPriority = 5;
	}

	// Case when only the item is passed through
	public void enqueue(T item) {
		enqueue(item, defaultPriority);
	}

	// Adds an element in the entered spot in the queue
	public void enqueue(T item, int priority) {
		if (!isFull()) {
			int j;

			if (isEmpty()) {
				queueArray[numItems] = item;
				priArray[numItems++] = priority;
			}
			else {
				for (j = numItems - 1; j >= 0; j--) {
					if (priority >= priArray[j]) {
						queueArray[j + 1] = queueArray[j];
						priArray[j + 1] = priArray[j];
					}
					else {
						break;
					}
				}
				queueArray[j + 1] = item;
				priArray[j + 1] = priority;
				numItems++;
			}
		}
	}

	// Removes the front element in the queue and returns it
	public T dequeue() {
		if (!isEmpty()) {
			return queueArray[--numItems];
		}
		return null;
	}

	// Returns the front element in the queue
	// Nick: return null when there are no elements in the queue
	public T peek() {
		if(!isEmpty()) {
			return queueArray[numItems - 1];
		}
		return null;
	}

	// Returns the size of the queue
	public int size() {
		return numItems;
	}

	// Checks if all the nodes have the same priority
	// Nick: include case where there is only one item in the queue
	public boolean isRegular() {
		if (!isEmpty()) {
			if (numItems == 1) {
				return true;
			}
			else {
				return (priArray[0] == priArray[numItems - 1]);
			}
		}
		return true;
	}

	// Checks if the queue is empty and returns the correspondng boolean value
	public boolean isEmpty() {
		return (numItems == 0);
	}

	// Checks if the queue is full and returns the corresponding boolean value.
	public boolean isFull() {
		return (numItems == maxSize);
	}

	// Displays all of the nodes and their priority to STDOUT
	public void display() {
		if(!isEmpty()) {
			for (int i = numItems - 1; i >= 0 && !isEmpty(); i--) {
				System.out.println("Element : " + queueArray[i] + " Priority: " + priArray[i]);
			}
		}
	}
}