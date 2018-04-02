#include <stdio.h>
#include <stdlib.h>
typedef struct node Node;
typedef int boolean;
#define true 1
#define false 2

struct node{
	int data;
	struct node *next;
};	//structure to node

void deleteNode(Node *node){ free(node); } //free the memory location of a node

Node* createNewNode(int value){
	Node *node = (Node*) malloc(sizeof(Node));
	node->data = value;
	node->next = NULL;

	return node;	//returns a new node[ node(data:value,next:NULL) ]
}

boolean isEmpty(Node* start) { return start == NULL; } //retruns list is empty or not

Node* insert_end(Node *start,int value){

	Node *newNode = createNewNode(value);	//create a new node with value
	Node *ptr;

	if(start == NULL) start = newNode;
	else{
		ptr = start;
		while(ptr->next != NULL) ptr = ptr->next;
		ptr->next = newNode;
	}
	return start;
}

Node* insert_begin(Node *start,int value){

	Node *newNode = createNewNode(value);

	if(start == NULL) start = newNode;
	else{
		newNode->next = start;
		start = newNode;
	}

	return start;
}

Node* insert_before(Node *start,int value,int before){

	if (isEmpty(start)){
		printf("Error:underflow!\n");
		return start;
	}

	if (start->data == before) return insert_begin(start,value);

	Node *newNode = createNewNode(value),*ptr,*preptr;

	ptr = start;
	preptr = ptr;

	while(ptr->data != before){
		preptr = ptr;
		ptr = ptr->next;
		if(preptr->next == NULL){
			printf("Error:%d is not found!\n",before);
			return start;
		}
	}
	newNode->next = ptr;
	preptr->next = newNode;
	return start;
}

Node* insert_after(Node* start,int value,int after){

	if (isEmpty(start)){
		printf("Error:underflow!\n");
		return start;
	}

	Node *ptr,*preptr;

	ptr = start;
	preptr = ptr;
	Node *newNode = createNewNode(value);

	if(preptr->data == after){
		ptr = preptr->next;
		newNode->next = ptr;
		preptr->next = newNode;
		return start;
	}

	while(preptr->data != after){
		preptr = ptr;
		ptr = ptr->next;
		if(preptr->next==NULL) {
			if (preptr->data == after) return insert_end(start,value);
			printf("Error:%d is not found!\n",after);
			return start;
		}
	}
	newNode->next = ptr;
	preptr->next = newNode;
	return start;
}

int readValue(){
	printf("Enter a value: ");
	int n;
	scanf("%d",&n);
	return n;
}

Node* delete_begin(Node *start){
	
	if (isEmpty(start)){
		printf("Error:underflow!\n");
		return start;
	}

	Node *tmp;
	tmp = start;
	start = start->next;
	deleteNode(tmp);
	return start;
}

Node* delete_end(Node *start){

	if (isEmpty(start)){
		printf("Error:underflow!\n");
		return start;
	}

	Node *ptr = start,*preptr = start;

	while(ptr->next != NULL){
		preptr = ptr;
		ptr = ptr->next;
	}

	preptr->next = NULL;
	deleteNode(ptr);
	return start;
}

Node* delete_node(Node *start,int value){
	
	if (isEmpty(start)){
		printf("Error:underflow!\n");
		return start;
	}

	if (start->data == value) return delete_begin(start);

	Node *ptr,*preptr;
	ptr = preptr = start;

	while(ptr->data != value){
		if (ptr->next == NULL) {
			printf("Error:%d is not found!\n",value);
			return start;
		}
		preptr = ptr;
		ptr = ptr->next;
	}

	preptr->next = ptr->next;
	deleteNode(ptr);
	return start;
}

