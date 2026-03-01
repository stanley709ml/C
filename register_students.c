#include <stdio.h>
#include <string.h>

// THIS IS INCOMPLETE. I SHOULD FINISH IT BY TODAY.

typedef float f32;
typedef struct{
	char student_name[50];
	f32 student_grades[3];
	f32 medium_grades;
	int passed_failed;
} student;

int main(){

	int ammount_students;
	int* pammount_students = &ammount_students;

	printf("How many students do you want to register? ");
	scanf("%d", &ammount_students);
		
	student students[*pammount_students];
	
	int total_students = sizeof(students) / sizeof(students[0]);

	if(total_students <= 0){
		printf("Okay, no students will be registered.\n");
	}else{
		printf("The ammount of students in this class is a total of %d\n", total_students);
	}	
	return 0;
}
