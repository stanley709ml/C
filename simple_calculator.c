#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){

	float n = 0.0f;
	char operator = '\0';
	float n1 = 0.0f;
	float result = 0.0f;

	printf("Choose a number (can be floating point): ");
	scanf("%f", &n);

	printf("What operation do you want to do (+, -, *, /, ^ (^ is to the power of))? ");
	scanf(" %c", &operator);
	
	printf("Chose another number (can also be a floating point): ");
	scanf(" %f", &n1);
	
	
	if(operator == '+'){
		result = n + n1;
		printf("The result of the addition of the two numbers is %.2f\n", result);
	} else if(operator == '-'){
		result = n - n1;
		printf("The result of the subtraction of the two numbers is %.2f\n", result);
	} else if(operator == '*'){
		result = n * n1;
		printf("The result of the multiplication of the two numbers is %.2f\n", result);
	} else if(operator == '/'){
		result = n / n1;
		printf("The result of the division of the two numbers is %.2f\n", result);
	} else if(operator == '^'){
		result = pow(n, n1);
		printf("The result of the number 1 to the power of number 2 is %.2f\n", result);
	} else{
		printf("Insert a valid operator.");
	}
	
	return 0;
}
