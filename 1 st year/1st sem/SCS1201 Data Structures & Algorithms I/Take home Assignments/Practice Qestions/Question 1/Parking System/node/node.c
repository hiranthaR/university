#include <stdio.h>
#include <stdlib.h>
#include "node.h"

Node *createNode(void *value){

	void *dupValue = malloc(sizeof(value));
	dupValue = value;

	Node *node = (Node*) malloc(sizeof(Node));
	node->left = NULL;
	node->right = NULL;
	node->value = dupValue;

	return node;
}

int deleteNode(Node *node){
	free(node-value);
	free(node);
}
