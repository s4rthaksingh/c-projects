#include <stdio.h>

int main(int argc, char *argv[]){

	char *dest = argv[1];	

	
	FILE *destfile = fopen(dest, "wb");

	if(!destfile){
		perror("Error opening destination file");
		return 1;
	}


	for(int i = 2; i < argc; i++)
		fprintf(destfile, "%s ", argv[i]);

	printf("Successfully written to %s\n", dest);
	fclose(destfile);
	return 0;
}
