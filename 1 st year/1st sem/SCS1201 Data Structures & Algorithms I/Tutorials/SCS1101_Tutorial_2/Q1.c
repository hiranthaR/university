#include <stdio.h>

int main(){

	int i,ar[10],size=0;

	printf("\nEnter array size( must less than 10): ");
	scanf("%d",&size);

	if(size>10){
		printf("error: array out if size!\n\n");
		return 0;
	}

	printf("\n\n");

	for (i = 0; i < size; ++i){
		printf("Enter element %d: ", i);
		scanf("%d",&ar[i]);
	}

	int positive=0,negative=0,sum=0;
	float average = 0;

	printf("\n\n");

	for (i=0;i<size;i++){

		printf("%d,  ", ar[i]);
		if(ar[i]>0){
			positive += ar[i];
		} else {
			negative += ar[i];
		}
	}

	sum = positive + negative;
	average = (float) sum/size;

	printf("\n\nSum of all negative numbers = %d\n", negative );
	printf("Sum of all positive numbers = %d\n", positive );
	printf("Average of all input numbers = %f\n\n", average );

	return 0;
}