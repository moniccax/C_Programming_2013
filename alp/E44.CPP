#include <constream.h>
#include <stdio.h>
#include <stdlib.h>

void main(){
  FILE *arq;
  arq = fopen("c:\\bc31\\bin\\exer1.txt","r");

  if(arq==NULL){
    cout << "Arquivo nao encontrado" ;
    getch();
    exit(1);
  }

 // char linha; //funciona para fgetc
  char linha[255]; //fgets e fscanf

  //linha=fgetc(arq);

  while(!feof(arq)) {

  //  fgets(linha, 2, arq);
    fscanf(arq, "%c", &linha);
    cout<<""<< linha;
  //  linha=fgetc(arq);
    getch();

  }

  if (ferror (arq)){
    cout << "\n\nArquivo nao lido.";
    getch();
    exit(1);
  }

  cout << "Arquivo lido";
  getch();
}