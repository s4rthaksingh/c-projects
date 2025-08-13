#include <stdio.h>

void copystring(char *dest, const char *src){
	int i = 0;

	while(src[i] != '\0')
	{
		dest[i] = src[i];
		i++;	
	}
	dest[i] = '\0';
}

int main()
{
	char d[10];
	char *s = "Hello\0";
	copystring(d,s);
	printf("%s",d);
	
	return 0;
}
