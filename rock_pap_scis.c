#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

	srand(time(NULL));

	int max = 3;
	int min = 1;
	int compChoice = (rand() % (max - min + 1) + min);

	printf("%d\n", compChoice);

	return 0;
}
