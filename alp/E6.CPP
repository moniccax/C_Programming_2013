#include <constream.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void main(){
  FILE *arq;
  char b;
  arq = fopen("c:\\bc31\\bin\\exer3.txt", "r");

  if (arq == NULL){
    cout << "Arquivo nao encontrado.\n";
    getch();
    exit(1);
  }

  b=fgetc(arq);
  while (!feof(arq)){
    cout << b;
    b=fgetc(arq);
  }

  if (ferror(arq)){
    cout << "Erro ao ler arquivo.";
    getch();
    exit(1);
  }
  else
    cout << "\n\nArquivo lido com sucesso.";

  fclose(arq);
  getch();
}