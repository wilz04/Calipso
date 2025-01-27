#ifndef DataBase_h
#define DataBase_h

#include "Grid.h"

typedef struct DataBase {
  char *url;
  Grid *first;
} DataBase;

gAdd(DataBase *base, Grid *grid) {
  if (base->first == NULL) {
    base->first = grid;
  } else {
    Grid *tmp = base->first;
    while (tmp->next != NULL) {
      tmp = tmp->next;
    }
    tmp->next = new_Grid(ln);
  }
}

DataBase *new_DataBase(char *url) {
  DataBase *dbTmp = (DataBase*) malloc(SIZE);
  dbTmp->url = url;
  FILE *file;
  char *ln = (char*) malloc(SIZE);
  Grid *gTmp;
  char *info = (char* malloc(SIZE));
  strcpy(info, url);
  strcat(info, "info.dat");
  if (file = fopen(info, "r")) {
    do {
      fscanf(file, "%s", ln);
      gTmp = new_Grid(ln);
      gAdd(dbTmp, gTmp);
    } while (!feof(file));
  }
  return dbTmp;
}

#endif

