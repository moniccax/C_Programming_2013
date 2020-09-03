#include <constream.h>
#include <stdio.h>
#include <stdlib.h>

void main(){
  FILE *arq;
  arq = fopen("c:\\bc31\\bin\\Ex3.txt","r");
  if (arq==NULL){
    cout << "Arquivo nao enontrado";
    getch();
    exit(1);
  }

  char linha[255];
  while (!feof(arq)){
    fgets(linha,255,arq);
    cout << linha ;
    getch();
  }

  if (ferror(arq)){
    cout << "Arquivo nao lido.";
    getch();
    exit(1);
  }

  fclose(arq);
  cout << "\n\n\nArquivo lido";
  getch();
}