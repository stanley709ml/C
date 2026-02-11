#include <stdio.h>

void checkBalance(float balance);
float deposit();
float withdraw(float amount);

int main(){

	float balance, depositt, withdraww;
	int choice;

	do{
		printf("Welcome to the bank. What would you like to do?\n1. Check balance\n2. Deposit\n3. Withdraw\n4. Exit\n");
		scanf("%d", choice);
	}while(choice != 4);

	switch(choice){
		case 1:
			checkBalance(balance);
			break;
		case 2:
			balance + deposit();
			break;
		case 3:
			balance - withdraw(balance);
		       	break;	
		case 4:
			printf("Thanks for using the bank!");
			break;
	}

	return 0;
}

void checkBalance(float balance){

	printf("Your current balance is $%.2f\n", balance);
}

float deposit(){

	float amount;

	printf("How much do you want to deposit? ");
	scanf("%f", &amount);

	if(amount < 0){
		printf("Invalid. Try again.\n");
	}else{
		printf("Succesfully deposited %.2f.\n", amount);
		return amount;
	}

}

float withdraw(float balance){
	
	float amount;
	
	printf("How much do you want to withdraw? ");
       	scanf("%f", &amount);

	if(amount < 0){
		printf("Invalid. Try again.\n");
	}else{
		printf("Succesfull withdraw of %.2f\n", amount);
		return balance - amount;
	}


}
