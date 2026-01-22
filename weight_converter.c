#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
	
	char unit = '\0';
	char unitToConvert = '\0';
	float weight = 0.0f;
	float totalKP = 0.0f;
	float totalKT = 0.0f;
	float totalPK = 0.0f;
	float totalPT = 0.0f;
	float totalTK = 0.0f;
	float totalTP = 0.0f;

	printf("What's the unit of the weight you have (K for kg, P for pounds, T for tons)? ");
	scanf("%c", &unit);

	printf("To what unit do want to convert to? ");
	scanf(" %c", &unitToConvert);

	printf("What's the total weight? ");
	scanf("%f", &weight);

	if(unit == 'K' && unitToConvert == 'T'){
		totalKT = weight * 1000;
		printf("The total weight from %c in tons is %.1f%c\n", unit, totalKT, unitToConvert);
	} else if(unit == 'K' && unitToConvert == 'P'){
		totalKP = weight * 2.205;
		printf("The total weight from %c in pounds is %.1f%c\n", unit, totalKP, unitToConvert);	
	} else if(unit == 'P' && unitToConvert == 'K'){
		totalPK = weight / 2.205;
		printf("The total weight from %c in kilograms is %.1f%c\n", unit, totalPK, unitToConvert);
	} else if(unit == 'P' && unitToConvert == 'T'){
		totalPT = weight / 2000;
		printf("The total weight from %c in tons is %.1f%c\n", unit, totalPT, unitToConvert);
	} else if(unit == 'T' && unitToConvert == 'K'){
		totalTK = weight / 1000;
		printf("The total weight from %c in kilograms is %.1f%c\n", unit, totalTK, unitToConvert);
	} else if(unit == 'T' && unitToConvert == 'P'){
		totalTP = weight * 2000;
		printf("The total weight from %c in pounds is %.1f%c\n", unit, totalTP, unitToConvert);
	}

	return 0;
}
