#include <constream.h>
#include <math.h>
#include <stdio.h>

void func(char* (*p) (char *)){
  char nome[80];
  cout << "Nome: " << endl;
  (*p)(nome);
  cout << "Seu nome e': " << nome;
}

int main(){
  char *(*p)(char *);
  p=gets;
  func(p);
  getch();
  return 0;
}