#include <constream.h>
#include <stdio.h>
#include <stdlib.h>   //exit()
#include <string.h>   //strlen

void main() {

  clrscr();

  int inteiro=5;
  float real=5.1;
  char vet[10]="Um nome";

  FILE* arq;
  arq=fopen("c:\dados\ex8.txt", "wb"); //Write Binary

  if(arq==NULL) {
    cout<<"\nErro na gravacao";
    getch();
    exit(1);
  }

  fwrite(&inteiro, sizeof(int), 1, arq);
  fwrite(&real, sizeof(float), 1, arq);
  fwrite(vet, strlen(vet), 1, arq);


  if(ferror(arq)) {
    cout<<"\nErro na gravacao";
    getch();
    exit(1);
  }
  fclose(arq);
  cout<<"\nArquivo gravado";
  getch();

}