Node* delete_after(Node* start,int after){

	if (isEmpty(start)){
		printf("Error:underflow!\n");
		return start;
	}

	Node *ptr,*preptr;
	ptr = preptr = start;

	if(preptr->data == after){
		ptr = preptr->next;
		preptr->next = ptr->next;
		deleteNode(ptr);
		return start;
	}

	while(preptr->data != after){
		if (preptr->next == NULL){
			printf("Error:%d is not found!\n",after);
			return start;
		}
		preptr = ptr;
		ptr = ptr->next;
	}

	if (preptr->next==NULL){
		printf("Error:no value found after %d!\n",after);
		return start;
	}

	preptr->next = ptr->next;
	deleteNode(ptr);
	return start;
}

Node* delete_before(Node* start,int before){

	if (isEmpty(start)){
		printf("Error:underflow!\n");
		return start;
	}

	if(start->data == before){
		printf("Error:no value before %d!\n" , before);
		return start;
	}

	Node *ptr,*preptr,*ppretr;
	ppretr= preptr = ptr = start;

	if(preptr->next->data == before){
		start = preptr->next;
		deleteNode(ptr);
		return start;
	}

	while(ptr->data != before){
		if(ptr->next == NULL){
			printf("Error:%d is not found!\n",before);
			return start;
		}
		ppretr = preptr;
		preptr = ptr;
		ptr = ptr->next;
	}

	ppretr->next = ptr;
	deleteNode(preptr);
	return start;
}

Node* delete_list(Node* start){

	while(start!= NULL) start = delete_begin(start);
	return start;
}

void displayList(Node *start){

	if (isEmpty(start)){
		printf("Error:list is empty!\n");
		return;
	}

	Node *ptr = start;
	while(ptr->next != NULL){
		printf("%d, ", ptr->data);
		ptr = ptr->next;
	}
		printf("%d\n", ptr->data);
}

