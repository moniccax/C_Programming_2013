#include <constream.h>
#include <stdio.h>
#include <stdlib.h>

void main(){
  FILE *arq;
  arq = fopen("c:\\bc31\\bin\\ex8.txt","rb");
  if (arq==NULL){
    cout << "O arquivo nao foi encontrado.\n";
    getch();
    exit(1);
  }

  char linha[255];
  while (!feof(arq)){
    fscanf(arq, "%c", &linha);
    cout << *linha;
  }

  if (ferror(arq)){
    cout << "\nNao foi possivel ler o arquivo.";
    getch();
    exit(1);
  }

  fclose(arq);
  cout << "\n\nArquivo lido com sucesso";
  getch();
}