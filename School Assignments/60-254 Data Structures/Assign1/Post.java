// Post.java
// Nicholas Culmone
// The Post object used to store all the Facebook posts from the main program

// INCLUDE SECTION
import java.util.*;

public class Post{

	// Private variables
	private int likes;
	private int comments;
	private String name;
	private int size;
	private int date;
	private Post next;

	// Constructor
	public Post(int l, int c, String n, int s, int d){
		likes = l;
		comments = c;
		name = n;
		size = s;
		date = d;
		next = null;
	}
	
	// Getters
	public int get(int n){
		switch(n){
			case 0: return likes;
			case 1: return comments;
			case 2: return size;
			case 3: return date;
			default: return 0;
		}
	}
	public int getLikes(){
		return likes;
	}
	public int getComments(){
		return comments;
	}
	public String getName(){
		return name;
	}
	public int getSize(){
		return size;
	}
	public int getDate(){
		return date;
	}
	public Post next(){
		return next;
	}

	// Setter
	public void setNext(Post n){
		next = n;
	}

	// Overrides the toString method to make display all the Post's attributes when printing
	public String toString(){
		return ("Likes: " + likes + "\nComments: " + comments + "\nUsername: " + name + "\nSize: " + size + "\nDate Posted: " + date);
	}
}
