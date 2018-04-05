#include <stdio.h>

#define MAX 30
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
  printf("Enter the size of the Array (Less Than 30): ");
  int size,i;
  scanf("%d", &size);
  int arr[size];

  for (i = 0;i < size;i++) {
    printf("Enter element %d : ", i+1);
    scanf("%d", &arr[i]);
  }



  printf("\nElements: ");
  for (i = 0;i < size;i++) {
    printf("%d ", arr[i]);
    push(arr[i]);
  }

  for (i = 0;i < size;i++)  arr[i] = pop();

  printf("\nRevised Elements: ");
  for (i = 0;i < size;i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");

  return 0;
}
