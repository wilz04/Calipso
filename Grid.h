#ifndef Grid_h
#define Grid_h

#include "List.h"

typedef struct Grid {
  List *head;
  struct Grid *next;
} Grid;

void nAdd(Grid *grid, Node *node) {
  if (grid->head->first == NULL) {
    grid->head->first = node;
  } else {
    List *lTmp = grid->head;
    while (lTmp->next != NULL) {
      lTmp = lTmp->next;
    }
    if (lTmp->first == NULL) {
      lTmp->first = node;
    } else {
      Node *nTmp = lTmp->first;
      while (nTmp->next != NULL) {
        nTmp = nTmp->next;
      }
      nTmp->next = node;
    }  
  }
}

void lAdd(Grid *grid, List *list) {
  if (grid->head->first == NULL) {
    grid->head = list;
  } else {
    List *tmp = grid->head;
    while (tmp->next != NULL) {
      tmp = tmp->next;
    }
    tmp->next = list;
  }
}

char *getValue(Grid *grid, int num) {
  if (grid->head->next != NULL) {
    Node *tmp = grid->head->first;
    int i;
    for (i=0; i!=num; i++) {
      tmp = tmp->next;
    }
    return tmp->caption;
  } else {
    return NULL;
  }  
}

void load(Grid *grid, char *url) {
  FILE *file;
  if (file = fopen(url, "r")) {
    char *data = (char*) malloc(SIZE);
    char *caption = (char*) malloc(SIZE);
    int value = 0;
    do {
      fscanf(file, "%s", data);
      int i;
      int j = 0;
      for (i=0; i<=strlen(data); i++) {
        if ((data[i] == ',') || (data[i] == '\0')) {
          caption[j] = '\0';
          nAdd(grid, new_Node((char*) getValue(grid, value), caption));
          caption = (char*) malloc(SIZE);
          j = 0;
          value++;
        } else {
          caption[j] = data[i];
          j++;
        }
      }
      value = 0;
      lAdd(grid, (List*) new_List());
    } while (!feof(file));
    fclose(file);
    printf("> Successful! <\n");
  } else {
    printf("> Bad Command <\n");
  }    
}

Grid *new_Grid(char *url) {
  Grid *tmp = (Grid*) malloc(SIZE);
  tmp->head = new_List();
  load(tmp, url);
  return tmp;
}

void gShow(Grid *grid) {
  if (grid->head->first == NULL) {
    printf("> Void <\n");
  } else {  
    printf(">\n");
    List *tmp = grid->head;
    while (tmp->first != NULL) {
      lShow(tmp);
      tmp = tmp->next;
    }
    printf("<\n");
  }
  printf("> Successful! <\n");
}

#endif

