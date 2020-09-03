/*****************************************************************
 * Autor: Gilmar Machado Grossi                                  *
 * Compilador: BC 3.1 Borland                                    *
 * Ambiente: Tela de scroll do DOS                               *
 * Modelo de memoria: Small                                      *
 * Data: 08/08 e 10/08 de 2011                                   *
 * Objetivo: Exemplo de fila simples sobre vetor estatico        *
 *****************************************************************/

// ----- Inclui as bibliotecas necessarias
#include <iostream.h> // cout, cin, endl
#include <stdio.h> // printf e scanf
#include <conio.h> // clrscr() e getch()
#include <dos.h> // sound(), nosound() e delay()
#include <process.h> // exit()
#include "C:\bc31\bin\MOLDURA.H"
#include "C:\bc31\bin\FILA_SD.H"
//#include <string.h> // funcoes para manipulacao de vetor de char

// --------------- Declaracao de variaveis globais
#define esc 27
  // ----- largura e altura da tela. Varia com o S.O., a resolucao
  //       e o tipo de monitor. O padrao DOS puro e' 25 linhas x 80 colunas
  //       Com XP, a 1024x768, e monitor CRT 3x4 de 15" deu 48 lin. x 80 col.
  //       Com XP, a 1280x1024, LCD 3x4 de 15" deu 48 lin. x 80 col.
  //       Com 7, a 1024x600, LCD 16x9 de 10" deu 24 lin. x 80 col.


/* --------------- Convencoes para funcionamento da fila
fila vazia - head=-1 e tail=0
fila esgotada para enfileirar - tail=max
fila sem elementos para desenfileirar - head=max
- Para enfileirar primeiro teste se tail<max, se for coloque o elemento na
  posicao tail e depois incremente tail de 1.
- Para desenfileirar primeiro incremente head de 1, e teste se head<tail, se
  for retire o elemento da posicao head.
*/


 int menu(void) {
  int resp=0;
  while ((resp<1) || (resp>5)) {
    moldura();
    gotoxy(28,3);  cout << "Fila simples sobre vetor estatico";
    gotoxy(28,7);  cout << "1 - Enfileirar elemento";
    gotoxy(28,8);  cout << "2 - Desenfileirar elemento";
    gotoxy(28,9);  cout << "3 - Mostrar toda a fila";
    gotoxy(28,10); cout << "4 - Limpar fila";
    gotoxy(28,11); cout << "5 - Sair";
    gotoxy(28,13); cout << "Opcao: ";
    cin >> resp;
    if ((resp<1) || (resp>5)) {
      gotoxy(3, (alt-1)); cout << "Opcao Invalida";
      apito();
    } // ----- if ((resp<1) || (resp>5))
  } // ----- while ((resp<1) || (resp>5))
  return resp;
} // ----- menu()


// --------------- Programa Principal
int main() {
  int i;
  int fila[5];

  int op=0;
  while (op!=5) {
    op=menu();
    switch (op) {
      case 1: enfileira(); break;
      case 2: desenfileira(); break;
      case 3: mostrafila(); break;
      case 4: limpafila(); break;
      case 5: clrscr();
	      exit(0);
      default : printf("Bug!\n");
		exit(1); // Encerra programa com codigo erro.
    }
  }
  delete fila;
  getch();
  return 0;
}

