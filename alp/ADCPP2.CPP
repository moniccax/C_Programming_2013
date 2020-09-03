// ----- Inclui as bibliotecas necessarias
#include <stdlib.h> // exit
#include <constream.h> // cin e cout
const int max=11;
int main(void) {
  int* v; // ----- alocando um vetor de inteiros dinamico
  v=new int [max];
  if (v==NULL) {
    cout << "Memoria Insuficiente para alocar um inteiro\n\n";
    exit (1);
  }
  clrscr();
  cout << endl;
  cout << "Testando alocacao dinamica" << endl;
  for (int i=1; i<=10; i++) {
    v[i]=i;
    cout << "I=" << v[i] << endl;
  }
  cout << "Tecle <enter> para terminar" << endl;
  getch();
  delete v; //destroi v; desaloca max*sizeof(int) bytes
  return(0);
}
