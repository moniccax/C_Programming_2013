#include <constream.h>
#include <math.h>

void main(){
  clrscr();
  int h;
  double a, s=1.0, exp=2.0, den, sinal=1.0, diferenca, cosseno=0.0, cont=0.0, fat=0.0;
  cout<<"Digite o angulo: "<<endl;
  cin>>a;
  for(int i=1; i<=20; i++){
     cont+=2.0;
     cout<<"pao"<<endl;
     for (float j=cont; j>=1; j--){
	fat=fat*j;
	cout<<"Fat:"<<fat;
     }
     den=fat;
     fat=1.0;
     sinal=sinal*(-1.0);
     s+=((pow(a,exp))/den)*sinal;
     exp+=2.0;
  }
  cosseno=cos(a);
  diferenca=s-cosseno;
  cout<<"A serie e': "<<s<<endl;
  cout<<"Atraves da funcao: "<<cosseno<<endl;
  cout<<"A diferenca entre ambos: "<<diferenca<<endl;
  getch();
}