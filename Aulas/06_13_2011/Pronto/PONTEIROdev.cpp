/*********************************************************
*Autor: Daniel Silva da Fonseca                          *
*Compilador:BC 3.1                                       *
*Ambiente:                                               *
*Modelo de memoria: Small                                *
*Data: 10/03/2011                                        *
*Objetivo:Aprender a                                     *
*-ler uma quantidade indeterminada de dados              *
*-diferen‡a entre a tela de scroll do DOS e a tela cheia *
**********************************************************/
#include <iostream.h>
#include <conio.h>
int main(){
system("cls");
int x;
int *p;
p=&x;
cout<<" p="<<p;
p++;
cout<<"\n p apos incremento ="<<p<<"\n";
system("pause");
return 0;
}
