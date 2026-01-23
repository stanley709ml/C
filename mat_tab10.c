#include <stdio.h>

int matTab10(void);

int main(void){
	
	matTab10();

	return 0;
}

int matTab10(void){
	int i, j;
	
	for(int i = 1; i <= 10; i++){
		for(int j = 1; j <=10; j++){
			printf("%d * %d = %d\n", i, j, i * j);
		}
	}
}
