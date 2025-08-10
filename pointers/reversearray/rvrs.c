#include <stdio.h>

#define SIZE 5

void reverse(int *arr);
void swap(int *x, int *y);
void getarray(int *arr, int n);

void getarray(int *arr, int n){
	for(int j = 0; j < n; j++){
		printf("Enter element number %d : ",j+1);
		scanf("%d",&arr[j]);
}
}


void swap(int *x, int *y){
	*x = *x + *y;
	*y = *x - *y;
	*x = *x - *y;
}

void reverse(int *arr){
	int start = 0;
	int end = SIZE -1;
	while(start < end){
	swap(&arr[start],&arr[end]);
	start++;
	end--;
}
}

int main(){
	int arr[SIZE];
	getarray(arr,SIZE);
	reverse(arr);
	printf("Your reversed array is :\n");
	for(int i = 0; i <= SIZE-1;i++) printf("%d\n",arr[i]);	
	return 0;
}

