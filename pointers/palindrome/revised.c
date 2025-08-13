#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
while(1){
        char *string = NULL;
        size_t len = 0;
	int check = 1;
	int i = 0;

        printf("Enter your string : ");
        getline(&string, &len, stdin);
        string[strcspn(string,"\n")] = '\0';

	len = strlen(string);

	while(string[i] != '\0' && (len-i)>i){	
		if(string[i] != string[len-i-1])
			{
				check = 0;	
				break;
			}
		i++;
	}
	
	if(check) printf("Palindrome\n");
	else printf("Not a palindrome\n");
	free(string);
}}
