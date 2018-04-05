#include <stdio.h>
#include <string.h>

#define MAX 20
int stack[MAX];
int top = -1;

int pop() {
  if (top >= 0) return stack[top--];
}

void push(int value) {
  if (top < MAX)  stack[++top] = value;
}

int peek() {
  if (top >= 0) return stack[top];
}

int main() {
  printf("Enter the number: ");
  int n;
  scanf("%d", &n);

  while (n > 0) {
    push(n % 2);
    n /= 2;
  }

  while (top >= 0) printf("%d", pop());

  printf("\n");
  return 0;
}
