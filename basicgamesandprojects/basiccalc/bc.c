#include <stdio.h>

void main(){
	while(1==1){
	int a,b;
	char o;
	printf("Enter number 1 : ");
	scanf("%d",&a);
	printf("Enter number 2 : ");
	scanf("%d",&b);
	printf("Choose your operator : ");
	scanf(" %c",&o);
	switch(o){
	case '+':
		printf("%d",(a+b));
	break;
	case '-':
		printf("%d",(a-b));
	break;
	case '*':
		printf("%d",(a*b));
	break;
	case '/':
		printf("%f",((float)a/b));
	break;
	}
	printf("\n");
}}
