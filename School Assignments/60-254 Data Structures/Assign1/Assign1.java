// Assign1.java
// Nicholas Culmone
// A computer program that allows the user to store information about Facebook posts.
// Each post contains the number of likes and comments, the username of the poster,
// the size of the post, and the date the post was made. In order to implement a linked
// list data structure, the post also stores the next post in the list.

// The user is able to display the current posts, search for a post, display
// the total number of posts, make a new post, delete one or all the posts,
// and sort the posts based on a given attribute.

// INCLUDE SECTION
import java.util.*;

// MAIN PROGRAM FOLLOWS
public class Assign1{
	public static void main(String[]args){

		Scanner kb = new Scanner(System.in);

		Object num = new ArrayList<String>();
		//num.add("YO");
		System.out.println(num);

		// Variable init
		String user = "1", user2;
		int user3;
		Post head = null;
		Post cur;
		Post prev;

		// Escapes when the user enters "7"
		while(!user.equals("7")){

			// Prompts user and gets entry
			space();
			System.out.println(num);
			System.out.print("\n0. Display Posts\n1. Search for a Post\n2. Display current number of stored posts\n3. Store the data of a new post\n4. Delete a Post\n5. Delete all posts\n6. Sort Posts\n7. Exit\n\nEnter Selection: ");
			user = kb.nextLine();

			space();

			switch(user){

				// Displays all the posts
				case "0":
					cur = head;
					while(cur != null){
						System.out.println("\n" + cur);
						cur = cur.next();
					}
					enter();
					break;

				// Searches for a post
				case "1":
					// Prompts user and gets input
					System.out.print("\nSearch by:\n0. Number of Likes\n1. Number of Comments\n2. Number of Characters\n3. Date\n4. Username\n\nEnter which criteria you want to search by: ");
					user3 = kb.nextInt();
					kb.nextLine();

					space();

					switch(user3){
						case 0: case 1: case 2: case 3:
							search(head, user3);
							break;
						case 4:
							cur = head;
							int val;
							boolean flag = false;
							System.out.print("Enter Value: ");
							String n = kb.nextLine();

							while(cur != null){
								if(cur.getName().equals(n)){
									System.out.println(cur);
									flag = true;
									break;
								}
								cur = cur.next();
							}
							if(!flag) System.out.println("Post not found.");
							break;
						default: space(); System.out.println("Invalid value."); break;
					}

					enter();
					break;

				// Counts the number of saved posts
				case "2":
					int count = 0;
					cur = head;
					while(cur != null){
						count ++;
						cur = cur.next();
					}
					System.out.println("There are " + count + " saved posts");
					enter();
					break;

				// Stores the data of a new post
				case "3":
					// Prompts the user and gets input
					System.out.print("Enter Number of Likes: ");
					int likes = kb.nextInt();
					kb.nextLine();

					System.out.print("Enter Number of Comments: ");
					int comments = kb.nextInt();
					kb.nextLine();

					System.out.print("Enter Username: ");
					String name = kb.nextLine();

					System.out.print("Enter Number of Characters: ");
					int size = kb.nextInt();
					kb.nextLine();

					System.out.print("Enter Date (YYYYMMDD): ");
					int date = kb.nextInt();
					kb.nextLine();

					// Tests to see that all the input data is valid, then saves  the post
					if(likes >=0 && comments >= 0 && !name.equals("") && size >= 0 && date > 9999999 && date < 100000000){
						Post tmp = new Post(likes, comments, name, size, date);
						if(head == null){
							head = tmp;
						}
						else{
							cur = head;
							while(cur.next() != null){
								cur = cur.next();
							}
							cur.setNext(tmp);
						}
						System.out.println("Post added.");
					}
					else{
						System.out.println("Invalid post.");
					}
					enter();
					break;

				// Delete a post
				case "4":
					// Prompts user and gets input
					System.out.print("\nDelete by:\n0. Post Date\n1. Post Author\n\nEnter which criteria you want to delete by: ");
					user2 = kb.nextLine();

					cur = head;
					prev = null;
					boolean deleted = false;

					switch(user2){
						// Case when user wants to delete by date
						case "0":
							System.out.print("Enter Date: ");
							int val = kb.nextInt();
							kb.nextLine();

							while(cur != null){
								deleted = false;

								if(val == cur.getDate()){
									deleted = true;

									if(cur == head){
										head = cur.next();
										cur = head;
									}
									else{
										prev.setNext(cur.next());
										cur = cur.next();
									}
								}
								if(deleted == false){
									prev = cur;
									cur = cur.next();
								}
							}
							break;

						// Case when user wants to delete by author
						case "1":
							System.out.print("Enter Author: ");
							String val2 = kb.nextLine();

							while(cur != null){
								deleted = false;

								if(cur.getName().equals(val2)){
									deleted = true;

									if(cur == head){
										head = cur.next();
										cur = head;
									}
									else{
										prev.setNext(cur.next());
										cur = cur.next();
									}
								}
								if(deleted == false){
									prev = cur;
									cur = cur.next();
								}
							}
							break;

						// Invalid input
						default:
							System.out.println("Invalid value.");
							enter();
							break;
					}
					break;

				// Clears all the posts in the LList
				case "5":
					head = null;
					System.out.println("Posts cleared.");
					enter();
					break;

				// Sorts the posts in the LList
				case "6":
					// Prompts user and gets input
					System.out.print("\nSort by\n0. Number of Likes\n1. Number of Comments\n2. Number of Characters\n3. Date\n\nEnter which criteria you want to sort by: ");
					user3 = kb.nextInt();
					kb.nextLine();

					switch(user3){
						case 0: case 1: case 2: case 3:
							head = sort(head, user3);
							break;
						// Invalid input
						default:
							System.out.println("Invalid value.");
							enter();
							break;
					}

					break;

				// Exits the program
				case "7":
					break;

				// Invalid input
				default:
					space();
					System.out.println("Invalid value.");
					enter();
			}
		}

	}

