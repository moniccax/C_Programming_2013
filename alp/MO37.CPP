#include <constream.h>

float result(){
  clrscr();
  float cont=1.0, s, den=1.0, sinal, fat;
  while (cont<=50.0){
    fat=fat*cont;
    cont++;
    s+=(fat/den)*sinal;
    sinal=sinal*(-1.0);
    den+=2.0;
  }
  return s;
}

int main(){
  float s;
  s=result();
  cout<<"serie e':"<<s;
  getch();
  return 0;
}