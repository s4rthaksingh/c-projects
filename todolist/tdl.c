#include <stdio.h>

void main(){
	FILE *fptr;
	int task;
	printf("What do you want to do today?\n\n1. Add a new task\n2. View tasks\n3. Clear list\n\nType the respective number : ");
	scanf(" %d",&task);
	switch(task){
	case 1:
		char newtask[50];
		printf("Enter new task : ");
		while (getchar() != '\n');
		fgets(newtask,50,stdin);
		fptr = fopen("todos.txt","a");
		fprintf(fptr,"%s",newtask);
	       	fclose(fptr);	
		printf("Added that task to your to-do list\n");
		break;
	case 2:
		fptr = fopen("todos.txt","r");
		char ch;
		while((ch=fgetc(fptr)) != EOF) putchar(ch);
		fclose(fptr);
		break;
	case 3:
		char *filename = "todos.txt";
		remove(filename);
		printf("Cleared your list.\n");
		break;
	}

}
