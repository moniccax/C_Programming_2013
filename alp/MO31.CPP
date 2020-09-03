#include <constream.h>

float result(){
  float den=1.0, s=0.0, sinal=1.0;
  while ((4.0/den)>0.0001){
    s+=(4.0/den)*sinal;
    sinal=sinal*(-1.0);
    den+=2.0;
  }
  return s;
}

float main(){
  float serie;
  clrscr();
  serie=result();
  cout<<"O valor de pi e'"<<setprecision(5)<<serie<<endl;
  getch();
  return 0;
}