#include <constream.h>
#include <math.h>
#include <stdio.h>

void main(){
  clrscr();
  int sinal = 1;
  long float s=0.0, den, aux=1.0, pi=0.0;
  int cont=1;
  while (cont<=51){
    den=pow(aux,3);
    aux=aux+2;
    s+=(1/den)*sinal;
    sinal=sinal*(-1);
    cont++;
  }
  pi=(pow(s*32,1.0/3.0));
  cout << pi;
  getch();
}