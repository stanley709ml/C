#include <stdio.h>
#include <math.h>

int matTab(int num);

int main(){

	int x = 0;

  printf("Choose a number to see it's multiplication table (integers only): ");
  scanf("%d", &x);

	matTab(x);

	return 0;
}

int matTab(int num){

	int i;
	int result;
	int max;
	
	max = num * 10;

	for(int i = 1; num * i <= max; i++){
	    result = num * i;
		printf("%d * %d = %d\n", num, i, result);
	}

}
