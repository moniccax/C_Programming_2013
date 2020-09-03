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
  ifstream arq("c:\\bc31\\bin\\dados.dat",ios::in, ios::binary);
  clrscr();
  if(arq.fail()){
    cout << "Erro ao abrir arquivo.\n";
    getch();
    exit(1);
  }
  while (!arq.eof()) {
    arq.read((char*)&r, sizeof(registro));
    cout << "i=" << r.i << endl;
    cout << "x=" << r.x << endl;
    cout << "n=" << r.n << endl;
  }
  arq.close();
  getch();
  return 0;
}
