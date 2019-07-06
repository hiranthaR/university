#include <stdio.h>

int main(){

	int grades[2][5];
	char subject[2][20] = {"Mathematics","Physics"};

	printf("enter Mathematics marks of students\n\n");

	for (int i = 0;i<5;i++){
		scanf("%d",&grades[0][i]);
	}

	printf("\n");

	printf("enter Physics marks of students\n\n");

	for (int i = 0;i<5;i++){
		scanf("%d",&grades[1][i]);
	}

	printf("\n\n");

	for (int i = 0;i<2;i++){
		
		float average;
		int total = 0;

		for (int j = 0;j<5;j++){
			total += grades[i][j];
		}

		average = total/5.0;
		printf("The average of %s is: %f \n\n",subject[i] , average);
	}

	return 0;
}