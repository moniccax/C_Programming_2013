#include <constream.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream.h>
#include <string.h>

struct registro{
  int i;
  float x;
  char n[255];
} ;

int main(){
  ofstream arq("c:\\bc31\\bin\\bin.txt", ios::binary);
  if (arq.fail()){
    cout << "Nao foi possivel abrir";
    getch();
    exit(1);
  }

  registro r;
  r.i=1;
  r.x=5 ;
  strcpy(r.n, "1 linha");
  arq.write((char*)&r, sizeof(registro));
  if (arq.fail()){
    cout << "nao gravou";
    getch();
    exit(1);
  }
  else
    cout <<"Arquivo gravado";
  getch();
  return 0;
}