#include <stdio.h>
#include <constream.h>
#include <fstream.h>
#include <stdlib.h>

void main(){
  ofstream arq("EX2.txt", ios::in);
  if (arq.fail()){
    cout << "Arquido nao foi gravado";
    getch();
    exit(1);
  }

  char string[]="Pao com queijo";

  for (int i=0; string[i]!='\0'; i++){
    arq.put(string[i]);
    cout <<""<< string[i];
    getch();
  }

  if(arq.fail()){
    cout << "Arquido nao foi gravado";
    getch();
    exit(1);
  }

  arq.close();
  cout << "\n\n\nArquivo gravado";
  getch();
}