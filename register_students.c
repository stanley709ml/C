#include <stdio.h>
#include <string.h>

// Just a warning I think will be good:
// This program creates a file named 'workers-report.txt' inside whatever
// directory you executed this program.

typedef float f32;
typedef struct{
	char student_name[50];
	f32 student_grades[3];
	f32 medium_grades;
    f32 sum_grades;
	int passed_failed;
} Student;

void medium_grades_students(){

	int ammount_students;
    int total_students;
    int total_grades;
    int* pammount_students = &ammount_students;

	printf("How many students do you want to register? ");
	scanf("%d", &ammount_students);
	getchar();

	Student students[*pammount_students];
    total_students = sizeof(students) / sizeof(students[0]); 
       
    for (int i = 0; i < total_students; i++) {
          printf("What is the name of the %d student? ", i + 1);
          fgets(students[i].student_name, sizeof(students[i].student_name), stdin);
          students[i].student_name[strcspn(students[i].student_name, "\n")] = '\0';
            
          students[i].sum_grades = 0;

          for (int j = 0; j < 3; j++) {  
            printf("What is the %d grade of %s? ", j + 1, students[i].student_name);
            scanf("%f", &students[i].student_grades[j]);
            
            getchar(); 

            students[i].sum_grades += students[i].student_grades[j];
            students[i].medium_grades = students[i].sum_grades / 3;

            if(students[i].medium_grades >= 7){
                 students[i].passed_failed = 1;
            }else{
                students[i].passed_failed = 0;
            }
         }
     }
    
    for (int k = 0; k < total_students; k++) {

        if(students[k].passed_failed != 0){
            printf("The medium of the grades from student %s is a total of %.1f and is passed.\n", students[k].student_name, students[k].medium_grades); 
        }else{
            printf("The medium of the grades from the student %s is a total of %.1f and is failed.\n", students[k].student_name, students[k].medium_grades);
        }
      
    }
}

int main(){
    
    medium_grades_students();

    return 0;
}