Node* sort_list(Node* start){

	if (isEmpty(start)){
		printf("Error:can't sort.list is empty!\n");
		return start;
	}

	Node *ptr1,*ptr2;
	int temp;

	ptr1 = start;

	while(ptr1 != NULL){
		ptr2 = ptr1->next;

		while(ptr2 != NULL){
			if(ptr1->data>ptr2->data){
				temp = ptr1 -> data;
				ptr1->data = ptr2->data;
				ptr2->data = temp;
			}
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
	return start;
}


int main(){

	printf("\n*** Linked List Implementation ***\n\n");
	Node *start1 = NULL;	//start point for new list

	printf("%s\n", isEmpty(start1) ? "list is empty!" : "list is not empty!" );	//cheak list empty or not

	//now list is empty.but I try to delete values from list.
	start1 = delete_begin(start1);		//deleting 1st node
	start1 = delete_end(start1);		//deleting last node
	start1 = delete_node(start1,56);	//deleting a value
	start1 = delete_before(start1,45);	//deleting node before a value
	start1 = delete_after(start1,67);	//deleting node after value
	start1 = delete_list(start1);		//deleting all list.nothing except
	//fine! all got Error:underflow!

	displayList(start1);				//printing the list

	printf("---------------------------------------\n\n");

	//cheak insert_before and insert_after at under flow condition 
	start1 = insert_before(start1,5,6);	//inserting 5 before 6
	start1 = insert_after(start1,5,6);	//inserting 5 after 6
	//fine! both got Error:underflow!

	displayList(start1);				//printing the list

	printf("---------------------------------------\n\n");

	//cheaking insert_begin Function:this will insert items to front
	start1 = insert_begin(start1,5);	//inserting 5 -> 5 : at NULL
	displayList(start1);
	start1 = insert_begin(start1,6);	//inserting 6 -> 6,5
	displayList(start1);
	start1 = insert_begin(start1,7);	//inserting 7 -> 7,6,5
	displayList(start1);
	//works fine :)

	printf("---------------------------------------\n\n");

	//deleting all list to cheack insert_after Function
	start1 = delete_list(start1);
	displayList(start1);
	//success! : deleteing list works fine!

	printf("---------------------------------------\n\n");

	//cheaking insert_end Function:this will insert items to end
	start1 = insert_end(start1,5);	//inserting 5 -> 5 : at NULL
	displayList(start1);
	start1 = insert_end(start1,6);	//inserting 6 -> 5,6
	displayList(start1);
	start1 = insert_end(start1,7);	//inserting 7 -> 5,6,7
	displayList(start1);
	//works fine :)

	printf("---------------------------------------\n\n");

	//adding more dummy data
	start1 = insert_end(start1,8);
	start1 = insert_end(start1,9);
	start1 = insert_end(start1,10);
	start1 = insert_end(start1,11);
	start1 = insert_end(start1,12);
	start1 = insert_end(start1,13);
	start1 = insert_end(start1,14);
	start1 = insert_end(start1,15);
	start1 = insert_end(start1,16);
	start1 = insert_end(start1,17);
	start1 = insert_end(start1,18);
	start1 = insert_end(start1,19);
	start1 = insert_end(start1,20);
	displayList(start1);
	//done!

	printf("---------------------------------------\n\n");

	//cheaking insert_before Function insert_before(list,value,target)
	start1 = insert_before(start1,76,5);	//insert before 1st value
	displayList(start1);	//success!
	start1 = insert_before(start1,77,12);	//insert before a middle value
	displayList(start1);	//success!
	start1 = insert_before(start1,78,20);	//insert before last value
	displayList(start1);	//success!
	start1 = insert_before(start1,79,100);	//insert before not related value
	//got the error:not found
	displayList(start1);	//success!
	//works fine for all possibilities.

	printf("---------------------------------------\n\n");

	//checking insert_after Function insert_before(list,value,target)
	start1 = insert_after(start1,80,76);		//insert after 1st value
	displayList(start1);	//success!
	start1 = insert_after(start1,80,13);	//insert after a middle value
	displayList(start1);	//success!
	start1 = insert_after(start1,82,20);	//insert after last value
	displayList(start1);	//success!
	start1 = insert_after(start1,83,100);	//insert after not related value
	//got the error:not found
	displayList(start1);	//success!
	//works fine for all possibilities.

	printf("---------------------------------------\n\n");

	//checking deleting funtions
	start1 = delete_begin(start1);			//deleting 1st element
	displayList(start1);
	start1 = delete_end(start1);			//deleting last element
	displayList(start1);
	start1 = delete_node(start1,13);		//deleting 1st element
	displayList(start1);
	//they are working

	printf("---------------------------------------\n\n");

	//checking delete_after function
	start1 = delete_after(start1,80);		//1st element
	displayList(start1);
	start1 = delete_after(start1,12);		//a middle element
	displayList(start1);
	start1 = delete_after(start1,20);		//last element
	displayList(start1);
	start1 = delete_after(start1,100);		//not related element
	displayList(start1);
	//nice worked :D

	printf("---------------------------------------\n\n");

	//checking delete_before function
	start1 = delete_before(start1,80);		//1st element
	displayList(start1);
	start1 = delete_before(start1,77);		//middle element
	displayList(start1);
	start1 = delete_before(start1,20);		//last element
	displayList(start1);
	start1 = delete_before(start1,100);		//not leated element
	displayList(start1);
	//gg working

	printf("---------------------------------------\n\n");

	//check sorting list	
	printf("Sorted list!\n");
	sort_list(start1);						//sorting
	displayList(start1);
	//worked

	printf("---------------------------------------\n\n");

	//removing all list
	start1 = delete_list(start1);			//empty list again
	displayList(start1);
	//working

	printf("---------------------------------------\n\n");

	//add 2 element and test sort function
	start1 = insert_end(start1,9);
	start1 = insert_end(start1,6);
	sort_list(start1);
	displayList(start1);
	//worked

	//check it for 1 element
	start1 = delete_node(start1,9);
	sort_list(start1);
	displayList(start1);
	//worked

	//now im going to sort empty list :D
	start1 = delete_node(start1,6);
	sort_list(start1);
	displayList(start1);



	return 0;
}