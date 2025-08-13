#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main(){
while(1){
	char *string = NULL;
	size_t len = 0;
	printf("Enter your string : ");
	getline(&string, &len, stdin);
	string[strcspn(string,"\n")] = '\0';

	char *start = string;
	char reverse[56];
	while(*string != '\0') string++;
	string--;	
	int i = 0;
	while(string != start){
		reverse[i] = *string;
		string--;	
		i++;
	}	
	reverse[i] = *string;
	reverse[i+1] = '\0';

	if(strcmp(start,reverse) == 0)
		printf("Palindrome\n");
	else
		printf("Not a palindrome\n");
	free(string);
}}
