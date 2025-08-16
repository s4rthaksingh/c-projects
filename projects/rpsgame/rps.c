#include <stdio.h>
#include <stdlib.h>

void main(){
	int user;
	while(1==1)	
	{
		printf("Enter 1 for rock, 2 for paper, 3 for scissors, 4 to exit game : ");
		scanf("%d",&user);
		int computer = rand()%3;
		if(user==1 && computer==2) printf("Computer chose paper and won!");
		else if(user == 2 && computer == 1) printf("Computer chose rock and lost");
		else if(user == 3 && computer == 2) printf("Computer chose paper and lost");
		else if(user == 2 && computer == 3) printf("Computer chose scissors and won!");
		else if(user == 1 && computer == 3) printf("Computer chose scissors and lost");
		else if(user == 3 && computer == 1) printf("Computer chose rock and won!");
		else if(user == 4) exit(0);
		else printf("You both tied");
		printf("\n");
	}
}
