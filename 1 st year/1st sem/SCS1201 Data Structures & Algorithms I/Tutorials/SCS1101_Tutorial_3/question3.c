#include <stdio.h>
#include <string.h>

#define MAX 20
char stack[MAX];
int top = -1;

char pop() {
  if (top >= 0) return stack[top--];
}


int peek() {
  if (top >= 0) return stack[top];
}

void push(char value) {
  if (top < MAX)  stack[++top] = value;
}

int main() {
  char expr[20];
  expr[0] = '\0';

  printf("Enter the equation: ");
  char phr[20];
  scanf("%s", &phr);

  strncat(phr, ")", 1);
  push('(');

  int i;
  for (i = 0;i < strlen(phr);i++) {
    if (phr[i] == '(') {
      push('(');
    } else if ((phr[i] >= 48 && phr[i] <= 57) || (phr[i] >= 65 && phr[i] <= 90) || (phr[i] >= 97 && phr[i] <= 122)) {
      int len = strlen(expr);
      expr[len] = phr[i];
      expr[len + 1] = '\0';
    } else if (phr[i] == ')') {
       while (peek() != '(') {
        int len = strlen(expr);
        expr[len] = pop();
        expr[len + 1] = '\0';
      }
      pop();
    } else if (phr[i] == '+' || phr[i] == '-') {
      while (peek() != '(') {
       int len = strlen(expr);
       expr[len] = pop();
       expr[len + 1] = '\0';
      }
      push(phr[i]);
    } else if (phr[i] == '*' || phr[i] == '/' ) {
      push(phr[i]);
    }

  }
  int j;
  for (j = 0;j < strlen(expr);j++) {
    printf("%c", expr[j]);
  }
  printf("\n");
  return 0;
}

/*
  a) stack
  b) 32*4AB+*+
  c) AB+CD+*
  d) AB+C*DE-FG+*-
*/
