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

#include <iostream.h> // cout, cin, endl
#include <stdio.h> // printf e scanf
#include <stdlib.h> //
#include <math.h> //
#include <string.h> // funcoes para manipulacao de vetor de char
#include <fstream.h> // funcoes de arquivo em C++


// --------------- Declaracao de variaveis globais
#define esc 27
#define clrscr() system("clear")
#define getch() system("read a")

class cplx {
  private:
    float r, i;

  public:
    cplx(float r0=0, float i0=0) : r(r0), i(i0){} // ----- Construtor
    void igual(float x, float y) {
      r=x;
      i=y;
    }
    void print()  { // ----- Escreve parte real e parte imaginaria na tela
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
      cplx temp;
      // z*w=(ac-bd) +(bc+ad)i
      temp.r=r*c.r-i*c.i;
      temp.i=i*c.r+r*c.i;
      return temp;
    }
    cplx operator /(cplx& c) const { // ----- Sobrecarga operador divisão
      cplx temp;
      // z/w=(ac+bd)/sqrt(sqr(c)+sqr(d)) + (bc-ad)i/sqrt(sqr(c)+sqr(d))
      temp.r=(r*c.r+i*c.i)/(pow(c.r,2)+pow(c.i,2));
      temp.i=(i*c.r-r*c.i)/(pow(c.r,2)+pow(c.i,2));
      return temp;
    }
    int operator ==(cplx& c) { // ----- igualdade
      if ((r==c.r) && (i==c.i))
	return 1; // ----- e' igual
      else
	return 0; // ----- nao e' igual
    }
    friend ostream& operator << (ostream& stream, cplx& c) {
      stream << c.r << "+i" << c.i;
      return stream;
    }
    friend istream& operator >> (istream& stream, cplx& c) {
      float r1, i1;
      stream >> r1 >> i1;
      if (stream.good()) {
	c.r=r1;
	c.i=i1;
      }
      return stream;
    }
};

// --------------- Programa Principal
int main() {
  clrscr();
  cplx i(2.0, 5.0), j, s;
  clrscr();
  j.igual(3.0, 5.0);
  j=(1 , 3) ;
  cout << "I=";
  i.print();
  cout << "J=";
  j.print();
  cout << "S=";
  s.print();
  s=i.operator+(j); //i+j
  cout << "i+j=";
  s.print();
  s=i.operator-(j); //i-j
  cout << "i-j=";
  s.print();
  s=i.operator*(j); //i*j
  cout << "i*j=";
  s.print();
  s=i.operator/(j); //i/j
  cout << "i/j=";
  s.print();
  cout << "J=" << j << endl;
  cin >> j;
  j.print();
  if (i==j)
    cout << "I e' igual a: ";
  getch();
  return 0;
}

