#include <stdio.h>
#include <stdlib.h>
#define MAX 5
typedef int bool;
#define true 1
#define false 0

struct Queue{
	int front,rear,count,queue[MAX];
};


struct Queue* creatQueue(){
	struct Queue *q = malloc(sizeof(struct Queue));
	q -> front = 0; 
	q -> rear = 0; 
	q -> count = 0; 
}

bool isFull(struct Queue *q){ return q->count == MAX; }

bool isEmpty(struct Queue *q){ return q->count==0; }

int size(struct Queue *q){ return q->count; }

void deleteQueue(struct Queue *q){ free(q); }

void enqueue(struct Queue *q,int value){
	if (isFull(q)){
		printf("Error:overflow! \n");
		return;
	}
	q->queue[q->rear] = value;
	q->rear = (q->rear + 1) % MAX; 
	q->count++;
}

void displayQueue(struct Queue *q){
	if (isEmpty(q)){
		printf("Error:Queue empty!\n");
		return;
	}
	int i = q->front, j = q->count;

	for(;0 != j;j--){
		printf("%d %s",q->queue[i] , j == 1 ?"\n":",");
		i = (i+1) % MAX;
	}
}

int dequeue(struct Queue *q){
	if(isEmpty(q)){
		printf("Error:underflow!\n");
		return -1;
	}
	int value = q->queue[q->front];
	q->front = (q->front + 1) % MAX;
	q->count--;
	return value;
}

int peek(struct Queue *q){
    if(isEmpty(q)){
        printf("Cannot peek. Queue is empty.\n");
        return -1;
    }
 
    return q->queue[ q->front ];
}

void sortQueue(struct Queue *q){

	printf("\nsteps:\n");

	int n = q->count,i,j,x,y;

	for(i = 0 ; i < n ; i++){
		x = dequeue(q);
		for(j=0; j < n-1; j++){
			y = dequeue(q);

			if( x<y )
				enqueue(q,y);
			else{
				enqueue(q,x);
				x = y;
			} 
		}
		enqueue(q,x);
		displayQueue(q);
	}
}

int main(){

	struct Queue *queue = creatQueue();

	printf("Elements: ");
	enqueue(queue,8);
	enqueue(queue,1);
	enqueue(queue,7);
	enqueue(queue,6);
	enqueue(queue,0);
	displayQueue(queue);
	sortQueue(queue);
	printf("\nSorted Queue!: ");
	displayQueue(queue);

	deleteQueue(queue);
	return 0;
}