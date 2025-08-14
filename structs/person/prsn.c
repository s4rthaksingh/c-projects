#include <stdio.h>

typedef struct {
	char *city;
	char *state;
	int pincode;
} Address;

typedef struct {
	char *name;
	int age;
	Address address;
} Person;

int main(){
	Address address = {"San Francisco", "California", 94301};
	
	Person p1 = {"Sarthak", 16, address};
	Person p2 = {"John Doe", 20, address};
	Person p3 = {"Jane Doe", 30, address};
	
	Person people[3] = {p1,p2,p3};

	for(int i = 0; i < 3; i++){
		Person p = people[i];
		printf("Name : %s\nAge : %d\nCity : %s\nState : %s\nPincode : %d\n", p.name, p.age, p.address.city, p.address.state, p.address.pincode);
	}
}
