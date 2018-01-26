// Lab9.c
// Nicholas Culmone
// Manipulate linked list structures by defining functions
// in order to do so.

// LIBRARY PACKAGES INCLUDED BELOW
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// STRUCT DEFINITIONS FOLLOW
struct student {
   int ID;
   char name[40];
   struct student *next;
};
typedef struct student Student;

// FUNCTION PROTOTYPE STATEMENTS FOLLOW
int getChoice();                        // Gets input from the user from stdin
Student *addToList(Student *List);      // Adds a student to the end of the linked list
void printList(Student *List);          // Prints the linked list
void printListRR(Student *List);        // Prints the linked list in reverse order using recursion
void searchList(Student *List);         // Searches for a student given an ID from the user

// MAIN PROGREAM FOLLOWS
int main() {
    int choice = 0;
    Student *SLIST = NULL;

    choice = getChoice();

    while(choice >= 0) {
        switch(choice) {
            case 0 : printf("Bye...\n"); exit(0);
            case 1 : SLIST = addToList(SLIST); break;
            case 2 : printList(SLIST); break;
            case 3 : printListRR(SLIST); break;
            case 4 : searchList(SLIST); break;
            default: printf("That is not a valid choice\n");
        }
        choice = getChoice();
    }

    if(SLIST) free(SLIST);
    return 0;
}

// FUNCTION DEFINITIONS FOLLOW

/*  Gets input from the user from stdin
    Output: int (user input)
*/
int getChoice() {
    int choice = 0;

    printf("\n****** MENU ******\n");
    printf("1. Add new student to list.\n");
    printf("2. Print the student list, beginning to end.\n");
    printf("3. Recursively print the student list from the end.\n");
    printf("4. Search the list for a student.\n");
    printf("0. Quit.\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    return choice;
}


/*  Adds a new student to the end of the linked list after given 
    input from the user for the credentials of this student
    Input: Student *List (head of LList)
    Output: Student *List (head of updated LList)
*/
Student *addToList(Student *List){
    Student *tmp = malloc(sizeof(Student));
    tmp -> next = NULL;
    char name [40];
    int ID;

    printf("Enter Name: ");
    scanf("\n%[^\n]", name);
    printf("Enter ID: ");
    scanf("%d", &ID);

    strcpy(tmp -> name, name);
    tmp -> ID = ID;

    if(!List) return tmp;

    Student *cur = List;

    while(cur->next){
        cur = cur->next;
    }
    cur->next = tmp;
    return List;
}

/*  Prints the LList
    Input: Student *List (head of list)
*/
void printList(Student *List){
    Student *ptr = List;

    while(ptr){
        printf("%d %s\n", ptr->ID, ptr->name);
        ptr = ptr->next;
    }
}

/*  Prints the LList in reverse order using recursion
    Input: Student *List (head of LList)
*/
void printListRR(Student *List){
    if(!List) return;
    char name[40];
    strcpy(name, List->name);
    int id = List->ID;

    printListRR(List->next);
    printf("%d %s\n", id, name);
    return;
}

/*  Traverses through the LList and tries to find a user entered ID
    Input: Student *List
*/
void searchList(Student *List){
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);

    while(List){
        if(List->ID == id){
            printf("%d %s\n", List->ID, List->name);
            return;
        }
        List = List->next;
    }
    printf("ID %d not found.\n", id);
}