	//FUNCTION DEFINITIONS FOLLOW

	/*  Sorts the posts in the LList given the head and the index of the
		values that are to be sorted by. Uses the bubble sort method
		Input: Post head, int attr
		Output: The head of the sorted LList
	*/
	public static Post sort(Post head, int attr){
		// Edge cases when the LList's size is 0 or 1
		if(head == null || head.next() == null) return head;

		boolean sorting = true;

		while(sorting){
			sorting = false;
			Post prev = null, cur = head, next = head.next();
			for(int i=0; next != null; i++){
				if(cur.get(attr) < next.get(attr)){
					sorting = true;

					// Swaps the positions of the elements in both the LList
				    if(prev == null){
				    	head = next;
				    	cur.setNext(next.next());
				    	next.setNext(cur);
				    }
				    else{
				    	prev.setNext(next);
				    	cur.setNext(next.next());
				    	next.setNext(cur);
				    }
				    Post tmp = next;
				    next = cur;
				    cur = tmp;
				}

				prev = cur;
				cur = next;
				next = next.next();
			}
		}
		return head;
	}

	/*	Searches for the first instance of a Post based on a user input
		Input: Post cur (the head of the LList), int user (what the user wants to search by)
		Output: Prints the Post that is found (or that the post wasn't found)
	*/
	public static void search(Post cur, int user){
		Scanner kb = new Scanner(System.in);

		int val;
		boolean flag = false;

		System.out.print("Enter Value: ");
		val = kb.nextInt();
		kb.nextLine();

		while(cur != null){
			if(cur.get(user) == val){
				System.out.println(cur);
				flag = true;
				break;
			}
			cur = cur.next();
		}
		if(!flag) System.out.println("Post not found.");
	}

	/*	Prints a large space
		Input: n/a
		Output: 61 Empty lines to stdout
	*/
	public static void space(){
		for(int i=0;i<61;i++){
			System.out.println("");
		}
	}

	/*	Prompts the user to press enter to continue
		Input: n/a
		Output: n/a
	*/
	public static void enter(){
		Scanner kb = new Scanner(System.in);
		System.out.println("\n\nPress Enter to continue...");
		kb.nextLine();
	}
}
