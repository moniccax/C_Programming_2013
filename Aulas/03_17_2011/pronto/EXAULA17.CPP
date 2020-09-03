/***********************************************************
*Autor: Daniel Silva da Fonseca                            *
*Compilador:BC 3.1                                         *
*Ambiente: Windows XP                                      *
*Data: 10/03/2011                                          *
*Objetivo:Calcular a variavel "S" do exercicio da aula do  *
*dia 17/03/2011                                            *
***********************************************************/
#include <constream.h>
#include <math.h>
void main (){
  clrscr();
  int sinal, num1, num2, den;
  float s, total, aux1; 
  cout<< "\n\n          Exercicio da aula do dia 17/03/2011 \n\n";
  num1=3;
  num2=15;
  s=0;
  sinal=-1;
  for(den=1, num1=3, num2=15; den<=15; den++,num1++,num2--){
    sinal=sinal*-1;
    aux1=num1*num2;
    total=aux1/den;
    total=sinal*total;
    s+=total;
  }
  cout<< "\n O valor encontrado para a variavel s e de "<<s;
  cout<< "\n Pressione enter para sair";
  getch();
  }
