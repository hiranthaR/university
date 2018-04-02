## Integer Linked List implementaion with C language ##

# available functions #

- Create Node
  - this will create a new node and return it
```c
Node* createNewNode(int value);
```

- Delete Node
  - This will free the memory used by the node
```c
void deleteNode(Node *node);
```

- Is Empty
  - this will return 1 or 0 as list elements
```c
boolean isEmpty(Node* start);
```

- read value
  - This will read int and return it
```c
int readValue();
```

- Insert to End
  - This will add a node rest to the list
```c
Node* insert_end(Node *start,int value);
```

- Insert to front 
  - This will a node to front
```c
Node* insert_begin(Node *start,int value);
```

- Insert node before to a node
  - This will add a node before to a node
```c
Node* insert_before(Node *start,int value,int before);
```

- Insert node after a node
  - This will add new node after a specific node
```c
Node* insert_after(Node* start,int value,int after);
```

- delete node from begin
  - This will delete front node
```c
Node* delete_begin(Node *start);
```

- delete node from end
  - This will delete lst node from the lsit
```c
Node* delete_end(Node *start);
```

- delete a specific node 
  - This will delete a specific node from the list
```c
Node* delete_node(Node *start,int value);
```

- delete node after a node
  - This will delete the node after a specific node
```c
Node* delete_after(Node* start,int after);
```

- delete node before a node
  - This will delete the node before a specific node
```c
Node* delete_before(Node* start,int before);
```

- delete all list items
  - This will free the entire list
```c
Node* delete_list(Node* start);
```

- display list
  - This will show the list
```c
void displayList(Node *start);
```

- sort the list >
  - This will sort the list
```c
Node* sort_list(Node* start);
```

- main method <
  - The main function :smiley:
```c
int main();
```


