#include <constream.h>
#include <math.h>


void main(){
  clrscr();
  float num=1.0, s, sinal=1.0;
  for (float i=15.0; i>=1.0; i--){
    s+=(num/(pow(i,2)))*sinal;
    sinal=sinal*(-1.0);
    num=num*2.0;
    cout<<"\t"<<num;
  }
  cout<<"\n\t"<<s;
  getch();
}