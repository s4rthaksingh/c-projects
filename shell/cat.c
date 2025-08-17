#include <stdio.h>

int main(int argc, char *argv[]){

	if(argc < 2){
		printf("Usage : %s <text>\n", argv[0]);
		return 1;
	}
	char *dest = argv[1];	

	
	FILE *destfile = fopen(dest, "wb");

	if(!destfile){
		perror("Error opening destination file");
		return 1;
	}


	for(int i = 2; i < argc; i++)
		fprintf(destfile, "%s ", argv[i]);
	fprintf(destfile, "\n");
	printf("Successfully written to %s\n", dest);
	fclose(destfile);
	return 0;
}
