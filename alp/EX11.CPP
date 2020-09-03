#include <constream.h>
#include <stdlib.h>
#include <fstream.h>

void main() {

  int inteiro;
  float real;
  char vet[10];

  clrscr();

  ifstream arq("c:\dados\ex8.dat" ,ios::binary);

  if(arq==NULL) {
    cout<<"\nNao foi possivel abrir o arquivo";
    getch();
    exit(1);
  }

  arq.read((char*) &inteiro, sizeof(int));
  cout<<"\n"<<inteiro;

  arq.read((char*) &real, sizeof(float));
  cout<<"\n"<<real;

  arq.read(vet, sizeof(vet));
  cout<<"\n"<<vet;

  getch();

  if(arq.fail()) {
    cout<<"\nErro na leitura";
    getch();
    exit(1);
  }

  arq.close();
  cout<<"\nArquivo lido";
  getch();
}
