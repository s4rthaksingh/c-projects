#include <stdio.h>
#include <string.h>

int main(){
	size_t len = 0;
	char userfilename[20];
	char filename[20] = "data.txt";
	printf("1. View notes\n2. Add a note\n3. Remove a note\n4. Update a note\n\nEnter your choice number : ");
	int c = getchar();
	
	
	switch(c){
		
	default:
		printf("Invalid choice.\n");
		break;	
	}	
	return 0;
};
