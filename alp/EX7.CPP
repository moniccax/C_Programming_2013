#include <constream.h>
#include <stdlib.h>
#include <fstream.h>

void main() {

  clrscr();

  char linha[255];
  clrscr();
  ifstream arq("c:\\bc31\\bin\\exer3.txt");

  if(arq==NULL) {
    cout<<"\nErro";
    getch();
    exit(1);
  }

  while(!arq.eof()) {
    arq.getline(linha, sizeof(linha));
    cout<<"\n" <<linha;
    getch();
  }

   if(arq.fail()) {
    cout<<"\nErro";
    getch();
    exit(1);
  }

  arq.close();
  cout<<"\nArquivo lido";
  getch();

}