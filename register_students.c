#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef float f32;
typedef struct{
    char name[50];
    int id;
    f32 grade;
} Student;

void addStudents(Student students[], int* count){
    printf("\nWhat is the ID of the student? ");
    scanf("%d", &students[*count].id);
    getchar();

    printf("What is the name of the student? ");
    fgets(students[*count].name, sizeof(students[*count].name), stdin);
    students[*count].name[strcspn(students[*count].name, "\n")] = '\0';

    printf("What is the grade of the student? ");
    scanf("%f", &students[*count].grade);
    
    getchar();

    (*count)++;
}

void printStudents(Student students[], int count){
    for (int i = 0; i < count; i++) {
        printf("\nStudent #%d name: %s\nStudent #%d grade: %.1f\nStudent #%d ID: %d\n\n", i+1, students[i].name, i+1, students[i].grade, i+1, students[i].id);   
    }
}

float calculateAverage(Student students[], int count){
    float grade_average = 0;
    float grades_sum = 0;

    if (count == 0){
        return 0;
    }else{
        for (int i = 0; i < count; i++) {
            grades_sum += students[i].grade;
        }
    
    grade_average = grades_sum / count;
 
    }

   return grade_average;
}

Student findTopStudent(Student students[], int count){
    Student topStudent = students[0];

    for (int i = 0; i < count; i++) {
        if (students[i].grade > topStudent.grade) {
            strcpy(topStudent.name, students[i].name);
            topStudent.id = students[i].id;
            topStudent.grade = students[i].grade;
        }
    }
    return topStudent;
}

int main(){

    Student students[100];
    int count = 0;
    int choice;

    while(1){
        printf("\nWhat do you want to do?\n1 - Add Student\n2 - Show all students\n3 - Show average grade\n4 - Show top student\n5 - Exit\nChoice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addStudents(students, &count);
                break;
            case 2:
                printStudents(students, count);
                break;
            case 3:
                printf("\nThe grade average of all students is %.1f\n", calculateAverage(students, count));
                break;
            case 4: {
                        Student topStudent = findTopStudent(students, count);
                        printf("\nThe top student is:\nID: %d\nName: %s\nGrade: %.1f\n", topStudent.id, topStudent.name, topStudent.grade);
                        break;
            }
            case 5:
                printf("\nBye bye!\n");
                return 1;
                break;
        }
    }

    return 0;
}
