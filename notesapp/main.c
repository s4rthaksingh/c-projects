#include <stdio.h>
#include <string.h>

int main(){
	size_t len = 0;
	char userfilename[20];
	char filename[20] = "data.txt";
	printf("1. View notes\n2. Add a note\n3. Remove a note\n4. Update a note\n\nEnter your choice number : ");
	int c = getchar();
	if(c < 1 || c > 4){
		printf("Invalid choice.\n");
		return 1;
	}
	printf("Your choice : %c\n", c);
	return 0;
};
