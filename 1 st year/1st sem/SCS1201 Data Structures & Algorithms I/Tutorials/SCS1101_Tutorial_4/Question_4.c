#include <stdio.h>
#include <stdlib.h>
#define MAX 255
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

int getJosephusPlace(struct Queue *q,int m){
	
	struct Queue *temp = creatQueue();

	int i,n;

	for (i = 0; i < q->count;i++){
		n = dequeue(q);
		enqueue(q,n);
		enqueue(temp,n);
	}

	while(temp->count != 1){
		for(i=0;i<m-1;i++) enqueue(temp,dequeue(temp));
		dequeue(temp);
	}

	n = dequeue(temp);
	deleteQueue(temp);

	return n+1;
}

int main(){

	struct Queue *queue = creatQueue();
	
	int i=0,n,m;

	printf("Enter the people count: ");
	scanf("%d",&n);
	printf("Enter the mth one: ");
	scanf("%d",&m);

	for (;i<n;i++) enqueue(queue,i);

	printf("Queue: ");
	displayQueue(queue);
	int place = getJosephusPlace(queue,m);
	printf("\nJosephus needs to sit %d place to avoid being eliminated.\n", place);
	
	deleteQueue(queue);

}