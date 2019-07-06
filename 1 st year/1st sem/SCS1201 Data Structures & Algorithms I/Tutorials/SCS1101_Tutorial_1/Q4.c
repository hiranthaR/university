#include <stdio.h>


int add(int n)
{
    if(n != 0) return n + add(n-1);
    return n;
}


int main()
{
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    printf("Sum = %d\n\n",add(num));
    return 0;
}

