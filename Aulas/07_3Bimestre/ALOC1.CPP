/***************************************************************
 * Autor: Gilmar Machado Grossi                                *
 * Compilador: BC 3.1 Borland                                  *
 * Ambiente: Tela de scroll do DOS                             *
 * Modelo de memoria: Small                                    *
 * Data: 01/08/2011                                            *
 * Objetivo: Mostrar alocacao dinamica de memoria              *
 ***************************************************************/

// ----- Inclui as bibliotecas necessarias
#include <stdlib.h> // exit
#include <constream.h> // cin e cout

int main(void) {
  int* id;

  id=new int;
  if (!(id = new int)) {
    cout << "Memoria Insuficiente para alocar um inteiro\n\n";
    exit (1);
  }

  clrscr();
  cout << endl;
  cout << "Testando alocacao dinamica" << endl;
  for (*id=1; *id<=10; (*id)++)
    cout << "I=" << *id << endl;
  cout << "Tecle <enter> para terminar" << endl;
  getch();

  delete id; //destroi id; desaloca sizeof(int) bytes
  return(0);
}
