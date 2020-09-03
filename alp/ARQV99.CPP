#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream.h>

void main(){
  ofstream arq("c:\\bc31\\bin\\T.txt", ios::in);
  if (arq.fail()){
    cout << "Arquivo nao encontrado";
    getch();
    exit(1);
  }
  char frase[255];
  cout <<  "\nEscreva uma frase:";
  gets(frase);
  while(strcmp(frase, "Fim.")!=0){
    for (int i=0; frase[i]; i++){
      arq.put(frase[i]);
      cout << frase[i];
      getch();
    }
    arq << "\n";
    cout <<  "\nEscreva outra frase";
    gets(frase);
  }
  if (arq.fail()){
    cout << "Arquivo nao salvo";
    getch();
    exit(1);
  }
  cout << "Arquivo gravado";
  arq.close();
  getch();
}