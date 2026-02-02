#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

	srand(time(NULL));

	int max = 100;
	int min = 0;
	int ranNum = (rand() % (max - min + 1) + min);
	int guess_num;

	do{
		printf("Choose a number to guess from 0 to 100: ");
		scanf("%d", &guess_num);	
		
		if(guess_num > ranNum){
			printf("Too high!\n");
		} else if(guess_num < ranNum){
			printf("Too low!\n");
		}

	}while(guess_num != ranNum);

	printf("You got it! The number was %d\n", ranNum);

	return 0;
}
