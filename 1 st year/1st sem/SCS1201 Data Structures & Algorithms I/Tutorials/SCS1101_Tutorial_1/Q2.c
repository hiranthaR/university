#include <stdio.h>

int factorial(int n){

	if (n==1) return 1;
	return n * factorial(n-1);
}

int main(){

	int place;

	printf("\nenter the number: ");
	scanf("%d",&place);
	printf("factorial of %d is: %d\n\n", place , factorial(place));

	return 0;
}