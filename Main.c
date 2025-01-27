#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 128

#include "DataBase.h"

Grid *students;
Grid *signature;
Grid *carrier;
Grid *grades;

void init() {
  students = new_Grid("Base/Estudiantes.dat");
  signature = new_Grid("Base/Materias.dat");
  carrier = new_Grid("Base/Carreras.dat");
  grades = new_Grid("Base/Notas.dat");
}

int main(int argc, char *argv[]) {
  init();
  DataBase *db = new_DataBase("Base/Estudiantes.dat");
  int *cmd = 0;
  while (1) {
    scanf("%i", &cmd);
    switch ((int) cmd) {
      case 1:
        //exec("Select ");
        break;
      case 2:
        break;
      default:
        exit(0);
    }
  }
  return 0;
}

