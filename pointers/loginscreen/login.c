#include <stdio.h>
#include <stdlib.h>

int indexof(int target, int *arr, int arrsize){
	for(int i = 0; i < arrsize; i++)
		if(arr[i] == target)
			return i;	
	return -1;
}

int main(){
	int *userids = NULL;
	int *pins = NULL;
	int arrsize = 0;
	int c;
	int enteredid, enteredpin;

	while(1){
		printf("Type 1 for login, 2 for register : ");
		scanf("%d",&c);

		switch(c){	
			case(1):
				printf("Enter user ID : ");
				scanf("%d",&enteredid);
				printf("Enter pin : ");
				scanf("%d",&enteredpin);
				if(indexof(enteredid,userids,arrsize) == indexof(enteredpin,pins,arrsize) && indexof(enteredid,userids,arrsize)!=-1)
					printf("Login successful!\n");
				else
					printf("Wrong password or user ID\n");
				break;
			case(2):
				printf("Enter user ID : ");
				scanf("%d",&enteredid);
				printf("Enter pin : ");
				scanf("%d",&enteredpin);
				userids = (int *)realloc(userids, (arrsize+1)*sizeof(int));
				pins = (int *)realloc(pins, (arrsize+1)*sizeof(int));
				userids[arrsize] = enteredid;
				pins[arrsize] = enteredpin;
				arrsize++;
				printf("Successfully registered, now you may login.");
				break;	
		}
	}
}
