#include <stdio.h>
#include <string.h>

typedef struct {
	char title[100];
	char author[20];
	double price;	
} Book;

int main(){
	char title[100], author[20];
	double price;
	printf("Enter book title : ");
	fgets(title, 100, stdin);
	printf("Enter author name : ");
	fgets(author, 20, stdin);
	printf("Enter book price : ");
	scanf("%lf",&price);

	title[strcspn(title, "\n")] = '\0';
	author[strcspn(author, "\n")] = '\0';

	Book myBook;
	strcpy(myBook.title, title);
	strcpy(myBook.author, author);
	myBook.price = price;
	printf("%s\n%s\n%lf\n", myBook.title, myBook.author, myBook.price);
}
