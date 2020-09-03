#include <conio.h>
#include <iostream.h>
#include <stdlib.h>
#include <math.h>

int fat (int n){
    int r;
    if ((n==1) || (n==0)){
       return 1;
    }               
    else{
      r=(fat(n-1)*n);
      return r;
   }
}
double seq(double n){
    int i,cont=0, sinal=1;
    double den=0.0, num=0.0, s=1.0;
    for (i=0; i<10; i++){
        cont+=2;
        den=fat(cont);
        num=pow(n,cont);
        sinal=sinal*(-1);
        s+=sinal*(num/den);
    }
    return s;
}

int main(){
  system("cls");
  int cont=0, sinal=1;
  double a, s, diferenca, radianos, cosseno;
  cout<<"Digite o angulo: ";
  cin>>a;
  cout<<"\n Angulo ="<<a;
  radianos=a*3.14/180;
  s=seq(radianos);
  cosseno=cos(radianos);
  diferenca=s-cosseno;
  cout<<"\n A serie e': "<<s<< endl;
  cout<<" Atraves da funcao: "<<cosseno<< endl;
  cout<<" A diferenca entre ambos: "<<diferenca<< endl;
  getch();
}
