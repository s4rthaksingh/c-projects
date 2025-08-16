#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char username[64];
	int candidateid;
} Vote;

int getvotes(Vote **arr){
	int i = 0;
	Vote currentvote;
	FILE *file = fopen("votes.bin","rb");
	if(!file)
		return 0;
	while(fread(&currentvote, sizeof(Vote), 1, file))
		{
			*arr = realloc(*arr, sizeof(Vote)*(i+1));
			(*arr)[i] = currentvote;
			i++;
		}
	fclose(file);
	return i;
}

int main(){
	FILE *fptr;
	
	Vote *votesarray = malloc(0);
	int votescount = getvotes(&votesarray);

	char username[64];
	int candidateid;
	
	printf("Enter username : ");	
	scanf("%s",username);

	if(votescount != 0)
		for(int j = 0; j < votescount; j++)
			if(strcmp(votesarray[j].username, username) == 0)
				{
					printf("You have already voted.\n");
					return 1;
				}

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
	return 0;
}
