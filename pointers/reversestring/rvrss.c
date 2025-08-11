#include <stdio.h>

void reverse(char *arr){
	int len = 0;
	char *copy = arr;
	while(*copy != '\0'){
		len++;
		copy++;
}
	char reverse[len+1];	
	for(int i = 0; i < len; i++)
		reverse[i] = arr[len - 1 - i];
	reverse[len] = '\0';
	
	for (int i = 0; i <= len; i++) {
       		arr[i] = reverse[i];
    	}
}

int main(){
	char name[] = "Sarthak";
	reverse(name);
	printf("%s",name);
}
