#include <stdio.h>
#include <string.h>

typedef struct {
	char email[320];
	char password[256];
} User;

int getaccounts(User **accounts){
	FILE *fptr = fopen("data.bin", "rb");
	User current;
	int i = 0;
	while(fread(&current, sizeof(User), 1, fptr))
	{
		*accounts[i] = current;
		i++;
	}		
	return i;
}

int checkemail(const char *email) {
	User *accounts;
	int count = getaccounts(&accounts);
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
	FILE *fptr = fopen("data.bin","ab");

	fwrite(&newuser, sizeof(User), 1, fptr); 
	fclose(fptr);
	printf("%s : %s\n", email, password);
}

int main()
{
	int choice;
	printf("1.Create account\n2.Deposit\n3.Withdraw\n4.Payment\nType the option number : ");
	scanf("%d", &choice);	

	switch(choice){
		case 1:
			char email[320], pass[256];
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
			break;
		case 3:
			break;
		case 4:
			break;
	}
}
