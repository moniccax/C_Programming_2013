#include <constream.h>
#include <stdio.h>
#include <stdlib.h>

void main() {

  char linha[255];

  FILE* arq;

  arq=fopen("c:\dados\ex3.txt","r");

  if(arq==NULL) {
    cout<<"\nNao foi possivel abrir o arquivo";
    getch();
    exit(1);
  }

  while(!feof(arq)) {
    fgets(linha, 255, arq);
    cout<<linha;
    getch();
  }

  if(ferror(arq)) {
    cout<<"\nO arquivo nao pode ser lido";
    getch();
    exit(1);
  }

  fclose(arq);
  cout<<"\nArquivo lido";
  getch();

}