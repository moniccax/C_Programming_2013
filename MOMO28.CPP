#include <constream.h>
#include <math.h>

void main(void){
  clrscr();
  float num=1000.0, den=1.0, sinal=1.0, s=0.0;
  for (int i=1; i<=50; i++){
    s+=(num/den)*sinal;
    num-=3;
    den++;
    sinal=sinal*(-1.0);
    cout << "\t" << num;
  }//--end of for
  cout << "\n\n\t" << s;
  getch();
}