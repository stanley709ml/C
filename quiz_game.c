#include <stdio.h>
#include <ctype.h>
#include <stdio.h>

int main(){
	
	char questions[4][10000] = { {"\nIn what year was Stanley founded?\n"}, {"\nWhat is the value of x and y:\nx + y = 36\n"}, {"\nWhat operational system is most used for mobile devices?\n"}, {"\nIn a mathematical matrix, we have the formula defined as A = (Aij), where i and j stands for:\n"} };
	char options[4][10000] = { {"\nA. 1913\nB. 1924\nC. 1921\nD. 1910\n"}, {"\nA. x = 36 - y; y = 36 - x\nB. x = y - 36; y = 36 - x\nC. x = 36 + y; y = x + 36\nD. x = 36 + y; y = 36 - x\n"}, {"\nA. Windows\nB. MacOS\nC. Unix\nD. Linux\n"}, {"\nA. Columns and lines\nB. Lines and columns\nC. The first and last element from the matrix\nD. The last and first element from the matrix\n"}};
	char answerKey[4] = {'A', 'A', 'D', 'B'}; 
	char userAnswer0[4];
	char userAnswer[4];
	
	int total_correct_answers = 0, points = 0;
	
	for(int i = 0; i < 4; i++){
		printf("%s", questions[i]);
		printf("%s", options[i]);
		printf("");
		scanf(" %c", &userAnswer0[i]);

		userAnswer[i] = toupper(userAnswer0[i]); 
		
		if(userAnswer[i] == answerKey[i]){
			printf("\nCorrect!\n");
			total_correct_answers++;	
		}else{
			printf("\nIncorrect.\n");
		}
	}

	points = total_correct_answers * 5;

	printf("\nYou correctly answered %d questions and got a total points of %d\n", total_correct_answers, points);

	return 0;
}
