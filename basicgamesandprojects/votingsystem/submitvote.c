#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char username[64];
	int candidateid;
} Vote;

int main(){
	FILE *fptr;
	
	char username[64];
	int candidateid;
	
	printf("Enter username : ");	
	scanf("%s",username);
	printf("Enter ID of the candidate you want to vote : ");
	scanf("%d",&candidateid);

	Vote v;
	strcpy(v.username, username);
	v.candidateid = candidateid;
	
	fptr = fopen("votes.bin","ab");
	fwrite(&v, sizeof(Vote), 1, fptr);
	fclose(fptr);	

	printf("Successfully counted your vote\n");
	fptr = fopen("votes.bin","rb");
	while(fread(&v, sizeof(Vote), 1, fptr))
		printf("User : %s, Candidate ID : %d\n", v.username, v.candidateid);
	
	fclose(fptr);
}
