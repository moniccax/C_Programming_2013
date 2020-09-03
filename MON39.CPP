#include <constream.h>
#include <math.h>

void main(){
  clrscr();
  int exp=2.0, cont, sinal=1;
  float x,num, aux=3.0;
  double fat, s;
  cout << "Digite o valor de x: ";
  cin >> x;
  s=x;
  for (cont=1; cont<=5; cont++){
    num+=pow(x,exp);
    exp+=2;
    while (aux>1){
      aux--;
      fat+=fat*aux;
    }//end while
    aux+=2;
    sinal=sinal*(-1.0);
    s+=(num/fat)*sinal;
    cout<< "\t" << fat;
  }//end for
  cout<<s<<endl;
  getch();
}//end main