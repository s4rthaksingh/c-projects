#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char email[320];
	char password[256];
	float balance;
} User;

int getaccounts(User **accounts){
	*accounts = NULL;
	FILE *fptr = fopen("data.bin", "rb");
	if(!fptr)
		return -1;
	User current;
	int i = 0;
	while(fread(&current, sizeof(User), 1, fptr))
	{
		*accounts = realloc(*accounts, sizeof(User)*(i+1));
		(*accounts)[i] = current;
		i++;
	}		
	fclose(fptr);
	return i;	
}

int checkemail(const char *email) {
	User *accounts = malloc(0);
	int count = getaccounts(&accounts);
	if(count != -1)
		for(int i = 0; i < count; i++)
			if(strcmp(accounts[i].email, email) == 0)
				return 0;	
	const char *at = strchr(email, '@');
	const char *dotcom = strstr(email, ".com");

	return (at && dotcom && at < dotcom);
}


void createaccount(char *email, char *password)
{
	User newuser;
	snprintf(newuser.email, sizeof(newuser.email), "%s", email);
	snprintf(newuser.password, sizeof(newuser.password), "%s", password);
	newuser.balance = 0;
	FILE *fptr = fopen("data.bin","ab");

	fwrite(&newuser, sizeof(User), 1, fptr); 
	fclose(fptr);
	printf("%s : %.2f\n", email, newuser.balance);
}

float getbalance(char *email)
{
	User *accounts = NULL;
	int count = getaccounts(&accounts);
	for(int i = 0; i < count; i++)
		if(strcmp(accounts[i].email, email) == 0)
			return accounts[i].balance;
	return -1;
}


int main()
{
	int choice;
	printf("1.Create account\n2.Check balance\n3.Deposit\n4.Withdraw\n5.Payment\nType the option number : ");
	scanf("%d", &choice);	

	switch(choice){
		char email[320], pass[256];
		case 1:
			printf("Enter your email (maximum 320 characters) : ");
			scanf("%s", email);

			if(!checkemail(email)){	
				printf("Email invalid or already in use\n");
				return 0;
			}

			printf("Enter a strong password (maximum 256 characters) : ");
			scanf("%s", pass);		
				
			createaccount(email, pass);		
				
			break;
		case 2:
			printf("Enter your email : ");
			scanf("%s", email);
			printf("Enter your password : ");
			scanf("%s", pass);
			
			float bal = getbalance(email);
			if(bal == -1)
				printf("Account doesn't exist");
			else
				printf("Your current balance : %.2f", bal);
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
	}
}
