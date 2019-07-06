#include <stdio.h>
#include <stdlib.h>
typedef struct node Node;

struct node
{
    int data;
    Node *next;
};

Node *root = NULL;

Node *createNewNode(int value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    return node;
}

void insertNode(int value)
{
    Node *newNode = createNewNode(value);

    if (root == NULL)
    {
        root = newNode;
        return;
    }
    Node *ptr = root;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = newNode;
}

void deleteNode(int value)
{
    Node *ptr = root;
    Node *preptr = root;

   while(ptr != NULL && ptr->data != value){
		if (ptr->next == NULL) {
			printf("Error:%d is not found!\n",value);
			return;
		}
		preptr = ptr;
		ptr = ptr->next;
	}

    preptr->next = ptr->next;
    free(ptr);
}


void printList()
{
    Node *ptr = root;
    while (ptr != NULL)
    {
        printf("%d", ptr->data);
        printf(ptr->next !=NULL?"->":"\n");
        ptr = ptr->next;
    }
}

int main()
{
    insertNode(2);
    insertNode(3);
    insertNode(4);
    insertNode(5);
    printList();
    deleteNode(3);
    printList();
}