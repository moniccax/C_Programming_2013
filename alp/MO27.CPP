#include <constream.h>
#include <math.h>

float valors();

int main(){
  clrscr();
  float result;

  result=valors();

  cout<<"O valor da serie e' :"<< result;
  getch();
  return 0;
}

float valors(){
  float num, s=0.0, den, sinal=1.0;
  for (num=1.0; num<=10.0; num++){
  den=pow(num,2);
  s+=(num/den)*sinal;
  sinal=sinal*(-1.0);
  }
  return s;
}