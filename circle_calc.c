#include <stdio.h>
#include <math.h>

int main(){
	
	// Circumference: 2 * pi * r
	// Area: pi * r^2
	// Diameter: 2 * r
	
	float radius = 0.0f;
	float area = 0.0f;
	float diameter = 0.0f;
	float circumference = 0.0f;
	const float pi = 3.14;

	printf("What's the radius of the circle? (If you only have the diameter, just divide it by two) ");
	scanf("%f", &radius);

	area = pi * pow(radius, 2);
	diameter = radius * 2;
	circumference = 2 * pi * radius;

	printf("The area of the circle is %.2fcm^2.\n", area);
	printf("The diameter of the circle is %.2fcm.\n", diameter);
	printf("The surface area of the circle is %.2fcm.\n", circumference);	

	return 0;	
}
