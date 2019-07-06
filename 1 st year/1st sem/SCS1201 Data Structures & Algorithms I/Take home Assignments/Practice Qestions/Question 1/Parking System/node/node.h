#ifndef __NODE_HEAD__
#define __NODE_HEAD__

typedef struct Node{

	struct Node *left;
	struct Node *right;
	void *value;	

} Node;

Node *createNode(void *value);

int deleteNode(Node *node);

#endif