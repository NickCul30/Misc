// Stack.java
// Nicholas Culmone
// A General Stack ADT

import java.util.*;

public class Stack<T>{
	private Object[] nodes;
	private T top;
	private int size;
	private int maxSize;

	// Constructor
	public Stack(){
		maxSize = 100;
		nodes = new Object[maxSize];
		top = null;
		size = 0;
	}

	public T getTop(){
		return top;
	}

	public void push(T node){
		nodes[size] = node;
		top = (T)nodes[size];
		size ++;
	}
	public T pop(){
		T tmp = top;

		if(size > 0){
			nodes[size - 1] = null;
			size --;

			if(size > 0) top = (T)nodes[size - 1];
			else top = null;
		}
		return tmp;
	}

	@Override
	public String toString(){
		String val = "";

		for(int i=0;i<size;i++){
			val += nodes[i] + " ";
		}
		return val;
	}
}