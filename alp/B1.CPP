#include <constream.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream.h>

void main(){
  ifstream arq("c:\\bc31\\bin\\bf.txt", ios::binary);
  if (arq.fail()){
    cout << "Arquivo nao lido";
    getch();
    exit(1);
  }
  int i;
  float f;
  char c[255];
  arq.read((char*)&c, sizeof(c));
  cout << c << endl;
  arq.read((char*)&f, sizeof(f));
  cout << f << endl;
  arq.read((char*)&i, sizeof(i));
  cout << i << endl;
  if(arq.fail()){
    cout << "Arquivo nao lido";
    getch();
    exit(1);
  }
  arq.close();
  getch();
}