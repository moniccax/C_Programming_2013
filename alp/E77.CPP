#include <constream.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream.h>

void main(){
  ifstream arq("c:\\bc31\\bin\\exx8.txt", ios::out);
  if(arq.fail()){
    cout << "Arquivo nao encontrado";
    getch();
    exit(1);
  }

  char frase[255];

  while (!arq.eof()){
     arq.getline(frase, sizeof(frase));
     cout <<"\n"<< frase;
     getch();
  }
  if (arq.fail()){
    cout << "Arquivo nao lido";
    getch();
    exit(1);
  }

  arq.close();
  cout << "\n\nArquivo lido";
  getch();
}