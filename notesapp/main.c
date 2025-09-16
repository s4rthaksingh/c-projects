#include <stdio.h>

int main(){
	size_t len = 0;
	FILE *fptr = fopen("data.txt", "w");
	char c;
	printf("Enter a new note, and press CTRL+D to end : ");
	while((c = getchar()) != EOF){
		fputc(c,fptr);
	}
	printf("\nSuccessfully written data to file : data.txt\n");
	fclose(fptr);
	return 0;
};
