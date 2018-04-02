## Integer Linked List implementaion with C language ##

# available functions #

> Create Node
this will create a new node and return it
```c
Node* createNewNode(int value);
```

> Delete Node
this will free the memory used by the node
```c
void deleteNode(Node *node);
```

> Is Empty
this will return 1 or 0 as list elements
```c
boolean isEmpty(Node* start);
```

> read value
this will read int and return it
```c
int readValue();
```

> Insert to End
this will add a node rest to the list
```c
Node* insert_end(Node *start,int value);
```

> Insert to front 
this will a node to front
```c
Node* insert_begin(Node *start,int value);
```

> Insert node before to a node
this will add a node before to a node
```c
Node* insert_before(Node *start,int value,int before);
```

> Insert node after a node
this will add new node after a specific node
```c
Node* insert_after(Node* start,int value,int after);
```

> delete node from begin
this will delete front node
```c
Node* delete_begin(Node *start);
```

> delete node from end
this will delete lst node from the lsit
```c
Node* delete_end(Node *start);
```

> delete a specific node 
this will delete a specific node from the list
```c
Node* delete_node(Node *start,int value);
```

> delete node after a node
this will delete the node after a specific node
```c
Node* delete_after(Node* start,int after);
```

> delete node before a node
this will delete the node before a specific node
```c
Node* delete_before(Node* start,int before);
```

> delete all list items
this will free the entire list
```c
Node* delete_list(Node* start);
```

> display list
this will show the list
```c
void displayList(Node *start);
```

> sort the list >
this will sort the list
```c
Node* sort_list(Node* start);
```

> main method <
the main function :smiley:
```c
int main();
```


