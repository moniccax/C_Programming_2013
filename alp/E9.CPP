#include <constream.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
  FILE *arq;
  arq = fopen("c:\\bc31\\bin\\ex9.txt", "wb");
  if (arq==NULL){
    cout << "Arquivo nao encontrado.\n";
    getch();
    exit(1);
  }

  int inteiro=5;
  float real=7.4;
  char vetor[10]="paoearroz";

  fputs(vetor, arq);
 // fwrite(&vetor, strlen(vetor), 1, arq);
  fprintf(arq, "%d   ", inteiro);
 // fwrite(&inteiro, sizeof(int), 1, arq);
  fprintf(arq, "%f  ", real);
 // fwrite(&real, sizeof(float), 1, arq);

  if (ferror(arq)){
    cout << "Gravacao nao foi efetuada.";
    getch();
    exit(1);
  }

  fclose(arq);
  cout << "\nArquivo gravado.";
  getch();
}
