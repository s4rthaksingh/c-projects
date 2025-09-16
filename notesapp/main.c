#include <stdio.h>
#include <string.h>

int main(){
	size_t len = 0;
	char c;
	char userfilename[20];
	char filename[20] = "data.txt";
	printf("Enter the filename you want to store text in (leave blank for 'data.txt') : ");
	scanf("%s", userfilename);
	if(strlen(userfilename) > 3)
		strcpy(filename, userfilename);
	FILE *fptr = fopen(filename, "a");
	printf("\nEnter a new note, and press CTRL+D to end : ");
	fprintf(fptr, "- ");
	while((c = getchar()) != EOF){
		fputc(c,fptr);
	}
	printf("\nSuccessfully written data to file : %s\n", filename);
	fclose(fptr);
	return 0;
};
