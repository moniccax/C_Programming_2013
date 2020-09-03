#include <constream.h>
#include <math.h>

void main(){
  clrscr();
  double fat=1.0, cont=3.0, x, den=1.0, s, sinal=1.0, i;
  double exp=2.0;
  cout<<"Digite o valor de x: "<<endl;
  cin>>x;
  s=x;
  for (exp=2.0; exp<=40.0; exp+=2.0){
    sinal=sinal*(-1.0);
    cout<<"f"<<endl;
    for (i=cont; i>1.0; i--) {
      fat=fat*i;
      cout<<"f"<<fat<<endl;
      }
    den=fat;
    cout<<"d"<<den<<endl;
    s+=(pow(x,exp)/den)*sinal;
    fat=1.0;
    cont+=2.0;
  }//end
  cout<<"\n\nA serie vale:"<<s<<endl;
  getch();
}