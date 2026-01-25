#include<stdio.h>

void freight_price(float km);

int main(){
    
    float km = 0.0f;
    
    printf("How many kilometers away is your home from our company? ");
    scanf("%f", &km);
    
    freight_price(km);
    
    return 0;
}

void freight_price(float km){

    const float dolPerKm = 0.39;
    float total = 0.0f;
    
    total = km * dolPerKm;
    
    printf("The total freight cost is $%.2f ($%.2f per km)\n", total, dolPerKm);
}
