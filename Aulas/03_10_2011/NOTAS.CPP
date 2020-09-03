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
#include <constream.h>
#include <math.h>
{
void main();
  int:num,nota,maior,menor;
  float:med;
  clrscr();
  nota=0;
  num=0;
  while(nota!=-1);{
    cout<<"/n Escreva as notas que deseja tirar a media";
    cin>>nota;
    num+1=num;
    if(nota>maior);{
      nota=maior}
    if(nota<menor);{
      nota=menor}
    }
  cout<</n O numero de notas lidas foi de "<<num>>";
  med=nota/num;
    cout<<("/n A media das notas digitadas e de "<<med>>");
  getch();
  }
