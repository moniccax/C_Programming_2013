/*****************************************************************
 * Autor: Gilmar Machado Grossi                                  *
 * Compilador: BC 3.1 Borland                                    *
 * Ambiente: Tela de scroll do DOS                               *
 * Modelo de memoria: Small                                      *
 * Data: 11/05/2011                                              *
 * Objetivo: Ser um programa exemplo para as aulas de  algoritmo *
 *           e logica de programacao, mostrando o uso de pontei- *
 *	     ros na linguagem C.                                 *
 *****************************************************************/

// ----- Inclui as bibliotecas necessarias
#include <constream.h> // cin e cout
#include <stdio.h> // printf e scanf
#include <conio.h> // clrscr() e getch()
#include <process.h> // system(" ")

// ----- Programa Principal
int main() {
  int i, j, a, b, c;
  int* k, l;
  float x, y;
  float* z, w;
  clrscr();
  i=2;
  j=3;
  cout << "O valor de i=" << i << endl;
  *k=i+j;
  cout << "O endereco de i=" << &i << endl;
  cout << "O conteudo da memoria apontada por k=" << *k << endl;
  cout << "O endereco de k=" << &k << endl;
  k=&i;
  cout << "O endereco da memoria apontada por k=" << k << endl;



  getch();
  return 0;
}
