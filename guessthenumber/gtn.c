#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(){
	while(1==1){
	srand(time(NULL));
	
	int n = rand()%10 + 1;
	int un;
	
	printf("Guess the number from 1 to 10 : ");
	scanf("%d", &un);
	if(n==un)
		printf("You guessed the correct number! it was indeed %d\n", n);
	else
		printf("Wrong! it was %d\n",n);
}}
