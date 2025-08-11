#include <stdio.h>

size_t mystrlen(const char *str){
	int len = 0;
	const char *ptr = str;
	while(*ptr != '\0'){
		len++;
		ptr++;	
}
	return len;
}

int main() {
    const char *text = "Hello, world!";
    printf("Length: %zu\n", mystrlen(text));
    return 0;
}
