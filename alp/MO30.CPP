#include <constream.h>
#include <math.h>

int main(){
  clrscr();
  float a=0.0, seno=0.0, rad=0.0;
  cout<<"Digite o valor do angulo: "<<endl;
  cin>>a;
  float i=a;
  for (i; i<=a+6.3; i+=0.1){
    rad=(i*3.14)/180.0;
    seno=rad-((pow(rad,3.0))/6.0)+((pow(rad,5.0))/120.0)-((pow(rad,7.0))/5040.0);
    cout << "\tSeno: "<<seno;
    cout << "\tAng: "<<i;
  }
  getch();
  return 0;
}