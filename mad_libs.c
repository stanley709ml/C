#include <stdio.h>
#include <string.h>

int main(){

    char adjective[32] = "";
    char noun[32] = "";
    char adjective2[32] = "";
    char verb[32] = "";
    char adjective3[32] = "";

    printf("Enter an adjective (description): ");
    fgets(adjective, sizeof(adjective), stdin);
    adjective[strlen(adjective) - 1] = '\0';

    printf("Enter a noun (animal or person): ");
    fgets(noun, sizeof(noun), stdin);
    noun[strlen(noun) - 1] = '\0';

    printf("Enter an adjective (description): ");
    fgets(adjective2, sizeof(adjective2), stdin);
    adjective2[strlen(adjective2) - 1] = '\0';

    printf("Enter a verb (ending /w -ing): ");
    fgets(verb, sizeof(verb), stdin);
    verb[strlen(verb) - 1] = '\0';

    printf("Enter an adjective (description): ");
    fgets(adjective3, sizeof(adjective3), stdin);
    adjective3[strlen(adjective3) - 1] = '\0';

    printf("Once in a time, %s went to an abandoned cemetery, and there\n", noun);
    printf("was %s things and it was %s. ", adjective, verb);
    printf("Then, once he saw the %s parts\nof the cemetery, and how %s it was, he leaved.\n", adjective2, adjective3);

    return 0;
}
