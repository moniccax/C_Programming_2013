/*****************************************************************
 * Autor: Gilmar Machado Grossi                                  *
 * Compilador: BC 3.1 Borland                                    *
 * Ambiente: Tela de scroll do DOS                               *
 * Modelo de memoria: Small                                      *
 * Data: 17/03/2011                                              *
 * Objetivo: Ser um programa exemplo para problemas de calculo   *
 *           de series numericas.                                *
 *****************************************************************/

// ----- Inclui as bibliotecas necessarias
#include <constream.h> // clrscr() , getch() , cout , cin
#include <stdio.h> // printf e scanf

// ----- Programa Principal
int main() {
  int num, den;
  float termo, soma;
  clrscr();
  printf ("\n\n          Calculo da Serie do Ex 1.12.24\n\n");
  for (num=1, den=1; den<=50; num+=2, den++) {
    termo=float(num)/float(den);
    soma+=termo;
  }
  cout << "A Soma da serie e : " << soma << endl;
  printf ("\nTecle <enter> p/ sair\n");
  getch();
  return 0;
}
