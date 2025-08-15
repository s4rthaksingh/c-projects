#include <stdio.h>
#include <stdlib.h>

int main(){
	char user[64];
	int candidateid;
	FILE *fptr;
	
	printf("Enter username : ");
	scanf("%s",user);
	printf("Enter ID of the candidate you want to vote : ");
	scanf("%d",&candidateid);

	fptr = fopen("votes.txt","a");
	fprintf(fptr, "%s : %d\n", user, candidateid);
	fclose(fptr);	

	printf("Successfully counted your vote\n");

	char ch;	
	int i =  0;
	int ui = 0;
	int pc = 0;
	int s = 0;
	char *users = malloc(0);
	fptr = fopen("votes.txt","r");

	while((ch = fgetc(fptr)) != EOF){
		if(ch == ' '){
			if(pc == 0){
				users = realloc(users, sizeof(char)*(ui+1));
				users[ui] = ",";
				ui++;
				pc = 1;
				}
			else pc = 0;
			s = 0;
			}
		if(ch == '\n' || i == 0)
			s = 1;
		if(s == 1 && ch != '\n')
			{

				users = realloc(users, sizeof(char)*(ui+1));
				users[ui] = ch;
				ui++;
			}
		i++;
	}
	
	printf("%s",users);
}
