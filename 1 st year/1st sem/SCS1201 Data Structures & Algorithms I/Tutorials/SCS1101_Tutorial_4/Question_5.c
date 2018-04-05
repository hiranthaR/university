#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 255
typedef int bool;
#define true 1
#define false 0

struct Queue{
	int front,rear,count;
	char queue[MAX][30];
};


struct Queue* creatQueue(){
	struct Queue *q = malloc(sizeof(struct Queue));
	q -> front = 0; 
	q -> rear = 0; 
	q -> count = 0; 
}

bool isFull(struct Queue *q){
	if (q->count == MAX) return true;
	else return false;
}

bool isEmpty(struct Queue *q){
	if(q->count==0) return true;
	else return false;
}

void enqueue(struct Queue *q,char value[]){
	if (isFull(q)){
		printf("Error:overflow! \n");
		return;
	}
	strcpy(q->queue[q->rear], value);
	q->rear = (q->rear + 1) % MAX; 
	q->count++;
}

void displayQueue(struct Queue *q){
	if (isEmpty(q)){
		printf("Error:Queue empty!\n");
		return;
	}
	int i = q->front, j = q->count;

	printf("Elements in Queue:");
	for(;0 != j;j--){
		printf("%s ",q->queue[i]);
		i = (i+1) % MAX;
	}
	printf("\n");

}

const char* dequeue(struct Queue *q){
	if(isEmpty(q)){
		printf("Error:underflow!\n");
		return (const char*)-1;
	}
	char value[30];
	strcpy(value,q->queue[q->front]);
	q->front = (q->front + 1) % MAX;
	q->count--;
	return value;
}

const char* peek(struct Queue *q){
    if(isEmpty(q)){
        printf("Cannot peek. Queue is empty.\n");
        return (const char*)-1;
    }
 
    return q->queue[ q->front ];
}

int size(struct Queue *q){
    return q->count;
}

void deleteQueue(struct Queue *q){
    free(q);
}

const char* getWordFromReverse(struct Queue *q,int position){
	if(q->count<position) return "Error:no enough words!";
	int dec = q->count-position,i;
	for(i=0;i<dec;i++) dequeue(q);
	return peek(q);
}

int main(){

	struct Queue *queue = creatQueue();
	
	char str[100];
    char splitStrings[10][10]; //can store 10 words of 10 characters
    int i,j,cnt,position;
 
    printf("Enter a string: ");
    gets(str);
 
    j=0; cnt=0;
    for(i=0;i<=(strlen(str));i++){
     if(str[i]==' '||str[i]=='\0'){
            splitStrings[cnt][j]='\0';
            cnt++;  
            j=0; 
        }
        else{
            splitStrings[cnt][j]=str[i];
            j++;
        }
    }
   for(i=0;i < cnt;i++)
        enqueue(queue,splitStrings[i]);
    
    printf("Enter the nth position you needs from end: ");
    scanf("%d",&position);
    printf("%d word from end is: %s \n" , position, getWordFromReverse(queue,position));
    return 0;

}