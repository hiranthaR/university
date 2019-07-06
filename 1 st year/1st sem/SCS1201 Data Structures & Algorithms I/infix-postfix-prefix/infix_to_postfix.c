#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 30
typedef struct stack Stack;

struct stack{
	int top;
	char data[MAX];
};

Stack* createStack(){
	Stack *stack = malloc(sizeof(Stack));
	stack->top = -1;
	return stack;
}

void deleteStack(Stack *stack){ free(stack); }
int isEmpty(Stack *stack){ return stack -> top == -1; }
int isFull(Stack *stack){ return MAX-1 == stack -> top; }
char peek(Stack *stack){ return stack->data[stack->top];}

void push(Stack *stack,char c){
	if(!isFull(stack))
		stack->data[++(stack->top)] = c;
}

char pop(Stack *stack){
	if (!isEmpty(stack))
		return stack->data[stack->top--];
}

void display(Stack *stack){

	if(isEmpty(stack)) return;
	int i;
	for(i =0;i<=stack->top;i++){
		printf("%c", stack->data[i]);
	}
	printf("Here\n");
}

const char * toPostfix(char q[]){

	Stack *stack = createStack();
	Stack *postfix = createStack();
	push(stack,'(');
	strncat(q,")",1);

	int i;
	for(i=0; i< strlen(q); i++){
		if(q[i] == '(')
			push(stack,q[i]);
		else if((q[i]>=48 && q[i]<=57) || (q[i]>=65 && q[i]<=90) || (q[i]>=97 && q[i]<=122) )
			push(postfix,q[i]);
		else if(q[i] == ')'){
			while (peek(stack) != '('){
				if(isEmpty(stack)) break;
				push(postfix,pop(stack));
			}
			pop(stack);
		} else if (q[i] == '+'|| q[i] == '-'){
			while (peek(stack) != '(') push(postfix,pop(stack));
			push(stack,q[i]);
		} else if (q[i] == '*'|| q[i] == '/'|| q[i] == '%')
			push(stack,q[i]);
	}

	if(!isEmpty(stack)){
		printf("Error: %d\n",stack->top);
		return "\0";
	}

	strcpy(q,"");
	strncat(q,"A",1);
	while(!isEmpty(postfix)) push(stack,pop(postfix));
	// printf("%s\n", q);
	while(!isEmpty(stack)) printf("%c",pop(stack));

	deleteStack(stack);
	deleteStack(postfix);
	return q;
}

int main(){

	char *q[30];

	printf("Enter the question: ");
	gets(q);

	printf("%s\n", toPostfix(q));
	// toPostfix(q);

// A-(B/C+(D%E*F)/G)*H

	return 0;
}