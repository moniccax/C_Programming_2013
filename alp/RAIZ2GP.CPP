/*****************************************************************
 * Autor: Gilmar Machado Grossi                                  *
 * Compilador: gcc no Linux Ubuntu 10.04                         *
 * Ambiente: Tela de scroll da Konsole                           *
 * Modelo de memoria: Small                                      *
 * Data: 08 de junho de 2011                                     *
 * Objetivo: Ser um programa exemplo para a aula teorica de      *
 *           algoritmo e logica de programacao, mostrando o      *
 *	         uso de ponteiros. O programa le os coeficientes     *
 *           A , B  e C de uma equacao do 2o grau. Calcula o     *
 *           delta,  e dependendo dele, aponta um ponteiro       *
 *           para a funcao correta que da a saida X1 e X2.       *      
 *****************************************************************/

// ----- Inclui as bibliotecas necessarias

#include <constream.h> // cout, cin, endl
#include <stdio.h> // printf e scanf
#include <stdlib.h> //
#include <math.h> // pow e sqrt

//using namespace std;

// --------------- Declaracao de variaveis globais
//#define esc 27
//#define clrscr() system("cls")
//#define getch() system("pause")

// --------------- Funcoes para calculo e impresao das raizes
void raiz_distinta(float pa, float pb, float pdelta) {
  float x1, x2;
  x1=(-pb+sqrt(pdelta))/(2*pa);
  x2=(-pb-sqrt(pdelta))/(2*pa);
  cout << "\n\tRaizes Distintas\n";
  cout << "\n\tX1 = " << x1 << endl;
  cout << "\n\tX2 = " << x2 << endl;
}

void raiz_dupla(float pa, float pb, float pdelta) {
  float x1, x2;
  x1=(-pb+sqrt(pdelta))/(2*pa);
  x2=x1;
  cout << "\n\tRaiz Dupla\n";
  cout << "\n\tX1 = " << x1 << endl;
  cout << "\n\tX2 = " << x2 << endl;
}

void raiz_complexa(float pa, float pb, float pdelta) {
  float xr, xi;
  xr=(-pb)/(2*pa);
  xi=sqrt(-pdelta)/(2*pa);
  cout << "\n\tRaizes Complexas\n";
  cout << "\n\tX1 = " << xr << " + " << xi << "i" << endl;
  cout << "\n\tX2 = " << xr << " - " << xi << "i" << endl;
}

// --------------- Programa Principal
int main() {
  float a, b, c, delta;
  void (*p)(float pa, float pb, float pdelta);
  void *q;
  clrscr();
  cout << "\n\n\t\t\t\tCalculo das Raizes de uma Equacao do 2o Grau\n";
  cout << "\n\tEntre o valor de A : ";
  cin >> a;
  cout << "\n\tEntre o valor de B : ";
  cin >> b;
  cout << "\n\tEntre o valor de C : ";
  cin >> c;
  delta=pow(b,2)-4*a*c;
  cout << "\n\tDelta = " << delta << endl;
  if (delta>0) p=raiz_distinta;
  if (delta==0) p=raiz_dupla;
  if (delta<0) p=raiz_complexa;
//  if (delta>0) raiz_distinta(a, b, delta);
//  if (delta==0) raiz_dupla(a, b, delta);
//  if (delta<0) raiz_complexa(a, b, delta);
  q=p;
  q(a, b, delta);
  cout << endl;
  getch();
  return 0;
}

