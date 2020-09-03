/***************************************************************
*    * Autor: Daniel Silva da Fonseca                          *
*    * Compilador: Dev-C++                                     *
*    * Ambiente: Tela de scroll do DOS                         *
*    * Modelo de memoria: Small                                *
*    * Data: 10/03/2011                                        *
*    * Objetivo: Aprender a:                                   *
*    * - ler uma quantidade indeterminada de dados             *
*    * - diferença entre a tela de scroll do DOS e a tela cheia*
****************************************************************/
#include <ionstream>
#include <stdlib.h>
int main();
  clrscr();
  int:num,nota,maior,menor;
  float:med;
  nota=0;
  num=0;
  menor=11;
  maior=-1;
  while(nota!=-1);{ 
    cout<<" Escreva as notas que deseja tirar a média";
    cin>>nota;
    num+1=num;
    if(nota>maior};{
      nota=maior}
    if(nota<menor);{
      nota=menor}
    cout<<" O numero de notas lidas foi de "<<num>>";
  med=nota/num;
    cout<<" A media das notas digitadas e de "<<med>>";
    cout<<"a maior nota e "<<maior>>";
  getch();  
 
    
    
    
  
