#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream.h>

void main(){
  ifstream arq("c:\\bc31\\bin\\ex3.txt");
  if(arq.fail()){
    cout << "Arquivo nao encontrado";
    getch();
    exit(1);
  }
  char frase[255];
  while (!arq.eof()){
     arq.getline(frase, sizeof(frase));
     cout << frase;
  }
  if(arq==NULL){
    cout << "Arquivo nao lido";
    getch();
    exit(1);
  }
  arq.close();
  cout << "\n\nArquivo lido";
  getch();
}