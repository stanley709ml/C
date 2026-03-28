#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define FILE_NAME "students_record.txt"
#define WRITE_MODE "w"
#define READ_MODE "r"
#define NAME_SIZE 100

typedef float f32;

typedef struct {
	char name[NAME_SIZE];
	f32 grade;
} Student;

Student *addStudents(int *total_students);
Student *loadStudents(const char *file_name, int *total_students);
Student *addMoreStudents(const char *file_name, Student *students, int *total_students);
void saveStudents(const char *file_name, Student *students, int total_students);
void printStudents(Student *students, int total_students);

int main() {	

	FILE *file = fopen(FILE_NAME, READ_MODE);
	int total_students = 0;
	Student *students;

	if (!file) {
		printf("Looks like we will have to start from scratch.\n");
		students = addStudents(&total_students);
		printStudents(students, total_students);
		saveStudents(FILE_NAME, students, total_students);
		
		char get_yesNo0[10];
		char get_yesNo;	

		do {	

			printf("Do you want to add anymore students over there? (Y/N) ");
			fgets(get_yesNo0, sizeof(get_yesNo0), stdin);
			sscanf(get_yesNo0, " %c", &get_yesNo);	
			get_yesNo = toupper(get_yesNo);
		
			if (get_yesNo == 'N') {
				printf("Bye then.\n");
				return 1;
			}

			students = addMoreStudents(FILE_NAME, students, &total_students);
			printStudents(students, total_students);
			saveStudents(FILE_NAME, students, total_students);

		} while (get_yesNo == 'Y');

	} else {

		char get_yesNo01[10];
		char get_yesNo0;	

		printf("Looks like there's something there. Let's load it:\n");
		students = loadStudents(FILE_NAME, &total_students);
		printStudents(students, total_students);
		saveStudents(FILE_NAME, students, total_students);	

		do {
		
			printf("Do you want to add anymore students over there? (Y/N) ");
			fgets(get_yesNo01, sizeof(get_yesNo01), stdin);
			sscanf(get_yesNo01, " %c", &get_yesNo0);	
			get_yesNo0 = toupper(get_yesNo0);
		
			if (get_yesNo0 == 'N') {
				printf("Bye then.\n");
				return 1;	
			}

			students = addMoreStudents(FILE_NAME, students, &total_students);
			printStudents(students, total_students);
			saveStudents(FILE_NAME, students, total_students);
			
		} while (get_yesNo0 == 'Y');

	}
	
	free(students);

	return 0;
}

Student *addStudents(int *total_students) {
	Student *students;
	int ammount_students;
	char get_ammountStudents[20];
	char get_gradeOfStudent[10];

	do {
	
		printf("How many students do you want to register? ");
		fgets(get_ammountStudents, sizeof(get_ammountStudents), stdin);
		sscanf(get_ammountStudents, "%d", &ammount_students);	

		if (ammount_students <= 0) {
			printf("Invalid ammount of students, try again.\n");	
		}

	} while (ammount_students <= 0);

	students = malloc(ammount_students * sizeof(Student));

	if (students == NULL) {
		printf("Memory allocation failed (function: addStudents)\n");
		exit(1);
	}

	for (int i = 0; i < ammount_students; i++) {
		printf("What is the name of the %d student? ", i+1);
		fgets(students[i].name, sizeof(students[i].name), stdin);
		students[i].name[strcspn(students[i].name, "\n")] = '\0';

		printf("What is the grade of the %d student? ", i+1);
		fgets(get_gradeOfStudent, sizeof(get_gradeOfStudent), stdin);
		sscanf(get_gradeOfStudent, "%f", &students[i].grade);

		(*total_students)++;
	}

	return students;
}
Student *loadStudents(const char *file_name, int *total_students) {
	FILE *file = fopen(file_name, READ_MODE);
	Student *students;
	(*total_students) = 0;

	if (file == NULL) {
		printf("File not found (function: loadStudents)\n");
		exit(1);
	}	
	
	char buffer[1024];
	int ammount_students = 0;

	while (fgets(buffer, sizeof(buffer), file)) {
		ammount_students++;			
	}

	rewind(file);

	students = malloc(ammount_students * sizeof(Student));

	if (students == NULL) {
		printf("Memory allocation failed (function: loadStudents)\n");
		exit(1);
	}

	for (int i = 0; i < ammount_students; i++) {
		fgets(buffer, sizeof(buffer), file);
		sscanf(buffer, "%[^:]: %f", students[i].name, &students[i].grade);
		(*total_students)++;	
	}
	
	fclose(file);
	return students;	
}

Student *addMoreStudents(const char *file_name, Student *students, int *total_students) {
	int ammount_extra_students = 0;
	int m = 0;
	char get_extra_students[10];
	char get_gradeOf_extra_student[10];

	
	do {

		printf("How many more students do you want to add? ");
		fgets(get_extra_students, sizeof(get_extra_students), stdin);
		sscanf(get_extra_students, "%d", &ammount_extra_students);	
	
		if (ammount_extra_students <= 0) {
			printf("Invalid ammount of students.\n");
		}

	} while (ammount_extra_students <= 0);

	int ammount_students = ammount_extra_students + (*total_students);	

	students = realloc(students, ammount_students * sizeof(Student));

	if (students == NULL) {
		printf("Memory reallocation failed (function: addMoreStudents)\n");
		exit(1);
	}

	for (int i = (*total_students); i < ammount_students; i++) {
		printf("What is the name of the %d new student? ", m+1);
		fgets(students[i].name, sizeof(students[i].name), stdin);
		students[i].name[strcspn(students[i].name, "\n")] = '\0';

		printf("What is the grade of the %d new student? ", m+1);
		fgets(get_gradeOf_extra_student, sizeof(get_gradeOf_extra_student), stdin);
		sscanf(get_gradeOf_extra_student, "%f", &students[i].grade);

		(*total_students)++;
		m++;
	}

	return students;

}

void saveStudents(const char *file_name, Student *students, int total_students) {
	FILE *file = fopen(file_name, WRITE_MODE);
	
	if (file == NULL) {
		printf("File not found (function: saveStudents)\n");
		exit(1);
	}

	for (int i = 0; i < total_students; i++) {
		fprintf(file, "%s: %.1f\n", students[i].name, students[i].grade);
	}	

	fclose(file);
}
void printStudents(Student *students, int total_students) {
	
	for (int i = 0; i < total_students; i++) {
		printf("%s: %.1f\n", students[i].name, students[i].grade);
	}

}

