#include <stdio.h>
#include <string.h>

// Just a warning I think will be good:
// This program creates a file named 'workers-report.txt' inside whatever
// directory you executed this program.

typedef float f32;
typedef struct{
    char name[100];
    f32 salary; 
} Workers;

int main(){

    int ammount_workers;
    int* pammount_workers = &ammount_workers;

    printf("How many workers do you wanna register? ");
    scanf("%d", &ammount_workers);
    getchar();

    Workers workers[*pammount_workers];

    for (int i = 0; i < ammount_workers; i++) {
        printf("What is the name of the %d worker? ", i+1);
        fgets(workers[i].name, sizeof(workers[i].name), stdin);

        printf("What is the salary of the %d worker? ", i+1);
        scanf("%f", &workers[i].salary);
        
        getchar();
    }

    printf("The data of the workers is the following:\n");

    FILE* pfile = fopen("workers-report.txt", "w");

    if (pfile == NULL) {
        printf("Could not open file\n");
        return 1;
    }

    char text0[1024] = "Below is located the report of all the workers registered:\n";
    
    for (int j = 0; j < ammount_workers; j++) {
        printf("%d worker name: %s%d worker salary: $%.2f\n\n", j+1, workers[j].name, j+1, workers[j].salary);

        char text[5108]; 
        sprintf(text, "%d worker name: %s%d worker salary: $%.2f\n\n", j+1, workers[j].name, j+1, workers[j].salary); 
        fprintf(pfile, "%s", text);
    }
    
    fclose(pfile);

    return 0;
}
