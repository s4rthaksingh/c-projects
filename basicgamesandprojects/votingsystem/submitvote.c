#include <stdio.h>

int main(){
	char user[64];
	int candidateid;
	
	printf("Enter username : ");
	scanf("%s",user);
	printf("Enter ID of the candidate you want to vote : ");
	scanf("%d",&candidateid);
	
	FILE *fptr = fopen("votes.txt","w");
	fprintf(fptr, "%s : %d\n", user, candidateid);
	fclose(fptr);	

	printf("Successfully counted your vote\n");
}
