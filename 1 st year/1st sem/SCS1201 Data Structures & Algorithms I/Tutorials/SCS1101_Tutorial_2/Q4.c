#include <stdio.h>

int main(){


	printf("\nEnter the array size: ");
	int size,i,oddLast=0,evenLast=0;

	scanf("%d",&size);
	
	int arr[size],odd[size],even[size];

	for (i = 0; i < size; ++i){
		printf("Enter element %d: ", i+1);
		scanf("%d",&arr[i]);
	}

	for (i = 0; i < size; ++i){
		if (arr[i]%2==0) even[evenLast++] = arr[i];
		else odd[oddLast++] = arr[i];
	}

	printf("\n\nThe Even elements are :\n");

	for (i = 0; i < evenLast; ++i) printf("%d ", even[i]);

	printf("\nThe Odd elements are :\n");

	for (i = 0; i < oddLast; ++i) printf("%d ", odd[i]);

	printf("\n");
	return 0;

}