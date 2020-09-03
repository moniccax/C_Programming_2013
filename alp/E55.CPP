#include <constream.h>
#include <fstream.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
  ifstream arq("Exer2.txt", ios::out);
  if (arq==NULL){
    cout << "Arquivo nao encontrado";
    getch();
    exit(1);
  }

  char letra;
  letra=arq.get();
  while (!arq.eof()){
    cout << letra;
    letra=arq.get();
    getch();
  }

  if (arq.fail()){
    cout << "Erro ao copiar caractere";
    exit(1);
  }

  arq.close();
  cout << "\n\n\nArquivo lido.";
  getch();

  return 0;
}