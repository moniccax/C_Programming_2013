#include <constream.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int  main(){
  int j;
  char grava[]="Gravando o segundo exercicio da lista 3";

  FILE *arq;
  arq = fopen("c:\\bc31\\bin\\Exer2.Txt", "w");

  if (arq==NULL){
    printf("Arquivo nao encontrado.");
    getch();
    exit(1);
  }

  for (j=0; grava[j]; j++)
   // fputc(grava[j], arq);
    fprintf(arq, "%c", grava[j]);


  if ferror(arq){
    printf("Erro ao gravar.");
    getch();
    exit(1);
  }

  fclose(arq);
  printf("Arquivo gravado.");
  getch();
  return 0;
}