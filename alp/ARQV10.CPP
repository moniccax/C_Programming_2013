#include <constream.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream.h>

void main(){
  FILE *arq;
  arq = fopen ("c:\\bc31\\bin\\Testando.txt", "r");
  if (arq == NULL) {
    cout << "Arquivo nao aberto.";
    getch();
    exit(1);
  }

  char linha[255];
  while(!feof(arq)){
    fgets(linha, 255, arq);
    for (int i=0; linha[i]; i++);
    cout << linha;
    getch();
  }
  if ferror(arq){
    cout << "Error";
    getch();
    exit(1);
  }
  else
    cout << "\nArquivo lido";
  getch();
  fclose(arq);
}