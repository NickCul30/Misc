//q2.c
//write a program that takes in the item num, unit price
//and the date and returns a nice looking table

#include <stdio.h>

int main(){
	int itemNo, month, day, year;
	float price;

	//prompts the user and then gets their input
	printf("Enter item number: ");
	scanf("%d", &itemNo);
	printf("Enter unit price: ");
	scanf("%f", &price);
	printf("Enter purchase date: ");
	scanf("%d/%d/%d", &month, &day, &year);

	//prints out the table
	printf("\n\nItem 	Unit 		Purchase");
	printf("\n 	Price 		Date");
	printf("\n----	------		----------");
	printf("\n%-d	$%7.2f	%-d/%-d/%-d", itemNo, price, month, day, year);

	return 0;
}