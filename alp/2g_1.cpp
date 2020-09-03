/*********************************************************************
* Aula de Laboratório de ALP do dia 01/07/2013                       *
*                                                                    *
*  Escreva um programa C++ que lê os coeficientes A, B, e C de uma   *
*  equação do 2o grau. Calcule o determinante Delta, e através do    *
*  valor de Delta efetue a chamada a uma das três seguintes funções: *
*  - RaizDupla, no caso de Delta ser zero;                           *
*  - RaizesReais, no caso de Delta ser maior que zero;               *
*  - RaizesComplexas, no caso de Delta ser menor que zero.           *
*  Cada uma das três funções anteriores, apenas calcula as raízes    *
*  de acordo com cada caso. Logo todas três funções possuem 3        *
*  parametros de entrada; A, B e Delta , e 2 parametros de saída;    *
*  X1 e X2, sendo que X1 e X2 podem ser números complexos.           *
*  Os parametros de entrada são passados por valor, e os de saída    *
*  são passados por referência.                                      *
*                                                                    *
*  Massa de dados de teste:                                          *
*  Raizes Reais     a=1 , b=4  e c=-5 => x1=-5 e x2=-1               *
*  Raiz Dupla       a=1 , b=-2 e c=1  => x1=1  e x2=1                *
*  Raizes Complexas a=2 , b=2  e c=2  => x1=-0.5 + 0.86i             *
*                                        x2=-0.5 - 0.86i             *
*********************************************************************/

#define clrscr() system("clear")
#define getch() system("read a")

#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

void RaizesReais(float a, float b, float delta, float& x1, float& x2) {
  x1=((-b) + sqrt(delta))/(2.0*a);
  x1=((-b) - pow(delta, 0.5))/(2.0*a);
//  x1=((-b) - sqrt(delta))/(2.0*a);  // ----- esperimente esta linha e a anterior e veja a diferenca de casas decimais
}

void RaizDupla(float a, float b, float delta, float& x1, float& x2) {
  x1=(-b)/(2.0*a);
  x2=x1;
}

void RaizesComplexas(float a, float b, float delta, float& x1, float& x2){
  x1=(-b)/(2.0*a);
  x2=sqrt((-delta))/(2.0*a);
}

int main() {
  float a, b, c, delta, x1, x2;
  clrscr();
  cout << "\n\n\t\t\tCalculo das raizes de uma equação do 2o grau\n";
  cout << "\n\tEntre o valor de A : ";
  cin >> a;
  cout << "\tEntre o valor de B : ";
  cin >> b;
  cout << "\tEntre o valor de C : ";
  cin >> c;
  delta=pow(b,2)-4.0*a*c;
  if (delta>0) {
    RaizesReais(a, b, delta, x1, x2);
    cout << "\n\tAs raízes são reais";
    cout << "\n\tX1= " << x1;
    cout << "\n\tX2= " << x2 << endl;
  }
  else
    if (delta==0) {
      RaizDupla(a, b, delta, x1, x2);
      cout << "\n\tRaiz dupla";
      cout << "\n\tX1= " << x1;
      cout << "\n\tX2= " << x2 << endl;
    }
    else {
      RaizesComplexas(a, b, delta, x1, x2);
      cout << "\n\tAs raízes são complexas";
      cout << "\n\tX1= " << x1 << " + " << x2 << "i";
      cout << "\n\tX2= " << x1 << " - " << x2 << "i" << endl;
    }
  getch();
}
    
