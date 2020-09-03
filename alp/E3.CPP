#include <constream.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void main(){
  FILE *arq;
  arq = fopen("c:\\bc31\\bin\\Exer3.Txt", "w");

  if (arq==NULL){
    cout << "Arquivo nao encontrado.\n";
    getch();
    exit (1);
  }

  char tela[80][25];

  for (int i=0; i<80; i++)
    strcpy(tela[i], "Uma linha inteira.\n");

  for (i=0; i<80; i++)
//    fprintf (arq, "%s", tela[i]);
    fputs(tela[i], arq);

  if (ferror(arq)){
    printf ("Erro ao gravar.\n");
    getch();
  }
  else
    printf ("Arquivo Gravado");

  fclose(arq);
  getch();
}