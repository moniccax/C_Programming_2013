#include <constream.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream.h>

void main() {
  int i;
  char ch, linha[255];
  ifstream arq("c:\\bc31\\bin\\texto2.txt",ios::in);
  clrscr();
  if(arq.fail()){
    cout << "Erro ao abrir arquivo.\n";
    getch();
    exit(1);
  }
  ch=arq.get();
  while((!arq.eof())&&(ch!='\n')){
    cout << ch;
    ch=arq.get();
  }
  cout << '\n';
  getch();
  arq.getline(linha, 2);
//  while (!arq.eof()) {
  while (!arq.eof() && (linha[0]!='\n')) {
    cout << linha;
    arq.getline(linha, 2);
//    if (linha[0]=='\0') {
//      cout << endl;
//      arq.getline(linha, 2);
//    }
  }
  getch();
}
