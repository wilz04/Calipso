#ifndef SQL_h
#define SQL_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void select() {
  int success = 0;
  char *cmd = (char*) malloc(SIZE);
  char *arg = (char*) malloc(SIZE);
  char *col = (char*) malloc(SIZE);
  char *val = (char*) malloc(SIZE);
  char *ord = (char*) malloc(SIZE);
  arg[0] = '\0';
  col[0] = '\0';
  while (strcmp(col, "Where")) {
    strcat(arg, col);
    scanf("%s", col);
  }
  scanf("%s", col);
  scanf("%s", cmd);
  if (!strcmp(cmd, "=")) {
    scanf("%s", val);
    scanf("%s", cmd);
    if (!strcmp(cmd, "Order")) {
      scanf("%s", cmd);
      if (!strcmp(cmd, "By")) {
        scanf("%s", ord);
        List *lTmp;
        Node *nTmp;
        if (!strcmp(ord, "Asc")) {
          lTmp = mega->head->next;
          printf(">\n");
          while (lTmp != NULL) {
            nTmp = lTmp->first;
            while (nTmp != NULL) {
              if (!strcmp(nTmp->value, col) && !strcmp(nTmp->caption, val)) {
                join(lTmp, arg);
                printf("\n");
                break;
              }
              nTmp = nTmp->next;
            }
            lTmp = lTmp->next;
          }
          printf("<\n");
          success++;
        } else if (!strcmp(ord, "Des")) {
          lTmp = mega->head;
          int i = 0;
          int j;
          while (lTmp->next->first != NULL) {
            lTmp = lTmp->next;
            i++;
          }
          printf(">\n");
          while (i != 0) {
            lTmp = mega->head;
            for (j=i; j!=0; j--) {
              lTmp = lTmp->next;
            }
            nTmp = lTmp->first;
            while (nTmp != NULL) {
              if (!strcmp(nTmp->value, col) && !strcmp(nTmp->caption, val)) {
                join(lTmp, arg);
                printf("\n");
                break;
              }
              nTmp = nTmp->next;
            }
            i--;
          }
          printf("<\n");
          success++;
        }
      }
    }
  }
  if (success) {
    printf("> Successful! <\n");
  } else {
    printf("> Bad Command <\n");
  }
}

void count() {
  int val = 0;
  char *col = (char*) malloc(SIZE);
  scanf("%s", col);
  List *lTmp = mega->head->next;
  Node *nTmp;
  printf("%s", "> ");
  while (lTmp != NULL) {
    nTmp = lTmp->first;
    while (nTmp != NULL) {
      if (!strcmp(nTmp->value, col)) {
        printf("%s, ", nTmp->caption);
      }
      nTmp = nTmp->next;
    }
    lTmp = lTmp->next;
  }
  printf("<\n> Successful! <\n");
}

void sum() {
  int val = 0;
  char *col = (char*) malloc(SIZE);
  scanf("%s", col);
  List *lTmp = mega->head->next;
  Node *nTmp;
  while (lTmp != NULL) {
    nTmp = lTmp->first;
    while (nTmp != NULL) {
      if (!strcmp(nTmp->value, col)) {
        val += atoi(nTmp->caption);
      }
      nTmp = nTmp->next;
    }
    lTmp = lTmp->next;
  }
  printf("> %i <\n> Successful! <\n", val);
}

void max() {
  int val = 0;
  char *col = (char*) malloc(SIZE);
  scanf("%s", col);
  List *lTmp = mega->head->next;
  Node *nTmp;
  while (lTmp != NULL) {
    nTmp = lTmp->first;
    while (nTmp != NULL) {
      if (!strcmp(nTmp->value, col)) {
        if (val < atoi(nTmp->caption)) {
          val = atoi(nTmp->caption);
        }
      }
      nTmp = nTmp->next;
    }
    lTmp = lTmp->next;
  }
  printf("> %i <\n> Successful! <\n", val);
}

Grid *exec(char *sql) {
  
}

void insert(char *sql) {
  
}

#endif

