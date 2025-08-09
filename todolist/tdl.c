#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main(){
	FILE *fptr;
	int task;
	int i;
	char c;
	printf("What do you want to do today?\n\n1. Add a new task\n2. View tasks\n3. Delete a task\n4. Clear list\n\nType the respective number : ");
	scanf(" %d",&task);
	if(task != 1){
		fptr=fopen("todos.txt","r");
		if(fptr == NULL || (c = fgetc(fptr)) == EOF){
			printf("You do not have any todos.\n");
			exit(1);
		}
		fclose(fptr);
		
	}
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
		int lasti = 0;
		i = 1;
		while((ch=fgetc(fptr)) != EOF){
			if(i>lasti){
				printf("\n%d. ",i);
				lasti = i;
			}
			if(ch == '\n')
				{
					i++;
				}
		
		putchar(ch);
		
		};
		fclose(fptr);
		putchar('\n');
		break;
	case 3:
		int todelete;
		printf("Enter task # you want to delete : ");
		scanf("%d",&todelete);
		
		char buffer[50];
		i=1;
		char newlist[5000] = "\0";
		fptr = fopen("todos.txt", "r");
		while(fgets(buffer, sizeof(buffer), fptr) != NULL){
		if(i==todelete)
			i++;	
		else{
			strcat(newlist,buffer);
			i++;
		}}
		fclose(fptr);
		fptr = fopen("todos.txt","w");
		fprintf(fptr,"%s",newlist);
		fclose(fptr);
		printf("Succesfully deleted task #%d\n",todelete);
		break;
	case 4:
		char *filename = "todos.txt";   	
		remove(filename);
                printf("Cleared your list.\n");
		break;
	}
}
