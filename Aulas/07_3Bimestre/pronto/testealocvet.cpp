#include <iostream>
#include <conio.h>

using namespace std;


char* rofl(){
  char *nome;
  nome = new char[80];
  cout << "Digite o nome da faixa: ";
  fflush(stdin);
  gets(nome);
  return nome;
}

int main(){
  char *p;
  int teste,i;
  char vet[1000][255];
  cout <<"\n \t digite o numero de faixas(max=1000): ";
  cin >> teste;
  for(i=0;i<teste;i++){
    p=rofl();
    strcpy(vet[i],p);
  }
  for(i=0;i<teste;i++){
    cout<<"\n nome da faixa: "<< vet[i];
  }
  getch();
  return 0;
}
