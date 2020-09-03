#include <constream.h>
#include <math.h>

int main(){
  clrscr();
  float a=0.0, seno=0.0, x=0.0, y=0.0;
  int flag=1;
  while (flag==1){
    cout<<"Digite o valor do angulo: "<<endl;
    cin>>x;
    a=(x*3.1415)/180.0;
    y=a-((pow(a,3.0))/6.0)+((pow(a,5.0))/120.0)-((pow(a,7.0))/5040.0);
    seno=sin(y);
    cout<<"O valor do seno e': "<<seno<<endl;
    cout<<"Digite 1 para continuar  "<<endl;
    cin>>flag;
  }
  getch();
  return 0;
}