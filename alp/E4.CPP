#include <constream.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int  main(){
  int j;
  char c, ler[255];

  FILE *arq;
  arq = fopen("c:\\bc31\\bin\\Exer1.Txt","r");

  if(arq==NULL){
    printf("Erro ao abrir o arquivo");
    getch();
    exit(1);
  }

  c=fgetc(arq);
  while((!feof(arq)) && (c!='\n')){
    cout << c;
    c=fgetc(arq);
  }
  getch();

  if ferror (arq){
    cout << "Erro ao tentar ler";
    exit(1);
  }

  fclose(arq);
  cout << "\nArquivo Lido.";
  getch();
  return 0;
}