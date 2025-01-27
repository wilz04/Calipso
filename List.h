#ifndef List_h
#define List_h

#include "Node.h"

typedef struct List {
  Node *first;
  struct List *next;
} List;

List *new_List() {
  List *tmp = (List*) malloc(SIZE);
  tmp->first = NULL;
  tmp->next = NULL;
  return tmp;
}

void lShow(List *list) {
  Node *tmp = list->first;
  while (tmp != NULL) {
    printf("%s, ", tmp->caption);
    tmp = tmp->next;
  }
  printf("\n");
}

void join(List *list, char *arg) {
  Node *tmp;
  char *col = (char*) malloc(SIZE);
  int i;
  int j = 0;
  for(i=0; i<=strlen(arg); i++) {
    if ((arg[i] != ',') && !(i == strlen(arg))) {
      col[j] = arg[i];
      j++;
    } else {
      col[j] = '\0';
      tmp = list->first;
      while (tmp != NULL) {
        if (!strcmp(tmp->value, col)) {
          printf("%s, ", tmp->caption);
        }
        tmp = tmp->next;
      }
      col = (char*) malloc(SIZE);
      j = 0;
    }
  }
}

#endif

