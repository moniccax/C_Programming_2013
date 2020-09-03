#include <constream.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream.h>

void main() {

  clrscr();
  char ch[]="Um segundo teste";

  ofstream arq("c:\dados\ex2.txt");

  if(arq.fail()) {
    cout<<"\nOcorreu um erro";
    getch();
    exit(1);
  }

  for(int i=0;ch[i]!='\0';i++) {
    arq.put(ch[i]);
    cout<<""<<ch[i];
    getch();
  }
  arq.close();
  cout <<"\nArquivo gravado";
  getch();
}