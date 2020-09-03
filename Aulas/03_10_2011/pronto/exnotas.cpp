/*********************************************************
*Autor: Daniel Silva da Fonseca                          *
*Compilador:BC 3.1                                       *
*Ambiente:                                               *
*Modelo de memoria: Small                                *
*Data: 10/03/2011                                        *
*Objetivo:Aprender a                                     *
*-ler uma quantidade indeterminada de dados              *
*-diferenca entre a tela de scroll do DOS e a tela cheia *
**********************************************************/
#include <constream.h>
#include <math.h>
#include <process.h>
void main(){
  int num,nota,maior,menor,aux;
  float med;
  clrscr();
  nota=0;
  aux=0;
  num=0;
  while(nota!=-1){
    cout<<"Escreva as notas que deseja tirar a media:";
    cin>>nota;
    if(nota!=-1){
      num=num+1;
      aux=aux+nota;
    }
    if(nota>maior)
      maior=nota;
    if(nota<menor && nota!=-1)
      menor=nota;
    }
  cout<<"\n O numero de notas lidas foi de "<<num;
  med=aux/num;
  cout<<"\n A media das notas digitadas e de "<<med;
  cout<<"\n A maior nota foi de "<<maior;
  cout<<"\n A menor nota foi de "<<menor;
  cout<<"\n pressione <enter> para sair\n";
  getch();
  }

