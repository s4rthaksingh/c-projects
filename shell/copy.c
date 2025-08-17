#include <stdio.h>

int main(int argc, char *argv[]){
	char *src = argv[1];	
	char *dest = argv[2];

	FILE *srcfile = fopen(src, "r");
	FILE *destfile = fopen(dest, "w");
	char ch;
	while((ch = fgetc(srcfile)) != EOF)
		fputc(ch, destfile);
	printf("Successfully copied %s to %s\n", src, dest);
	return 0;
}
