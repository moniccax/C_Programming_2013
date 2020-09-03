#include <constream.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct registro{
  int i;
  float f;
  char c[255];
};

void main(){
  registro x;
  x.i=1;
  x.f=2.6;
  strcpy(x.c, "1 linha") ;
  FILE *arq;
  arq=fopen("c:\\bc31\\bin\\binc.txt", "wb");
  if(arq==NULL){
    cout << "arquivo nao encontrado";
    getch();
    exit(1);
  }
  fprintf(arq, "%d", x.i);
  fprintf(arq, "%f", x.f);
  fprintf(arq, "%s", x.c);
  if (ferror(arq)){
    cout <<"Arquivo nao foi aberto";
    getch();
    exit(1);
  }
  fclose(arq);
  cout << "Arq gravado";
  getch();
}