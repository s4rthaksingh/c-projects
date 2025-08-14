#include <stdio.h>

typedef struct {
	char name[50];
	int age;
	float marks;
} Student;


int main(){
	Student highest = {"Dumb kid",5,0};
	Student students[5] = {
		{"Alice",20,95.5},
		{"Bob",21,88.0},
		{"Charlie",19,90.0},
		{"Derek",17,96},
		{"Eric",22,94.5}
	};
	
	for(int i = 0; i < 5; i++)
		if(students[i].marks > highest.marks)
			highest = students[i];
	
	printf("The student with highest marks is %s\n",highest.name);
}
