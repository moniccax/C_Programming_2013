#include <constream.h>
#include <stdio.h>
#include <stdlib.h>

void main(){
  FILE *arq;
  arq=fopen("c:\\bc31\\bin\\exer8.txt", "wb");

  if (arq==NULL){
    cout << "Arquivo nao encontrado";
    getch();
    exit(1);
  }

  int i=10;
  float f=88.8;
  char s[10]="Momo gata";

  fprintf(arq, "%d   ", i);
  fprintf(arq, "%f   ", f);
  fprintf(arq, "%s   ", s);
 // fwrite(&i, sizeof(i), 1, arq);
 // fwrite(&f, sizeof(f), 1, arq);
 // fwrite(&s, sizeof(s), 1, arq);
  if (ferror(arq)){
    cout << "Nao foi possivel gravar arquivo";
    getch();
    exit(1);
  }

  fclose(arq);
  cout << "Arquivo gravado";
  getch();
}