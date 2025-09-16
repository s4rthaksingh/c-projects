#include <stdio.h>

int main(){
	size_t len = 0;
	FILE *fptr = fopen("data.txt", "a");
	char c;
	printf("Enter a new note, and press CTRL+D to end : ");
	fprintf(fptr, "- ");
	while((c = getchar()) != EOF){
		fputc(c,fptr);
	}
	printf("\nSuccessfully written data to file : data.txt\n");
	fclose(fptr);
	return 0;
};
