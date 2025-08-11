#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	char *str1 = NULL, *str2 = NULL	;
	size_t len1 = 0, len2 = 0;

	printf("Enter first string : ");
	getline(&str1, &len1, stdin);	

	printf("Enter second string : ");
	getline(&str2, &len2, stdin);

	int len = len1 + len2 + 1;
	char *result = malloc(len);
	char *start = result;

	while(*str1 != '\n'){
		*result	= *str1;
		str1++;
		result++;
	}

	while(*str2 != '\n'){
		*result = *str2;
		result++;
		str2++;	
	}
	
	*result = '\0';

	printf("%s\n",start);
		
	free(start);
	return 0;
}
