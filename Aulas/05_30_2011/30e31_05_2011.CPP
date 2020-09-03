/*****************************************************************
 * Autor: Gilmar Machado Grossi                                  *
 * Compilador: gcc no Linux Ubuntu 10.04                         *
 * Ambiente: Tela de scroll da Konsole                           *
 * Modelo de memoria: Small                                      *
 * Data: 06/06 e 07/06 de 2011                                   *
 * Objetivo: Ser um programa exemplo para as aulas praticas de   *
 *           algoritmo e logica de programacao, mostrando a      *
 *	     sobrecarga de operadores.                           *
 *****************************************************************/

// ----- Inclui as bibliotecas necessarias

#include <iostream> // cout, cin, endl
#include <stdio.h> // printf e scanf
#include <stdlib.h> // 
#include <string.h> // funcoes para manipulacao de vetor de char
#include <fstream> // funcoes de arquivo em C++
#include <math.h>

using namespace std;

// --------------- Declaracao de variaveis globais
#define esc 27
#define clrscr() system("clear")
#define getch() system("read a")

class cplx {
  private:
    int r, i;

  public:
    cplx(int r0=0, int i0=0) : r(r0), i(i0){} // ----- Construtor
    void igual(int x, int y) {
      r=x;
      i=y;
    }
    void print() const { // ----- Escreve parte real e parte imaginaria na tela
      cout << r;
      cout << "+j" << i << endl;
    }
    cplx operator +(cplx& c) const { // ----- Sobrecarga operador adicao
      cplx temp;
      temp.r=r+c.r;
      temp.i=i+c.i;
      return temp;
    }
    cplx operator -(cplx& c) const { // ----- Sobrecarga operador subtracao
      cplx temp;
      temp.r=r-c.r;
      temp.i=i-c.i;
      return temp;
    }
    cplx operator *(cplx& c) const { // ----- Sobrecarga operador multiplicação
      cplx temp;                         //(ac-bd)+(bc+ad)i
      temp.r=(r*(c.r)-i*(c.i));
      temp.i=(r*(c.i)+i*(c.r));     
      return temp;
    }
    cplx operator /(cplx& c) const { // ----- Sobrecarga operador divisão
      cplx temp;                            //(ac+bd)/ca²+da² + (bc-ad)i/ca²+da²
      temp.r=(r*(c.r)+i*(c.i))/((c.r*pow(r,2))+(c.i*pow(r,2)));
      temp.i=(i*(c.r)-r*(c.i))/((c.r*pow(r,2))+(c.i*pow(r,2)));
      return temp;
    }
};

// --------------- Programa Principal
int main() {
  cplx i(2, 2), j, s;
  clrscr();
  j.igual(1, 3);
  j=i;
  cout << "I=";
  i.print();
  cout << "J=";
  j.print();
  cout << "S=";
  s.print();
  s=i+j;
  cout << "S+=";
  s.print();
  s=i-j;
  cout << "S-=";
  s.print();
  s=i*j;
  cout << "S*=";
  s.print();
  s=i/j;
  cout << "S/=";
  s.print();
  getch();
  return 0;
}

