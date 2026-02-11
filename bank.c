#include <stdio.h>

void checkBalance(float ballance);
float deposit();
float withdraw(float balannce);

int main(){

	int choice = 0;
	float balance = 0.0f;

	do{
		printf("Welcome to the bank. What would you like to do?\n1. Check balance\n2. Deposit\n3. Withdraw\n4. Exit\n");
		scanf("%d", &choice);

		switch(choice){
		case 1:
			checkBalance(balance);
			break;
		case 2:
			balance += deposit();
			break;
		case 3:
			balance -= withdraw(balance);
			break;
		case 4:
			printf("\nBye bye.\n");	
			break;
		default:
			printf("\nInvalid. Try again\n");
			break;
	}

	}while(choice != 4);

	
}

void checkBalance(float ballance){
	printf("\nYour current balance is $%.2f\n", ballance);
}

float deposit(){
	
	float amount = 0.0f;

	printf("How much would you like to deposit? ");
	scanf("%f", &amount);

	if(amount < 0){
		printf("\nInvalid quantity. Please try again\n");
	}else{
		printf("\nSuccesfully deposited $%.2f\n", amount);
	} return amount;

}

float withdraw(float balannce){
	
	float amount = 0.0f;

	printf("How much would you like to withdraw? ");
	scanf("%f", &amount);

	if(amount < 0){
		printf("\nInvalid quantity. Please try again\n");
	}else{
		printf("\nSuccesfully withdrawed $%.2f\n", amount);
	} return amount;
}
