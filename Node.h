#ifndef Node_h
#define Node_h

typedef struct Node {
  char *value;
  char *caption;
  struct Node *next;
} Node;

Node *new_Node(char *value, char *caption) {
  Node *tmp = (Node*) malloc(SIZE);
  tmp->value = value;
  tmp->caption = caption;
  tmp->next = NULL;
  return tmp;
}

#endif

