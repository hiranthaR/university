#include <stdio.h>

int main(){

	printf("\nEnter the array size: ");
	int size,i;

	scanf("%d",&size);
	
	int oder[size],reverse[size];

	for (i = 0; i < size; ++i){
		printf("Enter element %d: ", i);
		scanf("%d",&oder[i]);
	}

	for (i = 0; i < size; ++i){
		reverse[i] = oder[size-i-1];
	}

	printf("\n\nOder:\t\t");

	for (i = 0; i < size; ++i){
	printf("%d,\t",oder[i]);
	}

	printf("\nreverse:\t");

	for (i = 0; i < size; ++i){
	printf("%d,\t", reverse[i]);
	}

	printf("\n");
	return 0;

}