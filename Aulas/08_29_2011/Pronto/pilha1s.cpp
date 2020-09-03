/*****************************************************************
 * Autor: Gilmar Machado Grossi                                  *
 * Compilador: BC 3.1 Borland                                    *
 * Ambiente: Tela de scroll do DOS                               *
 * Modelo de memoria: Small                                      *
 * Data: 24/08 e 29/08 de 2011                                   *
 * Objetivo: Exemplo de pilha simples sobre vetor estatico       *
 *****************************************************************/

#include "c:\bc31\bin\pilha2s.h"

// --------------- Funcao mostra menu na tela
int menu(void) {
  int resp=0;
  while ((resp<1) || (resp>5)) {
    moldura();
    gotoxy(28,3);  cout << "Pilha simples sobre vetor estatico";
    gotoxy(28,7);  cout << "1 - Empilhar elemento";
    gotoxy(28,8);  cout << "2 - Desempilhar elemento";
    gotoxy(28,9);  cout << "3 - Mostrar toda a pilha";
    gotoxy(28,10); cout << "4 - Limpar a pilha";
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
  limpapilha();
  int op=0;
  while (op!=5) {
    op=menu();
    switch (op) {
      case 1: empilha(); break;
      case 2: desempilha(); break;
      case 3: mostrapilha(); break;
      case 4: limpapilha(); break;
      case 5: clrscr();
	      exit(0);
      default : printf("Bug!\n");
		exit(1); // Encerra programa com codigo erro.
    }
  }
  getch();
  return 0;
}

