#include <constream.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream.h>

void main(){
  ifstream arq("c:\\bc31\\bin\\cmaismais.txt", ios::binary);
  if (arq.fail()){
    cout << "Arquivo nao encontrado";
    getch();
    exit(1);
  }

  int i;
  float f;
  char c[25];
  arq.read((char*)&i, sizeof(i));
  cout << i;
  arq.read((char*)&f, sizeof(f));
  cout << f;
  arq.read((char*)&c, strlen(c));
  cout << c;

  getch();
}