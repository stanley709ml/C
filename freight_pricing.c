#include <stdio.h>

int main(){

	float km_away = 0.0f;
	const float dolperkm = 0.39;
	float total_price = 0.0f;

	printf("How many kilometers away is your home from our company? ");
	scanf("%f", &km_away);

	total_price = km_away * dolperkm;

	printf("Your total freight price is $%.2f ($%.2f per km)\n", total_price, dolperkm);

	return 0;
}
