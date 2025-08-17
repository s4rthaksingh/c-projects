#include <stdio.h>

int main(int argc, char *argv[]){
	if(argc != 2) {
		printf("Usage: %s <filename>\n", argv[0]);
		return 1;
	}

	char *src = argv[1];	

	remove(argv[1]);
	printf("Successfully deleted file %s\n", argv[1]); 
	return 0;
}
