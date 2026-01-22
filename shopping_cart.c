#include <stdio.h>
#include <string.h>

int main(){

    char product[32] = "";
    char currency = '$';
    float price = 0.0f;
    float ammount = 0.0f;
    float total = 0.0f;

    printf("Welcome to this... mall? What do you wish to buy here? ");
    fgets(product, sizeof(product), stdin);
    product[strlen(product) - 1] = '\0';

    printf("Can you read the price of the product for me? ");
    scanf("%f", &price);

    printf("How many of these do you want? ");
    scanf("%f", &ammount);

    total = price * ammount;

    printf("The total for %.0f %ss is %c%.2f\n", ammount, product, currency, total);

    return 0;
}
