#include <constream.h>
#include <stdio.h>
#include <stdlib.h>

void main(){
  float f=6.6;
  int i=1;
  char c[10]="momolinda";
  FILE *arq;
  arq = fopen("c:\\bc31\\bin\\bff","wb");
  if(arq==NULL){
    cout << "arq n encontrado";
    getch();
    exit(1);
  }
  fprintf(arq, "%s", c);
  fprintf(arq, "%f", f);
  fprintf(arq, "%d", i);
  if ferror(arq){
    cout << "ERROR";
    getch();
    exit(1);
  }
  fclose(arq);
}