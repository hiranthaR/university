#include <stdio.h>

int gcd(int a,int b){
	if (b==0) return a;

	return gcd(b, a%b);
}

int main(){

	int n1;
	int n2;

	printf("Enter the 1st number: ");
	scanf("%d" , &n1);
	printf("Enter the 2nd number: ");
	scanf("%d" , &n2);

	printf("\ngcd for %d and %d is: %d\n\n" , n1 , n2 , gcd(n1,n2));

	return 0;
}