#include <constream.h>

float result();

int main(){
  clrscr();
  float s=0.0;

  s=result();

  cout<<"O valor da serie e:"<<s<<endl;
  getch();
  return 0;
}                      

float result(){
  float num=480.0, den=10.0, sinal=1.0, valors=0.0;
  for (den=10.0; den<=40.0; den++){
     valors+=(num/den)*sinal;
     num-=5.0;
     sinal=sinal*(-1.0);
  }
  return valors;
}