#include <stdio.h>

int main(){
	size_t len = 0;
	FILE *fptr = fopen("data.bin", "wb");
	char *line = NULL;
	printf("> ");
	ssize_t read = getline(&line, &len, stdin);
	fprintf(fptr,"%s", line);
	fclose(fptr);
	return 0;
};
