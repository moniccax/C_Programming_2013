//Nao esta abrindo o arquivo para gravacao (???)
#include <constream.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream.h>

void main() {

  clrscr();

  int inteiro=5;
  float real=5.1;
  char vet[10]="Um nome";

  ofstream arq("c:\\bc31\\bin\\ex9.txt", ios::binary);

  if(arq==NULL) {
    cout<<"\nErro na abertura do arquivo";
    getch();
    exit(1);
  }

  arq.write((char*) &inteiro, sizeof(int));
  arq.write((char*) &real, sizeof(float));
  arq.write(vet, sizeof(vet));

  if(arq.fail()) {
    cout<<"\nErro na gravacao";
    getch();
    exit(1);
  }

  arq.close();
  cout<<"\nArquivo gravado";
  getch();

}