#include <constream.h>

void main(void){
  clrscr();
  float den=1.0, sinal=1.0, pi=0.0;
  while (4.0/den>=0.0001){
    pi+=(4.0/den)*sinal;
    den+=2;
    sinal=sinal*(-1.0);
   }
   cout << pi;
  getch();
}