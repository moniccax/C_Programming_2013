#include <constream.h>
#include <stdio.h>
#include <stdlib.h>

void main() {

  clrscr();

  int inteiro;
  float real;
  char vet[10];

  FILE* arq;
  arq=fopen("c:\dados\ex9.dat","rb"); //Read Binary

  if(arq==NULL) {
    cout<<"\nNao foi possivel abrir o arquivo";
    getch();
    exit(1);
  }

  fread(&inteiro, sizeof(int), 1, arq);
  cout<<"\n"<<inteiro;

  fread(&real, sizeof(float), 1, arq);
  cout<<"\n"<<real;
  fread(vet, sizeof(vet), 1, arq);
  cout<<"\n"<<vet;

  if(ferror(arq)) {
    cout<<"\nErro ao gravar";
    getch();
    exit(1);
  }

  fclose(arq);
  cout<<"\nArquivo lido";
  getch();

}