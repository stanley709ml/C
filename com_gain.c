#include <stdio.h>

int main(){

	float tot_on_sales = 0.0f;
	float comission_percentage = 0.0f;
	float comission_gain = 0.0f;

	printf("What's your total on sales? (DOLARS, NO CURRENCY ON PROMPT) ");
	scanf("%f", &tot_on_sales);

	if(tot_on_sales >= 10000){
		comission_gain = tot_on_sales * 0.25;
		printf("The total you will gain from that sale is 0.25 and the total is $%.2f\n", comission_gain);
	} else if(tot_on_sales > 7500){
		comission_gain = tot_on_sales * 0.15;
		printf("The total you will gain from that sale is 0.15x and the total is $%.2f\n", comission_gain);
	} else if(tot_on_sales >= 5000){
		comission_gain = tot_on_sales * 0.05;
		printf("The total you will gain from that sale is 0.05x and the total is $%.2f\n", comission_gain);
	} else{
		printf("You gain no commision gains.\n");
	}

	return 0;
}
