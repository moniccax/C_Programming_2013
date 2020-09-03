#include <constream.h>
#include <math.h>

void main(){
  clrscr();
  double e=1.0000, x, cont=2, fat=2;

  cout<<"x:";
  cin>>x;
  e+=x;
  double real=exp(x);
  while((real-e)>0.0001){
    e+=pow(x,cont)/fat;
    fat=fat*cont;
    cont++;
    cout<<e<<endl;
  }
  cout<<"x="<<x<<endl;
  cout<<"EXP="<<real<<endl;
  cout<<"e="<<e<<endl;
  cout<<"num_elementos="<<cont-2<<endl;
  getch();
}