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
#include <conio.h> // clrscr() e getch()
#include <process.h> // system(" ")
// ----- Programa Principal
int main () {
  char ch, str [80], frase[256];
  int i;
  float a;
  clrscr();
  printf ("Entre um unico caracter: ");
  scanf ("%c",&ch);
  rewind (stdin);
  printf("Voce digitou %c\n", ch);
  printf("Entre uma palavra: ");
  scanf ("%s",str);
  rewind (stdin);
  printf ("Voce digitou %s\n", str);
  printf ("Entre com uma frase ");
  gets(str);
  rewind(stdin);
  printf ("Voce digitou %sn\n",str);
  printf ("Entre um inteiro: ");
  scanf ("%d",&i);
  rewind (stdin);
  printf ("Voce digitou %d\n", i);
  printf ("Entre um numero hexadecimal: ");
  scanf ("%x",&i);
  rewind (stdin);
  printf ("Voce digitou %#x que vale (%d) em decimal.\n",i,i);
  printf ("Entre um numero real: ");
  scanf ("%f",&a);
  rewind (stdin);
  printf ("Voce digitou %f\n",a);
  printf ("\nTecle <enter> p/ sair\n");
  getch();
  return 0;
}

