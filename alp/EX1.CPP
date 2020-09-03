#include <constream.h>
#include <stdio.h>
#include <stdlib.h>

void main() {

  clrscr();

  char ch[]="Um teste";
  FILE* arq;
  arq=fopen("c:\dados\ex1.txt", "w");

  if(arq==NULL) {
    cout<<"\nNao foi possivel realizar a gravacao";
    getch();
    exit(1);
  }

  for(int i=0;ch[i]!='\0';i++) {
    fputc(ch[i], arq);
    cout<<""<<ch[i];
    getch();
  }

  if ferror(arq) {
    cout<<"\nOcorreu um erro";
    getch();
    exit(1);
  }

  fclose(arq);
  cout<<"\nArquivo gravado";
  getch();
}