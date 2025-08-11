#include <stdio.h>
#include <stdlib.h>

void printArray(int *start_ptr, int *end_ptr) {
    for (int *current_ptr = start_ptr; current_ptr <= end_ptr; current_ptr++) {
        printf("%d ", *current_ptr);
    }
    printf("\n"); 
}


int main(){
int *start = malloc(sizeof(int));
int count = 0;

while (1) {
    printf("Enter a number: ");
    scanf("%d", &start[count]);
    count++;

    start = realloc(start, (count + 1) * sizeof(int));

    printArray(start, start + count - 1);
}
}
