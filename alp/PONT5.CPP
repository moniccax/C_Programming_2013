#include <constream.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void raiz_distinta (float pa, float pb, float pdelta){
  float x1, x2;
  x1=(-pb+sqrt(pdelta))/(2*pa);
  x2=(-pb-sqrt(pdelta))/(2*pa);
  cout << "\n\tRaizes distintas\n\tX1: " << x1 << "\n\tX2: " << x2;
}

void raiz_dupla (float pa, float pb, float pdelta){
  float x1, x2;
  x1=(-pb+sqrt(pdelta))/(2*pa);
  x2=x1;
  cout << "\n\tRaizes duplas\n\tX1: " << x1 << "\n\tX2: " << x2;
}

void raiz_complexa (float pa, float pb, float pdelta){
  float xr, xi;
  xr=(-pb)/(2*pa);
  xi=sqrt(-pdelta)/(2*pa);
  cout << "\n\tRaizes complexas\n\tX1: " << xr << " + " << xi << "i";
  cout << "\n\tX2: " << xr << " + " << xi << "i";
}

int main(){
  float a, b, c, delta;
  void (*p)(float pa, float pb, float pdelta);
//  void *q;
  clrscr();
  cout << "Valor de A: " << endl;
  cin >> a;
  cout << "Valor de B: " << endl;
  cin >> b;
  cout << "Valor de C: " << endl;
  cin >> c;
  delta=pow(b,2)-4*a*c;
  cout << "Delta: " << delta << endl;
  if (delta>0) p=raiz_distinta;
  if (delta==0) p=raiz_dupla;
  if (delta<0) p=raiz_complexa;
//  if (delta>0) raiz_distinta(a, b, delta);
//  if (delta==0)raiz_dupla(a, b, delta);
//  if (delta<0) raiz_complexa(a, b, delta);
  p(a, b, delta);
  cout << endl;
  getch();
  return 0;
}