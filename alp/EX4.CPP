#include <constream.h>
#include <stdio.h>
#include <stdlib.h>

void main() {

  clrscr();

  char ch;
  FILE* arq;

  arq=fopen("c:\dados\ex1.txt", "r");

  if(arq==NULL) {
    cout<<"\nErro na abertura";
    getch();
    exit(1);
  }
  while(!feof(arq)) {
    ch=fgetc(arq);
    cout<<""<<ch;
    getch();
  }

  if(ferror(arq)) {
    cout<<"\n O arquivo nao pode ser lido";
    getch();
    exit(1);
  }

  fclose(arq);
    cout<<"\nArquivo lido";
    getch();
}