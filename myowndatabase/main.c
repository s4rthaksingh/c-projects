#include <stdio.h>

int main(){
	size_t len = 0;
	char *line = NULL;
	printf("> ");
	ssize_t read = getline(&line, &len, stdin);
	printf("Data length : %ld\n", read-1);
	printf("Data size : %ld\n", sizeof(line));
	return 0;
};
