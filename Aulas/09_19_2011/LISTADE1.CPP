/*****************************************************************
 * Autor: Gilmar Machado Grossi                                  *
 * Compilador: BC 3.1 Borland                                    *
 * Ambiente: Tela de scroll do DOS                               *
 * Modelo de memoria: Small                                      *
 * Data: 19/09 e 21/09 de 2011                                   *
 * Objetivo: Exemplo de lista duplamente encadeada com alocacao  *
 *           dinamica de nodos e ponteiros dinamicos com conteudo*
 *           de endereco.                                        *
 *****************************************************************/

// ----- Inclui as bibliotecas necessarias

#include <iostream.h> // cout, cin, endl
#include <stdio.h> // printf e scanf
#include <conio.h> // clrscr() e getch()
#include <dos.h> // sound(), nosound() e delay()
#include <process.h> // exit()
#include "moldura.h"

// --------------- Declaracao de variaveis globais

/* --------------- Convencoes para funcionamento desta lista encadeada

Lista vazia - prim=null; e ult=null;
Lista esgotada para insercao de novos elementos - quando o heap acabar
Nodos para 1 elemento inteiro, alocados dinamicamente
*/

struct nodo {
  int n;      // ----- area de dado do nodo, somente um inteiro
  // ----- area de ponteiro do nodo
  struct nodo* ant;  // ----- aponta o nodo anterior
  struct nodo* prox; // ----- aponta o proximo nodo
}; // ----- struct nodo

nodo *prim = new nodo; // ----- ponteiro para inicio da lista
nodo *ult  = new nodo; // ----- ponteiro para final da lista

// --------------- Funcao mostra menu na tela
int menu(void) {
  int resp=0;
  while ((resp<1) || (resp>5)) {
    moldura();
    gotoxy(14,3);  cout << "Lista duplamente Encadeada com alocacao dinamica";
    gotoxy(28,7);  cout << "1 - Incluir elemento no inicio";
    gotoxy(28,8);  cout << "2 - Incluir elemento no final";
    gotoxy(28,9);  cout << "3 - Incluir elemento em ordem";
    gotoxy(28,10); cout << "4 - Excluir elemento no inicio";
    gotoxy(28,11); cout << "5 - Excluir elemento no final";
    gotoxy(28,12); cout << "6 - Excluir elemento apontado";
    gotoxy(28,13); cout << "7 - Acha elemento por valor chave primaria";
    gotoxy(28,14); cout << "8 - Mostrar toda a Lista";
    gotoxy(28,15); cout << "9 - Limpar a Lista";
    gotoxy(28,16); cout << "0 - Sair";
    gotoxy(28,17); cout << "Opcao: ";
    cin >> resp;
    if ((resp<0) || (resp>9)) {
      gotoxy(3, (alt-1)); cout << "Opcao Invalida";
      apito();
    } // ----- if ((resp<1) || (resp>5))
  } // ----- while ((resp<1) || (resp>5))
  return resp;
} // ----- menu()

// --------------- Funcao Insere nodo no inicio
int insere_inicio(nodo *p) {
  int ok=0;
  if (prim!=NULL) {
    // ----- tem nodo na lista. pesquisa a posicao em ordem crescente
    p->ant=NULL;
    p->prox=prim;
    prim->ant=p;
    prim=p;
  }
  else {
    // ----- lista vazia. insere primeiro nodo no inicio.
    p->ant=NULL;
    p->prox=prim;
    prim=p;
  }
  ok=1;
  return ok;
}

// --------------- Funcao Insere nodo no fim
int insere_fim(nodo *p) {
  int ok=0;
  p->ant=ult;
  p->prox=NULL;
  ult->prox=p;
  ult=p;
  ok=1;
  return ok;
}

// --------------- Funcao Insere nodo em ordem crescente
int insere_ordem(nodo *p) {
  int ok=0;
  nodo *p1, *p2;
  if (prim!=NULL) {
    // ----- tem nodo na lista. pesquisa a posicao em ordem crescente
    p1=prim;
    p2=prim;
    // ----- caminha na lista procurando o 1 nodo maior
    while ((p1->n<p->n) && (p1->prox!=NULL)) {
      p2=p1;
      p1=p1->prox;
    }
    // ----- Saiu do while. Existem 3 hipoteses:
    if (p1==p2) {
      // ----- insere antes do primeiro nodo
      ok=insere_inicio(p);
    }
    else { // ----- do if (p1==p2)
      if ((p1->n<p->n) && (p1->prox==NULL)) {
	// ----- insere depois do ultimo nodo;
	ok=insere_fim(p);
      }
      else { // ----- if ((p1->n<p->n) && (p1->prox==NULL))
	// ----- insere no meio da lista ou antes do ultimo nodo;
	// ----- os comandos sao os mesmos nestes 2 casos!
	p->prox=p1;
	p->ant=p2;
	p1->ant=p;
	p2->prox=p;
	ok=1;
      } // ----- else do if ((p1->n<p->n) && (p1->prox==NULL))
    } // ----- else do if (p1==p2)
  } // ----- if (prim!=NULL)
  else
    // ----- lista vazia. insere primeiro nodo no inicio.
    ok=insere_inicio(p);
  return ok;
}

// --------------- Funcao Retira nodo no inicio
int retira_inicio(void) {
  int ok=0;
  nodo *p;
  p=prim;
  p->prox->ant=NULL;
  prim=p->prox;
  delete p;
  return ok;
}

// --------------- Funcao Retira nodo no final
int retira_fim(void) {
  int ok=0;
  nodo *p;
  p=ult->ant;
  p->prox=NULL;
  delete ult;
  ult=p;
  return ok;
}

// --------------- Funcao Retira nodo apontado
int retira_apontado(nodo *p) {
  int ok=0;
  p->ant->prox=p->prox;
  p->prox->ant=p->ant;
  delete p;
  return ok;
}

// --------------- Funcao acha nodo por ordem de chave primaria
nodo* acha_ordem(int chave) {
  int ok=0;
  nodo *p;
  ?
  return ok;
}

// --------------- Aqui e' necessario criar uma funcao para item do menu, que conversa com
//                 o usuario e chama as rotinas acima fornecidas


// --------------- Programa Principal

int main() {

  // ----- inicializacao e' comando executavel e so pode ficar dentro da main
  // --------------- Funcao Cria Lista vira somente este comando
  prim=NULL;
  ult=NULL;
  // cria_lista();

  int op=-1;
  while (op!=0) {
    op=menu();
    switch (op) {
      case 1: ins_inicio(); break;
      case 2:  ; break;
      case 3:  ; break;
      case 4:  ; break;
      case 5:  ; break;
      case 6:  ; break;
      case 7:  ; break;
      case 8:  ; break;
      case 9:  ; break;
      case 0: clrscr();
	      deletalista();
	      exit(0);
      default : printf("Bug!\n");
		exit(1); // Encerra programa com codigo erro.
    }
  }
  getch();
  return 0;
}

