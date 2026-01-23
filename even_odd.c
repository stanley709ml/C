#include <stdio.h>
#include <math.h>

int main(){

	int x;

	printf("Choose a number to see if it's odd or even ");
	scanf("%d", &x);

	if (x % 2 != 0){
		printf("%d is odd.\n", x);
	} else{
		printf("%d is even.\n", x);
	}

	return 0;
}
