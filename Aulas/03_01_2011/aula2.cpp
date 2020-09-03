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
#include <stdio_ext.h> // system(" ")
#include <iostream> // cout, cin
//#include <conio.h> // clrscr() e getch()
//#include <process.h> // system(" ")

using namespace std;

// ----- Programa Principal
int main () {
  char ch, str [80], lixo[255];
  int i;
  float a;
//  clrscr();
  system("clear");
  printf ("Entre um unico caracter: ");
  scanf ("%c%*c",&ch);
//  rewind(stdin);
//  __purge(stdin);
//  cin.ignore();
  fclean(stdin);
  printf ("Voce digitou %c\n", ch);
  printf ("Entre uma palavra: ");
  scanf ("%s",str);
  printf ("Voce digitou %s\n", str);
  printf ("Entre um inteiro: ");
  scanf ("%d",&i);
  printf ("Voce digitou %d\n", i);
  printf ("Entre um numero hexadecimal: ");
  scanf ("%x",&i);
  printf ("Voce digitou %#x que vale (%d) em decimal.\n",i,i);
  printf ("Entre um numero real: ");
  scanf ("%f",&a);
  printf ("Voce digitou %f\n",a);
  printf ("\nTecle <enter> p/ sair\n");
//  getch();
  system("read a");
  return 0;
}
