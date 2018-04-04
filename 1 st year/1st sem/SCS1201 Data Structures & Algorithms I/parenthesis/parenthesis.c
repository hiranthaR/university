#include <stdio.h>
#include <string.h>
typedef int bool;
#define true 1
#define false 0
#define MAX 50

int top = -1;
char stack[MAX];

bool isEmpty(){ return top == -1; }

bool isFull(){ return top == MAX -1; }

char pop(){
	if(!isEmpty()) return stack[top--];
	printf("Error:stackUnderFlowError!\n");
	return -1;
}

void push(char c){
	if (!isFull()) stack[++top] = c;
	else printf("Error:stackOverFlowError!\n");
}

void peek(){
	if(!isEmpty()) printf("%c\n", stack[top]);
	else printf("Error:stackUnderFlowError!\n");
}

bool match(char open,char close){
	return (open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']');
}

bool check(char question[]){
	char temp;
	bool flag = true;
	int i;
	for(i=0; i<sizeof(question); i++){
		temp = question[i];
		if(temp == '(' || temp == '[' || temp == '{') push(temp);
		if(temp == ')' || temp == ']' || temp == '}')
			if (!match(pop(),temp)){
				flag = false;
				break;
			}
	}
	if (!isEmpty()) flag = false;
	return flag;
}

int main(){

	char question[50];
	printf("Enter the Question: ");
	gets(question);
	
	if (check(question)) printf("Mached!\n");
	else printf("not matched!\n");

	return 0;
}