/*****************************************************************
 * Autor: Gilmar Machado Grossi                                  *
 * Compilador: BC 3.1 Borland                                    *
 * Ambiente: Tela de scroll do DOS                               *
 * Modelo de memoria: Small                                      *
 * Data: 17/02/2011                                              *
 * Objetivo: Ser um programa exemplo para as aulas de  algoritmo *
 *           e logica de programacao, mostrando o uso do comando *
 *	     printf da linguagem C.                              *
 *****************************************************************/

// ----- Inclui as bibliotecas necessarias
#include <stdio.h> // printf e scanf
#include <conio.h> // clrscr() e getch()
#include <process.h> // system(" ")

// ----- Programa Principal
int main() {
  /* Para limpar a tela temos as seguintes opcoes:
  1 - somente nos compiladores da Borland, Turbo C, BC e C++ Builder
      podemos utilizar a funcao clrscr();
  2 - Em qualquer compilador para ambiente DOS (mesmo prompt de DOS
      em Windows) podemos utilizar o comando system("cls");
  3 - Em qualquer compilador para ambiente console do Linux, podemos
      utilizar o comando system("clear");
  Note que o comando system("<comando do sistema operacional"); usa
  o proprio comando do sistema operacional que limpa a tela para
  fazer o servico. Voce pode usar o comando system para chamar qualquer
  outro comando do S.O.  */
  clrscr();
//  system("cls"); // nao funciona no windows 7
/* Escrevendo na tela com o comando printf */
  printf ("\n\n          Testando o comando printf\n\n");
  printf ("Caracteres: %c %c \n", 'a', 65); // 65 e' A na tabela ASCII
  printf ("Decimais: %d %ld\n", 1977, 650000L);
  printf ("Precedendo com brancos: %10d \n", 1977);
  printf ("Precedendo com zeros  : %010d \n", 1977);
  printf ("Escrevendo a constante 100 como inteiro decimal     : %d \n", 100);
  printf ("Escrevendo a constante 100 como inteiro octal       : %o \n", 100);
  printf ("Escrevendo a constante 100 como inteiro hexadecimal : %x \n", 100);
  printf ("Usando o scope depois do percento : %#x %#o \n", 100, 100);
  printf ("Reais: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
  printf ("Truque com tamanho: %*d \n", 5, 10);
  printf ("%s \n", "A string");
  printf ("\nTecle <enter> p/ sair\n");
  getch();
  return 0;
}
