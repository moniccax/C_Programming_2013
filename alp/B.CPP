#include <constream.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream.h>

struct registro{
  char nome[255];
  float real;
  int i;
};

void main(){
  ofstream arq("c:\\bc31\\bin\\bf.txt", ios::binary);
  if(arq.fail()){
    cout << "arquivo nao encontrado";
    getch();
    exit(1);
  }
  registro x;
 // for(int i=0; i<=255; x.nome[i]=255, i++);
  strcpy(x.nome, "momo linda");
  x.real=55.5;
  x.i=1;

  arq.write((char*)&x, sizeof(registro));
  if (arq.fail()){
    cout << "ERROR";
    getch();
    exit(1);
  }
  arq.close();
  cout << "Arquivo gravado";
  getch();
}