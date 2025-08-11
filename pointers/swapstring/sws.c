#include <stdio.h>

void swap(char **str1, char **str2)
	{
		char *temp = *str1;
		*str1 = *str2;
		*str2 = temp;		
	}

void main(){
	char *a = "Hello ";
	char *b = "World";
	swap(&a,&b);
	printf("%s%s\n",a,b);
}
