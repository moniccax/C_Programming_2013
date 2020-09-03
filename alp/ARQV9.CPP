#include <constream.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream.h>

void main(){
  FILE *arq;
  arq = fopen ("c:\\bc31\\bin\\Testando.txt", "w");
  if (arq == NULL) {
    cout << "Arquivo nao aberto.";
    getch();
    exit(1);
  }
  char string[255];
  cout << "\nDigite frase:";
  gets(string);
  while (strcmp(string, "Fim")!=0){
    fprintf(arq, "%s\n", string);
    cout << "\nDigite outra frase:";
    gets(string);
  }
  if ferror(arq){
    cout << "\nArquivo nao foi gravado";
    getch();
    exit(1);
  }
  else
    cout <<"\nArquivo gravado";
  fclose(arq);
  getch();
}