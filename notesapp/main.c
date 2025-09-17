#include <stdio.h>
#include <string.h>

int main(){
	size_t len = 0;
	char userfilename[20];
	char filename[20] = "data.txt";
	printf("1. View notes\n2. Add a note\n3. Remove a note\n4. Update a note\n\nEnter your choice number : ");
	int c = getchar();
	getchar();	
	
	switch(c){
	case '1':
		char filename[100];
		printf("Enter notes file name (leave blank for default) : ");
		fgets(filename, sizeof(filename), stdin);
		if(filename[0] == '\n') strcpy(filename,"defaultnotes.txt");
		FILE *filepointer = fopen(filename, "r");
		if(!strcmp(filename, "defaultnotes.txt") && filepointer == NULL)
			filepointer = fopen(filename, "w");
		if(filepointer == NULL){
			printf("Couldn't find a file by that name. Make sure to use the full name of the file along with the extension.\n");
			return 1;
		}
		char ch;
		while((ch = fgetc(filepointer)) != EOF)
			putchar(ch);
		printf("End of file '%s'\n", filename);
		break;			
	default:
		printf("Invalid choice.\n");
		break;	
	}	
	return 0;
}
