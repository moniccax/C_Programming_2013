#include <constream.h>

void main(void){
  clrscr();
  float pes, cabecas, patos, coelhos;
  cout<<"Quantas cabecas no cercado?"<<endl;
  cin>>cabecas;
  cout<<"Quantos pes no cercado?"<<endl;
  cin>>pes;
  coelhos=pes-(2*cabecas)/2;
  patos=cabecas-coelhos;
  cout<<"O numero de patos e: "<<patos<<endl;
  cout<<"O numero de coelhos e: "<<coelhos<<endl;
  getch();
}                        