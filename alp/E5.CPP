#include <constream.h>
#include <stdlib.h>
#include <stdio.h>

void main(){
  clrscr();
  char ch;
  FILE *arq;
  arq = fopen("c:\\bc31\\bin\\exer2.txt","r");

  if (arq==NULL){
    cout << "Arquivo nao encontrado.\n";
    getch();
    exit(1);
  }

  ch=fgetc(arq);
  while ((!feof(arq)) && (ch!='\n')){
    cout << ch;
    ch = fgetc(arq);
    getch();
  }
  if (ferror(arq)){
    cout << "Arquivo nao lido." << endl;
    getch();
    exit(1);
  }
  else
    cout << "\n\nArquivo lido com sucesso.";

  fclose(arq);
  getch();
}