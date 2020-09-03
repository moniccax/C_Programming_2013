#include <constream.h>
#include <stdio.h>
#include <stdlib.h>

void main(){
  FILE *arq;
  arq = fopen ("c:\\bc31\\bin\\ex8.txt","wb");
  if (arq==NULL){
    cout << "Arquivo nao foi criado.";
    getch();
    exit(1);
  }


  float f=2.5;
  int i=1;
  char vet[10]="Momo !!!!";

  fprintf(arq, "%d   ", i);
  fprintf(arq, "%f   ", f);
  fprintf(arq, "%s   ", vet);

  if (ferror(arq)){
    cout << "\nErro ao gravar";
    getch();
    exit(1);
  }

  fclose(arq);
  cout << "\nArquivo gravado";
  getch();
}