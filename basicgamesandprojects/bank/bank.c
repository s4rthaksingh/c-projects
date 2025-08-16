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

int authenticate(char *email, char *pass){
	User *accounts = NULL;
	int count = getaccounts(&accounts);
	for(int i = 0; i < count; i++)
		if(strcmp(accounts[i].email, email) == 0 && strcmp(accounts[i].password, pass) == 0)
			return 1;
	return 0;
}

void changebalance(char *email, float bal){
	User *accounts = NULL;
	int count = getaccounts(&accounts);
	FILE *fptr = fopen("data.bin", "wb");
	for(int i = 0; i < count; i++)
		if(strcmp(accounts[i].email, email) == 0)
			accounts[i].balance = bal;
	fwrite(accounts, sizeof(User), count, fptr);
	fclose(fptr);
}

int main()
{
	int choice;
	printf("1.Create account\n2.Check balance\n3.Deposit\n4.Withdraw\n5.Payment\nType the option number : ");
	scanf("%d", &choice);	

	switch(choice){
		char email[320], pass[256];
		float bal;
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
			
			bal = getbalance(email);
			if(bal == -1){
				printf("Account doesn't exist\n");
				break;
			}
			if(!authenticate(email, pass)){
				printf("Wrong password\n");			
				break;
				}	
			else
				printf("Your current balance : %.2f\n", bal);
			break;
		case 3:				
			printf("Enter your email : ");
			scanf("%s", email);
			printf("Enter your password : ");
			scanf("%s", pass);
			if(!authenticate(email, pass)){
				printf("Wrong email or password\n");			
				break;
				}	
			bal = getbalance(email);
			float deposit;	
			printf("Enter amount you want to deposit : ");
			scanf("%f", &deposit);
			changebalance(email, bal+deposit);
			printf("Successfully deposited %.2f to your account\nYour current balance is %.2f\n",deposit,getbalance(email));	
			
			break;
		case 4:
			break;
		case 5:
			break;
	}
}
