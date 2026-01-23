#include <stdio.h>
#include <math.h>

int isPerfectCube(int num);

int main(){

	int x = 0;
	int xCbrt = 0;

	printf("Choose a number to see if it's a perfect cube: ");
	scanf("%d", &x);

	if(isPerfectCube(x)){
		xCbrt = cbrt(x);
		printf("%d is a perfect cube from %d\n", x, xCbrt);
	} else{
	    printf("%d is not a perfect cube.\n", x);
	}

	return 0;
}

int isPerfectCube(int num){
	int i;

	for(int i = 1; pow(i, 3) <= num; i++){
		if(pow(i, 3) == num){
			return 1;
		}
	}
	return 0;
}
