#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char *name;
	int id;
	float salary;
} Employee;

Employee *createEmployee(char *name, int id, float salary){
	Employee *e = (Employee *)malloc(sizeof(Employee));
	e->id = id;
	e->salary = salary;
	e->name = (char *)malloc(strlen(name) + 1);
	strcpy(e->name, name);

    	return e;
}

void display(Employee *e){
	Employee employee = *e;
	printf("Name : %s\nID : %d\nSalary : %.2f\n", employee.name, employee.id, employee.salary);
}

int main(){
	Employee *emp = createEmployee("John Doe", 1, 100000);
	display(emp);
	
	free(emp->name);
	free(emp);

	return 0;
}
