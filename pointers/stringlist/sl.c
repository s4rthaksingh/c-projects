#include <stdio.h>
#include <stdlib.h>

void printarray(char **arr, int size){
	for(int j = 0; j < size; j++){
		printf("%s",arr[j]);

}
}

int main(){
	char **arr = malloc(sizeof(char *));
	char *str;
	size_t temp;
	int i = 0;	

	while(1){
		arr = realloc(arr, (i + 1)*sizeof(char *)); 
		printf("Enter string : ");
		getline(&str,&temp,stdin);
		arr[i] = str;

		printarray(arr, i + 1);	
		i++;
		str = NULL;
		temp = 0;
	}

	return 0;
}
