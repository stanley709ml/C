#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){

	char unit = '\0';
	char unitToConvert = '\0';
	float temp = 0.0f;
	float tempCF = 0.0f;
	float tempCK = 0.0f;
	float tempFC = 0.0f;
	float tempFK = 0.0f;
	float tempKC = 0.0f;
	float tempKF = 0.0f;

	printf("What unit is the temperature you have (C celsius, K kelvin, F fahrenheit)? ");
	scanf("%c", &unit);

	printf("What unit do you want it to be converted to? ");
	scanf(" %c", &unitToConvert);

	printf("What's the current temperature? ");
	scanf(" %f", &temp);

	if(unit == 'C' && unitToConvert == 'F'){
		tempCF = (temp * 9 / 5) + 32;
		printf("The temperature from %c in %c is %.1f%c\n", unit, unitToConvert, tempCF, unitToConvert);
	} else if(unit == 'C' && unitToConvert == 'K'){
		tempCK = temp + 273;
		printf("The temperature from %c in %c is %.1f%c\n", unit, unitToConvert, tempCK, unitToConvert);
	} else if(unit == 'F' && unitToConvert == 'C'){
		tempFC = (temp - 32) * 5 / 9;
		printf("The temperature from %c in %c is %.1f%c\n", unit, unitToConvert, tempFC, unitToConvert);
	} else if(unit == 'F' && unitToConvert == 'K'){
		tempFK = (temp - 32) * 5 / 9 + 273;
		printf("The temperature from %c in %c is %.1f%c\n", unit, unitToConvert, tempFK, unitToConvert);
	} else if(unit == 'K' && unitToConvert == 'C'){
		tempKC = temp - 273;
		printf("The temperature from %c in %c is %.1f%c\n", unit, unitToConvert, tempKC, unitToConvert);
	} else if(unit == 'K' && unitToConvert == 'F'){
		tempKF = (temp - 273) * 9 / 5 + 32;
		printf("The temperature from %c in %c is %.1f%c\n", unit, unitToConvert, tempKF, unitToConvert);
	}

	return 0;
}
