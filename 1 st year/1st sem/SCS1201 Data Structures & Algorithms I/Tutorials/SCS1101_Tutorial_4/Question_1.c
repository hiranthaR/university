#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 3
typedef int boolean;
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

boolean isFull(struct Queue *q){ return q->count == MAX; }

boolean isEmpty(struct Queue *q){ return q->count==0; }

int size(struct Queue *q){ return q->count; }

void deleteQueue(struct Queue *q){ free(q); }

void enqueue(struct Queue *q,char patient[]){
	if (isFull(q)){
		printf("Error: No more chairs to %s!\n" ,patient);
		return;
	}
	strcpy(q->queue[q->rear], patient);
	q->rear = (q->rear + 1) % MAX; 
	q->count++;
	printf("%s came!\n", patient);
}

void dequeue(struct Queue *q){
	if(isEmpty(q)){
		printf("Error: No patients!\n");
		return;
	}
	printf("%s is Leaving!\n", q->queue[q->front]);
	q->front = (q->front + 1) % MAX;
	q->count--;
}

int main(){

	struct Queue *queue = creatQueue();

	enqueue(queue,"John");
	enqueue(queue,"Kate");
	enqueue(queue,"Shankar");
	dequeue(queue);
	enqueue(queue,"Zara");
	enqueue(queue,"Jack");
	dequeue(queue);
	dequeue(queue);
	printf("\n%d patient%s waiting for doctor!\n", size(queue) , size(queue) == 1?" is":"s are");

	return 0;
}