#include <stdio.h>
#include <string.h>

void main(){
while(1){
	char *string = NULL;
	size_t len = 0;
	printf("Enter your string : ");
	getline(&string, &len, stdin);
	string[strcspn(string,"\n")] = '\0';

	char *copy = string;
	char temp[56];
	while(*string != '\0') string++;
	string--;	
	int i = 0;
	while(string != copy){
		temp[i] = *string;
		string--;	
		i++;
	}	
	temp[i] = *string;
	temp[i+1] = '\0';

	if(strcmp(copy,temp) == 0)
		printf("Palindrome\n");
	else
		printf("Not a palindrome\n");
}}
