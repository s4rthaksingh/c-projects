#include <stdio.h>
#include <stdlib.h>


int indexof(int target, int *arr){
	int arrsize = sizeof(arr)/sizeof(int);
	for(int i = 0; i < arrsize; i++)
		if(arr[i] == target)
			return i;	
	return -1;
}

int main(){
	int *userids = NULL;
	int *pins = NULL;
	int index = 0;
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
				if(indexof(enteredid,userids) == indexof(enteredpin,pins))
					printf("Login successful!\n");
				else
					printf("Wrong password or user ID\n");
				break;
			case(2):
				printf("Enter user ID : ");
				scanf("%d",&enteredid);
				printf("Enter pin : ");
				scanf("%d",&enteredpin);
				userids = (int *)realloc(userids, (index+1)*sizeof(int));
				pins = (int *)realloc(pins, (index+1)*sizeof(int));
				userids[index] = enteredid;
				pins[index] = enteredpin;
				index++;
				printf("Successfully registered, now you may login.");
				break;	
		}
	}
}
