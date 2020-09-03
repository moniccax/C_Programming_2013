#include <conio.h>
#include <iostream.h>
#include <stdlib.h>
#include <math.h>

int fat (int n){
if ((n==1) || (n==0)) return 1;
   else
      return (fat(n-1)*n);
}

int main(){
  system("cls");
  int cont=0, sinal=1;
  double a, s=1.0, den, diferenca, cosseno=0.0;
  cout<<"Digite o angulo: ";
  cin>>a;
  cout<<"\n"<<a;
  for (int i=0; i<20; i++){
     cont+=2;
     den=fat(cont);
     sinal=sinal*(-1);
     s+=(pow(a,cont))/den*sinal;
  }
  cosseno=cos(a);
  diferenca=s-cosseno;
  cout<<"\n A serie e': "<<s<< endl;
  cout<<"Atraves da funcao: "<<cosseno<< endl;
  cout<<"A diferenca entre ambos: "<<diferenca<< endl;
  getch();
  return 0;
}
