#include <stdio.h>
#include <string.h>

#define MAX 20
int stack[MAX];
int top = -1;

void push(int value) {
  if (top < MAX) stack[++top] = value;
}
int pop() {
  if (top >= 0) return stack[top--];
}
int peek() {
  if (top >= 0) return stack[top];
}

void main() {
  char phrase[20];
  printf("Enter the code: ");
  scanf("%s", &phrase);

  int hasError = 1,i, commented = 1;

  for (i = 0;i < strlen(phrase);i++) {
    if (phrase[i] == '/' && phrase[i+1] == '*') {
      commented = 0;
    } else if (phrase[i] == '*' && phrase[i+1] == '/') {
      commented = 1;
    }
    if (commented == 1) {
      if (phrase[i] == '[' || phrase[i] == '{' || phrase[i] == '(') {
        push(phrase[i]);
      } else if (phrase[i] == ']' || phrase[i] == '}' || phrase[i] == ')') {
        char val = pop();
        if ((phrase[i] == ']' && val != '[') || (phrase[i] == ')' && val != '(') || (phrase[i] == '}' && val != '{') ) {
            hasError = 0;
            break;
        }
      }
    }
  }
  if (hasError == 0 || top >= 0) {
    printf("Invalid Expression\n");
  } else {
    printf("Valid Expression\n");
  }
}

/*
  d) a) [(a+b)+c+d)*e-f; = Invalid Expression
     b) ((a+(b+c)+[p*q]); = Invalid Expression
*/
