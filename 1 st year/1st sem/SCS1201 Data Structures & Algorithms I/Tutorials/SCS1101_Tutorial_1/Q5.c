#include <stdio.h>

void pattern(int n){
	if (n==0) return;

	pattern(n-1);
	printf("%d",n);
	pattern(n-1);
}

int main(){

	int place;

	printf("enter the value:");
	scanf("%d",&place);

	pattern(place);
	printf("\n\n");
	return 0;
}