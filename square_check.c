#include <stdio.h>
#include <math.h>

int isPerfectSquare(int number);

int main(){

	int x = 0;
	int xSqrt = 0;

	printf("Choose a number to check if it's a perfect square: ");
	scanf("%d", &x);

	if (isPerfectSquare(x)){
		xSqrt = sqrt(x);
		printf("%d is a perfect square from %d\n", x, xSqrt);
	} else{
		printf("%d is not a perfect square.\n", x);
	}

	return 0;
}

int isPerfectSquare(int number){
	int i;
	
	for(int i = 0; i * i == number; i++){
		if (i * i == number){
			return 1;
		} else{
			return 0;		
		}
	}

}
