#include <constream.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream.h> // Para comandos de arquivos em C++

void main () {

  clrscr();

  int i;
  char tela[80][100];

  FILE* arq;
  arq=fopen("c:\\bc31\\bin\\ex3.txt", "w");

  if(arq==NULL) {
    printf("\n  Erro ao abrir o arquivo");
    getch();
    exit(1);
  }

  for(i=0; i<80; i++)
    strcpy(tela[i], "Uma linha\n");

  for (i=0; i<80; i++) {
    fputs(tela[i], arq);
//    fprintf(arq, "%s", tela[i]);
//    fwrite(&tela[i], strlen(tela[i]), 1, arq);
  }


  if(ferror(arq)) { // Checa se houve erro na gravacao
    printf("\n  Erro ao gravar no arquivo");
    exit(1);
  }

  fclose(arq);
  printf("\n  Arquivo gravado");
  getch();

}