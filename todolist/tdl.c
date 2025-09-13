#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main(){
	FILE *fptr;
	int task;
	int i;
	char c;
	printf("What do you want to do today?\n\n1. Add a new task\n2. View tasks\n3. Edit a task\n4. Delete a task\n5. Clear list\n\nType the respective number : ");
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
		char new[256];
		printf("Enter new task : ");
		while (getchar() != '\n');
		fgets(new,256,stdin);
		fptr = fopen("todos.txt","a");
		fprintf(fptr,"%s",new);
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
		int toedit;                           
		printf("Enter task # you want to edit : ");       
		scanf("%d",&toedit);
		char buff[256];
		char newtask[256];
		i=1;
		char newl[25600] = "\0";    
		fptr = fopen("todos.txt", "r");     
		while(fgets(buff, sizeof(buff), fptr) != NULL){
                if(i==toedit){
			printf("Enter the edited task : ");
			while (getchar() != '\n');
			fgets(newtask,256,stdin);
			strcat(newl,newtask);
			i++;
		}
                else{
                        strcat(newl,buff);
                        i++;
                }}
                fclose(fptr);
                fptr = fopen("todos.txt","w");
                fprintf(fptr,"%s",newl);
                fclose(fptr);
                printf("Succesfully edited task #%d\n",toedit);
                break;
	case 4:
		int todelete;
		printf("Enter task # you want to delete : ");
		scanf("%d",&todelete);
		
		char buffer[256];
		i=1;
		char newlist[25600] = "\0";
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
	case 5:
		char *filename = "todos.txt";   	
		remove(filename);
                printf("Cleared your list.\n");
		break;
	}
}
