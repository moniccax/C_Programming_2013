#include <constream.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int  main(){
  int i;
  char gravar[]="Exercicio numero 1 da lista 3.";

  FILE *arq;
  arq = fopen("c:\\bc31\\bin\\Exer1.Txt", "w");

  if(arq==NULL) {
    printf("Erro ao abrir o arquivo.\n");
    getch();
    exit(1);
  }

  for (i=0; gravar[i]; i++){
    //fputc(gravar[i], arq);
   // fprintf(arq, "%c", i);
    fwrite(&i, sizeof(i), 1, arq);
    cout << gravar[i];
    getch();
  }

  if (ferror(arq)){
    printf("Erro ao tentar gravar no arquivo.\n");
    exit(1);
  }

  fclose(arq);
  printf("\n\n\nArquivo Gravado.");
  getch();
  return 0;
}