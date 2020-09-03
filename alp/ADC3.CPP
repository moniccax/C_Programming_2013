/***************************************************************
 * Autor: Gilmar Machado Grossi                                *
 * Compilador: BC 3.1 Borland                                  *
 * Ambiente: Tela de scroll do DOS                             *
 * Modelo de memoria: Small                                    *
 * Data: 02/03/2011                                            *
 * Objetivo: Mostrar alocacao dinamica de memoria              *
 ***************************************************************/

// ----- Inclui as bibliotecas necessarias
#include <stdio.h> // printf e scanf
#include <stdlib.h>
#include <conio.h> // clrscr() e getch()
#include <constream.h> // cin e cout
#include <string.h> // strcpy

const int max=11;

struct registro {
  int cod;
  char nome[40];
  float valor;
}; // ----- struct pessoa

int main(void) {
  registro* v;
  v=(registro*) malloc(sizeof(registro)*max);
  clrscr();
  cout << endl;
  cout << "Testando alocacao dinamica" << endl;
  v[2].cod=5;
  strcpy(v[7].nome , "Teste");
  v[3].valor=2.5;
  cout  << "v[2].cod = " << v[2].cod << endl;
  cout << "v[7].nome = " << v[7].nome << endl;
  cout  << "v[3].valor = " << v[3].valor << endl;
  cout << "Tecle <enter> para terminar" << endl;
  getch();
  free(v);
  return(0);
}
