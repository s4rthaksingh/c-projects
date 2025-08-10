#include <stdio.h>

void swap(int *ptr1, int *ptr2);

void swap(int *x, int *y){
	*x = *x + *y;
	*y = *x - *y;
	*x = *x - *y;	
}

int main(){
	int a,b;
	printf("Enter first integer : ");
 	scanf("%d",&a);
	printf("Enter second integer : ");	
	scanf("%d",&b);
	swap(&a,&b);
	printf("%d\n%d\n",a,b);
	return 0;
}
