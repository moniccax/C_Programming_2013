/*****************************************************************
 * Autor: Gilmar Machado Grossi                                  *
 * Compilador: BC 3.1 Borland                                    *
 * Ambiente: Tela de scroll do DOS                               *
 * Modelo de memoria: Small                                      *
 * Data: 06/04/2011                                              *
 * Objetivo: Este programa e' a solucao do exercicio 1.12.39 do  *
 *           livro Algoritmos Estruturados - Farrer e Outros,    *
 *           com uma pequena modificacao no enunciado.           *
 *                                                               *
 * Escreva um programa em C/C++ que calcula o somatorio da serie *
 * abaixo, com uma precisao de 0,01. O valor de X e' fornecido   *
 * pelo usuario.                                                 *
 *          2    4    6                                          *
 * S = X - X  + X  - X  + . . .                                  *
 *         -    -    -                                           *
 *         3!   5!   7!                                          *
 *                                                               *
 *****************************************************************/

// --------------- Inclui as bibliotecas necessarias
#include <constream.h>
#include <iomanip.h>
#include <math.h>

// --------------- Programa principal
int main () {
  // ----- Declaracao de variaveis
  float s, termo, x, expo, den, sinal, fat, i;
  // ----- Emite tela de saudacao para usuario e pede p/ aguardar
  clrscr();
  cout << "\n\n\tCalculo da Serie do ex. 1.12.39 modificado\n";
  cout << "\n\tEntre o valor de X : ";
  cin >> x;
  cout << "\n\tCalculando a serie.\n";
  cout << "\tAguarde . . .\n\n";
  // ----- Inicializacao das variaveis com os dados fornecidos
  termo=x;
  s=0;
  sinal=-1;
  den=3;
  // ----- Calculo da resposta
  while (fabs(termo)>0.01) {
    s=s+termo;
    // ----- Calculo do fatorial sem funcao e sem recursividade
    fat=1;
    for (i=den; i>1; i--)
      fat=fat*i;
    /* ----- Solucao nao recomendada com for porque e' menos legivel
    for (i=den, fat=1; i>1; fat=fat*i, i--);
    */
    termo=sinal*pow(x, (den-1))/fat;
    den+=2;
    sinal=sinal*(-1);
  }
  // ----- Saida dos Resultados
  cout << setw(10);
  cout << setiosflags(ios::fixed)
       << setiosflags(ios::showpoint)
       << setprecision(2);
  cout << "\tS = " << s << endl;
  // ----- Despede e aguarda <enter> para encerrar o programa
  cout << "\n\tTecle <enter> para sair " << endl;
  getch();
  // ----- Sai com codigo de termino normal do programa
  return 0;
}