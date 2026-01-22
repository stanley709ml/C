#include <stdio.h>
#include <math.h>

int main(){
	
	// Formula: p(1 + r/n)^nt

	float principal = 0.0f;
	float interest_rate = 0.0f;
	int timesCompounded = 0;
	int years = 0;
	float total = 0.0f;

	printf("What is the principal applied? ");
	scanf("%f", &principal);

	printf("What's the interest rate? ");
	scanf("%f", &interest_rate);
	interest_rate = interest_rate / 100;

	printf("How many times it was compounded? ");
	scanf("%d", &timesCompounded);

	printf("How many years did it last? ");
	scanf("%d", &years);

	total = principal * (pow(1 + interest_rate/timesCompounded, timesCompounded * years));

	printf("The total is $%.2f.\n", total);

	return 0;	

}
