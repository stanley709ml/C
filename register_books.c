#include <stdio.h>
#include <string.h>

typedef float f32;
typedef struct{
    char title[150];
    char author[100];
    int id;
    f32 rating;
} Book;

void addBook(Book books[], int* count){
    printf("\nWhat is the name of the book? ");
    fgets(books[*count].title, sizeof(books[*count].title), stdin);
    books[*count].title[strcspn(books[*count].title, "\n")] = '\0';

    printf("What is the name of the author of this book? ");
    fgets(books[*count].author, sizeof(books[*count].author), stdin);
    books[*count].author[strcspn(books[*count].author, "\n")] = '\0'; 

    printf("What is the ID of this book? ");
    scanf("%d", &books[*count].id);

    printf("What is the rating of this book (1-5)? ");
    scanf("%f", &books[*count].rating);

    getchar();

    (*count)++;
}

void printBooks(Book books[], int count){
    for (int i = 0; i < count; i++) {
        printf("\n#%d Book name: %s\n#%d Book author: %s\n#%d Book ID: %d\n#%d Book rating: %.1f\n\n", i+1, books[i].title, i+1, books[i].author, i+1, books[i].id, i+1, books[i].rating);
    }
}

f32 calculateAverageRating(Book books[], int count){
    f32 sum_ratings = 0;
    f32 average_rating = 0;

    if (count == 0){
        average_rating = 0;
        return average_rating;
    }

    for (int i = 0; i < count; i++) {
        sum_ratings += books[i].rating;
    }

    average_rating = sum_ratings / count;
    return average_rating;
}

Book findBestBook(Book books[], int count){
    Book bestBook = books[0];

    for (int i = 0; i < count; i++) {
        if (books[i].rating > bestBook.rating) {
            bestBook = books[i];
        }
    }
    return bestBook;
}

int main(){
    
    Book books[100] = {0};
    int count = 0;
    int choice;
    f32 average_rating = 0;

    while(1){
        printf("\nWhat do you want to do?\n1 - Add book\n2 - Show all books\n3 - Show average rating\n4 - Show best book\n5 - Exit\nChoice: ");
        scanf("%d", &choice); 
        getchar();

        switch (choice) {
            case 1:
                addBook(books, &count);
                break;
            case 2:
                printBooks(books, count);
                break;
            case 3:
                average_rating = calculateAverageRating(books, count);
                printf("\n\nThe average rating of all books is %.1f\n\n", average_rating);
                break;
            case 4: {
                        Book bestBook = findBestBook(books, count);
                        printf("\n\nThe best book is:\nName: %s\nAuthor: %s\nID: %d\nRating: %.1f\n\n", bestBook.title, bestBook.author, bestBook.id, bestBook.rating);
                        break; 
                    } 
            case 5:
                printf("\nBye then.\n");
                return 1;
                break;
        }
    } 

    return 0;
}
