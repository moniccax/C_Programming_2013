#include <constream.h>
#include <math.h>

void main(void){
  clrscr();
  float num=480.0, den=10.0, sinal=1.0, s;
  for (den=10.0; den<=40; den++){
  s+=(num/den)*sinal;
  num-=5;
  sinal=sinal*(-1.0);
  cout << "\t" << num;
  }
  cout << "\n\n\n" << s;
  getch();
}

