#include <constream.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream.h>

struct registro {
  int i;
  float x;
  char n[255];
};

int main() {
  registro r;
  ofstream arq("c:\\bc31\\bin\\dados.dat",ios::out, ios::binary);
  clrscr();
  if(arq.fail()){
    cout << "Erro ao abrir arquivo.\n";
    getch();
    exit(1);
  }
  for (int i=0; i<=255; r.n[i]=255, i++);
  r.i=1;
  r.x=1.0;
  strcpy(r.n, "1 linha");
  arq.write((char*)&r, sizeof(registro));
  r.i=2;
  r.x=2.0;
  strcpy(r.n, "2 linha");
  arq.write((char*)&r, sizeof(registro));
  r.i=5;
  r.x=2.5;
  strcpy(r.n, "3 linha");
  arq.write((char*)&r, sizeof(registro));

  arq.close();
  cout << "Arquivo Gravado";
  getch();
  return 0;
}
