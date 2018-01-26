
public class priorityQTester {

	public static void main(String[] args) {
		priorityQ<String> myQ = new arrayPriorityQ<String>(10);

		myQ.enqueue("yo");
		myQ.enqueue("hey", 10);
		myQ.enqueue("hi", 6);
		myQ.enqueue("word", 8);
		myQ.enqueue("test", 9);
		myQ.display();


	}

}
