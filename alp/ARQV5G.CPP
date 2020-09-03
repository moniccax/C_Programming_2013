#include <constream.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream.h>

int main() {
  int i;
  float x;
  char ch, linha[255];
  ofstream arq("c:\\bc31\\bin\\dados.txt",ios::out, ios::binary);
  clrscr();
  if(arq.fail()){
    cout << "Erro ao abrir arquivo.\n";
    getch();
    exit(1);
  }
  i=1;
  x=1.4;
  arq << i;
  arq << x;
  i=2;
  x=2.2;
  arq << i;
  arq << x;
  i=5;
  x=2.5;
  arq << i;
  arq << x;
  arq.close();
  cout << "Arquivo Gravado";
  getch();
  return 0;
}
