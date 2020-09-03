#include <constream.h>
#include <stdio.h>
#include <stdlib.h>

void main(){
  clrscr();
  FILE *arq;
  arq=fopen("c:\\bc31\\bin\\exer8.txt", "rb");
  if(arq==NULL){
    cout << "Arquivo nao encontrado";
    getch();
    exit(1);
  }

  int in;
  float fl;
  char st[255];

  //fscanf(arq, "%d", &in);
  fread(&in, sizeof(in), 1, arq);
  cout << in;
 // fscanf(arq, "%f", &fl);
  fread(&fl, sizeof(fl), 1, arq);
  cout << "  " << fl;
//  fscanf(arq, "%s", &st);
  fread(&st, sizeof(st), 1, arq);
  cout << "  " << st;

  if (ferror(arq)){
    cout << "ERROR.";
    getch();
    exit(1);
  }

  fclose(arq);
  cout << "\n\n\nArquivo lido";
  getch();
}