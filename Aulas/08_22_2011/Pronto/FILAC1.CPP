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
//#include <string.h> // funcoes para manipulacao de vetor de char
#include "C:\bc31\bin\Moldura.h"
#include "C:\bc31\bin\FILA_CD.h"

// --------------- Funcao mostra menu na tela
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
  int i, head, tail;
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
  getch();
  delete fila;
  return 0;
}

