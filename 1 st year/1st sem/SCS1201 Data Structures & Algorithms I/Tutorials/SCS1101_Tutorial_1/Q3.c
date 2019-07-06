#include <stdio.h>

int cache[30];
int cacheAssigned[30];

int febonacci(int n){
	if (cacheAssigned[n] == 1) return cache[n];

	if (n==0 || n==1) return 1;

	cacheAssigned[n] = 1;
	cache[n] = febonacci(n-1) + febonacci(n-2);

	return cache[n];
}

int main(){

	int place;

	printf("Enter the value: ");
	scanf("%d",&place);

	for (int i = 0; i < place; ++i){
		printf("%d, ",febonacci(i));
	}

	printf("\n\n");
	return 0;
}