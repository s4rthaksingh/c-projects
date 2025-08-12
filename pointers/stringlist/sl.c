#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printarray(char **arr, int size){
	for(int j = 0; j < size; j++){
		printf("%s",arr[j]);

	}
	printf("\n");
}

int main(){
	char **arr = malloc(sizeof(char *));
	char *str = "Hello World";
	size_t temp = 0;
	int i = 0;	
	ssize_t olen = 0;	
	ssize_t nlen = 0;

	while(*str != '-'){
		olen = nlen;
		arr = realloc(arr, (i + 1)*sizeof(char *)); 
		printf("Enter string : ");
		nlen = getline(&str,&temp,stdin);
		str[nlen-1] = ',';
		arr[i] = strdup(str);

		i++;
	}
	
	arr[i-2][olen-1] = '\0';
	arr[i-1] = "";
	printarray(arr, i);
	
	return 0;
}
