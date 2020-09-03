/*****************************************************************
 * Autor: Gilmar Machado Grossi                                  *
 * Compilador: BC 3.1 Borland                                    *
 * Ambiente: Tela de scroll do DOS                               *
 * Modelo de memoria: Small                                      *
 * Data: 17/02/2011                                              *
 * Objetivo: Ser um programa exemplo para as aulas de  algoritmo *
 *           e logica de programacao, mostrando o uso do comando *
 *	     scanf da linguagem C.                               *
 *****************************************************************/

// ----- Inclui as bibliotecas necessarias
#include <stdio.h> // printf e scanf
#include <stdlib.h> // system(" ")
//#include <stdio_ext.h> // system(" ")
#include <iostream> // cout, cin. Use com .h no BC 3.1 e sem .h nos demais compiladores
//#include <conio.h> // clrscr() e getch(). Use somente no BC 3.1
//#include <process.h> // system(" "). Use somente no BC 3.1

using namespace std;

// ----- Programa Principal
int main () {
  char ch, str [80], lixo[255];
  int i;
  float a;
//  clrscr();
  system("cls");
  printf ("Entre um unico caracter: ");
  scanf ("%c%*c",&ch);
//  rewind(stdin);
//  __purge(stdin);
//  cin.ignore();
//  fclean(stdin);
  gets(lixo);
  printf ("Voce digitou %c\n", ch);
  printf ("Entre uma palavra: ");
  scanf ("%s",str);
  gets(lixo);
  printf ("Voce digitou %s\n", str);
  printf ("Entre um inteiro: ");
  scanf ("%d",&i);
  gets(lixo);
  printf ("Voce digitou %d\n", i);
  printf ("Entre um numero hexadecimal: ");
  scanf ("%x",&i);
  gets(lixo);
  printf ("Voce digitou %#x que vale (%d) em decimal.\n",i,i);
  printf ("Entre um numero real: ");
  scanf ("%f",&a);
  gets(lixo);
  printf ("Voce digitou %f\n",a);
  printf ("\nTecle <enter> p/ sair\n");
  //getch();
  system("pause");
  return 0;
}
