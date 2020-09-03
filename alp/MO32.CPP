#include <constream.h>
#include <math.h>

float result(){
  float s=0.0, den=1.0, cont=1.0, sinal=1.0;
  while (cont<=50.0){
    s+=(1/pow(den,3.0))*sinal;
    sinal=sinal*(-1.0);
    den+=2;
    cont++;
  }
  return s;
}

int main(){
  clrscr();
  float valor=0.0, pi=0.0;
  valor=result();
  pi=(pow((valor*32),(1.0/3.0)));
  cout<<"O valor de pi e': "<<pi<<endl;
  getch();
  return 0;
}