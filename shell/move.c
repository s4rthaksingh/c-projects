#include <stdio.h>

int main(int argc, char *argv[]){
	if(argc != 3) {
		printf("Usage: %s <source> <target>\n", argv[0]);
		return 1;
	}

	char *src = argv[1];	
	char *dest = argv[2];

	FILE *srcfile = fopen(src, "rb");
	if(!srcfile){
		perror("Error opening source file");
		return 1;
	}
	FILE *destfile = fopen(dest, "wb");
	if(!destfile){
		perror("Error opening destination file");
		return 1;
	}
	int ch;
	while((ch = fgetc(srcfile)) != EOF)
		fputc(ch, destfile);
	printf("Successfully moved %s to %s\n", src, dest);
	fclose(srcfile);
	remove(argv[1]);
	fclose(destfile);
	return 0;
}
