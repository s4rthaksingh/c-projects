#include <stdio.h>
#include <math.h>

typedef struct {
	float x;
	float y;	
} Point;

int main(){
	float x1,y1,x2,y2;

	printf("Enter x1 : ");
	scanf("%f",&x1);	

	printf("Enter y1 : ");
	scanf("%f",&y1);	
	
	printf("Enter x2 : ");
	scanf("%f",&x2);	
	
	printf("Enter y2 : ");
	scanf("%f",&y2);	

	Point p1 = {x1,y1};
	Point p2 = {x2,y2};

	float s1 = (p2.x-p1.x)*(p2.x-p1.x);
	float s2 = (p2.y-p1.y)*(p2.y-p1.y);
	float distance = sqrt(s1 + s2);	

	printf("The distance between points is : %.2f\n",distance);
}
