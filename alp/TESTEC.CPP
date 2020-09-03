#include <constream.h>

void main(){
  clrscr();
  char x[255]="pao com queijo";
  cout << &x << endl;
  cout << x << endl;
  cout << (*(x+1));
  int a=2;
  int *ptra;
  ptra=&a;
  cout << ptra;
  //*************************************
  int qtd=20;
  int *pt;
  pt=&qtd;
  *pt=30;
  cout << "\n\t\t\t"<<qtd;
  //*************************************
  char nome[55]="igor";
  int n=2;
  cout << nome << endl;
  cout << (nome+2);
  getch();
}