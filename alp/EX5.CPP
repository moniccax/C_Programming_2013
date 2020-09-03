#include <constream.h>
#include <fstream.h>
#include <stdio.h>
#include <stdlib.h>

void main () {

  clrscr();

  char ch;
  ifstream arq("c:\dados\ex2.txt");

  if(arq.fail()) {
   cout<<"\nNao foi possivel realizar a leitura";
   getch();
   exit(1);
  }

  while(!arq.eof()) {
    ch=arq.get();
    cout<<""<<ch;
    getch();
  }

  if(arq.fail()) {
    cout<<"\nO arquivo nao pode ser lido";
    getch();
    exit(1);
  }
  arq.close();
  cout<<"\nArquivo lido" ;
  getch();
}