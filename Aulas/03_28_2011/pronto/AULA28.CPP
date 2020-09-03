/***********************************************************
*Autor: Daniel Silva da Fonseca                            *
*Compilador:BC 3.1                                         *
*Ambiente: Windows XP                                      *
*Data: 10/03/2011                                          *
*Objetivo:Exercicio 1.12.6 da lista.                       *
***********************************************************/
#include <constream.h>
void main(){
  clrscr();
  float mi, mf;
  int th, tm, ts;
  mf=0;
  cout<<"Digite a massa incial : ";
  cin>> mi;
  ts=0;
  while(mi>=0.5){
    mi=mi/2;
    ts=ts+50;
    if(mi<=0.5)
    mf=mi;
  }
  tm=ts/60;
  ts=ts%60;
  th=tm/60;
  tm=tm%60;
  cout << "\n O tempo encontrado e de " << th << ":" << tm << ":" << ts;
  cout << "\n Massa final e de "<<mf;
  getch();
}
