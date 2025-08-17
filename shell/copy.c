#include <stdio.h>

int main(int argc, char *argv[]){
	if(argc != 3) {
		printf("Usage: ./copy <source.txt> <target.txt>\n");
		return 1;
	}

	char *src = argv[1];	
	char *dest = argv[2];

	FILE *srcfile = fopen(src, "r");
	if(!srcfile){
		perror("Error opening source file");
		return 1;
	}
	FILE *destfile = fopen(dest, "w");
	if(!destfile){
		perror("Error opening destination file");
		return 1;
	}
	int ch;
	while((ch = fgetc(srcfile)) != EOF)
		fputc(ch, destfile);
	printf("Successfully copied %s to %s\n", src, dest);
	fclose(srcfile);
	fclose(destfile);
	return 0;
}
