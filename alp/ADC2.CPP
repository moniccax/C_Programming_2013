/***************************************************************
 * Autor: Gilmar Machado Grossi                                *
 * Compilador: BC 3.1 Borland                                  *
 * Ambiente: Tela de scroll do DOS                             *
 * Modelo de memoria: Small                                    *
 * Data: 01/08/2011                                            *
 * Objetivo: Mostrar alocacao dinamica de memoria em C         *
 ***************************************************************/

// ----- Inclui as bibliotecas necessarias
/*
#include <alloc.h>
#include <process.h>
*/
#include <stdlib.h> // exit
#include <constream.h> // cin e cout

const int max=11;

int main(void) {
  int* v;
  v=(int*) malloc(sizeof(int)*max);
  clrscr();
  cout << endl;
  cout << "Testando alocacao dinamica" << endl;
  for (int i=1; i<=10; i++) {
    v[i]=i;
    cout << "I=" << v[i] << endl;
  }
  cout << "Tecle <enter> para terminar" << endl;
  getch();
  free(v); //destroi id e desaloca sizeof(int) bytes
  return(0);
}

