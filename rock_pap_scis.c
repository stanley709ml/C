#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

	srand(time(NULL));

	int max = 3;
	int min = 1;
	int compChoice = (rand() % (max - min + 1) + min);
	int userChoice;

	printf("Choose your pick:\n 1. Rock\n 2. Scissors\n 3. Paper\n ");
	scanf("%d", &userChoice);

	if(compChoice == 3 && userChoice == 3){
		printf("Paper vs Paper and that's a tie!\n");
	}else if(compChoice == 3 && userChoice == 2){
		printf("Paper vs Scissors and that's a win for the user!\n");
	}else if(compChoice == 3 && userChoice == 1){
		printf("Paper vs Rock and that's a win for the computer!\n");
	}else if(compChoice == 2 && userChoice == 2){
		printf("Scissors vs Scissors and that's a tie!\n");
	}else if(compChoice == 2 && userChoice == 3){
		printf("Scissors vs Paper and that's a win for the computer!\n");
	}else if(compChoice == 2 && userChoice == 1){
		printf("Scissors vs Rock and that's a win for the user!\n");
	}else if(compChoice == 1 && userChoice == 3){
		printf("Rock vs Paper and that's a win for the user!\n");
	}else if(compChoice == 1 && userChoice == 2){
		printf("Rock vs Scissors and that's a win for the computer!\n");
	}else if(compChoice == 1 && userChoice == 1){
		printf("Rock vs Rock and that's a tie!\n");
	}

	return 0;
}
