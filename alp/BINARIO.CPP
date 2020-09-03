#include <constream.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream.h>
#include <string.h>

void main(){
  ofstream arq("c:\\bc31\\bin\\exer9.dat", ios::binary);
  if (arq.eof()){
    cout << "ERROR";
    getch();
    exit(1);
  }

  int inteiro=65;
  float real=44.4;
  char string[10]="momolinda";

  arq.write((char*)&inteiro, sizeof(int));
  arq.write((char*)&real, sizeof(float));
  arq.write((char*)&string, strlen(string));
  if (arq.fail()){
    cout << "Erro ao gravar";
    getch();
    exit(2);
  }

  arq.close();
  cout << "Arquivo gravado";
  getch();

}