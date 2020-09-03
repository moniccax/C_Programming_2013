#include <constream.h>
#include <math.h>

float result();

int main(){
  clrscr();
  float valors;

  valors=result();

  cout<< "A serie e "<<valors<<endl;
  getch();
  return 0;
}

float result(){
  float s=0.0, num, den, exp=1.0;
  for (den=50.0; den>=1.0; den--){
    num=pow(2.0,exp);
    exp++;
    s+=num/den;
  }
  return s;
}