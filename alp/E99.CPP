#include <constream.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream.h>

struct pessoa{
  int i;
  float f;
  char c[10];
};

void main(){
  ifstream arq("c:\\bc31\\bin\\Cmaismais.txt", ios::binary);
  if (arq.fail()){
    cout << "Erro ao abrir"<<endl;
    getch();
    exit(1);
  }
  pessoa x;

  x.i=5;
  x.f=77.7;
  strcpy(x.c, "kibaoum");

  arq.write((char*) &x, sizeof(pessoa));

  if (arq.fail()){
    cout << "ERROR";
    getch();
  }
  else {
    arq.close();
    cout << "\n\nPronto";
  }
  getch();
}