/*****************************************************************
 * Autor: Gilmar Machado Grossi                                  *
 * Compilador: BC 3.1 Borland                                    *
 * Ambiente: Tela de scroll do DOS                               *
 * Modelo de memoria: Small                                      *
 * Data: 31/08 e 05/09 de 2011                                   *
 * Objetivo: Exemplo de lista simplesmente encadeada sobre vetor *
 *           estatico                                            *
 *****************************************************************/

// ----- Inclui as bibliotecas necessarias

#include <iostream.h> // cout, cin, endl
#include <stdio.h> // printf e scanf
#include <conio.h> // clrscr() e getch()
#include <dos.h> // sound(), nosound() e delay()
#include <process.h> // exit()

#include "C:\USERS\ANNA\DOCUME~1\FELIPPE\ALP\moldura.h"

// --------------- Declaracao de variaveis globais
#define esc 27
  // ----- largura e altura da tela. Varia com o S.O., a resolucao
  //       e o tipo de monitor. O padrao DOS puro e' 25 linhas x 80 colunas
  //       Com XP, a 1024x768, e monitor CRT 3x4 de 15" deu 48 lin. x 80 col.
  //       Com XP, a 1280x1024, LCD 3x4 de 15" deu 48 lin. x 80 col.
  //       Com 7, a 1024x600, LCD 16x9 de 10" deu 24 lin. x 80 col.


/* --------------- Convencoes para funcionamento desta lista encadeada
Lista vazia - prim=nulo; e livre=0;
Lista esgotada para insercao de novos elementos - livre=nulo;
Nodos para 1 elemento inteiro, alocados sobre vetor estatico
*/

struct nodo {
  int n;    // ----- area de dado do nodo, somente um inteiro
  int prox; // ----- area de ponteiro do nodo, aponta so' o proximo nodo
}; // ----- struct nodo

const int nulo=-1;
const int max=5;
int prim=nulo, // ----- ponteiro para inicio da lista simplesmente encadeada
    livre=0;   // ----- ponteiro para lista de nodos livres

nodo lista_s[max];

// --------------- Funcao mostra menu na tela
int menu(void) {
  int resp=0;
  while ((resp<1) || (resp>5)) {
    moldura();
    gotoxy(14,3);  cout << "Lista simplesmente Encadeada sobre vetor estatico";
    gotoxy(28,7);  cout << "1 - Incluir elemento";
    gotoxy(28,8);  cout << "2 - Excluir elemento";
    gotoxy(28,9);  cout << "3 - Mostrar toda a Lista";
    gotoxy(28,10); cout << "4 - Limpar a Lista";
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

// --------------- Funcao Cria Lista
void cria_lista(void) {
  int i;
  prim=nulo; // ----- lista vazia
  livre=0;   // ----- livre aponta 1a posicao do vetor ou o 1o nodo
  for (i=0; i<max; i++) {
    lista_s[i].n=0;         // ----- zera area de dados do nodo
    lista_s[i].prox=i+1;    // ----- campo prox aponta proximo nodo
  }
  lista_s[max-1].prox=nulo; // ----- ultimo nodo tem prox aterrado
} // ----- cria_lista()

// --------------- Funcao Inclui elemento
void inclui(void) {
  int n, p;
  // ----- localiza um nodo livre no vetor da lista
  if (livre!=nulo) {
    // ----- limpa tela e pede o elemento para incluir
    moldura();
    gotoxy(30,3); cout << "Inclui elemento";
    gotoxy(3,7); cout << "Digite o elemento (n. inteiro) : ";
    cin >> n;
    p=lista_s[livre].prox;    // ----- salva endereco proximo nodo livre
    lista_s[livre].n=n;       // ----- guarda o elemento
    lista_s[livre].prox=prim; // ----- o novo nodo.prox aponta o antigo 1o da lista
    prim=livre;               // ----- prim aponta o novo 1o nodo
    livre=p;                  // ----- livre atualizado p/ novo nodo livre
  }
  else {
    moldura();
    gotoxy(3, (alt-1));
    cout << "Nao ha nodos livres na Lista";
    apito();
  } // ----- else do if (livre!=nulo)
} // ----- inclui()

// --------------- Funcao exclui elemento
void exclui(void) {
  int n, p1, p2;
  char ch;
  // ----- limpa tela e pede o elemento para excluir
  moldura();
  gotoxy(30,3); cout << "Exclui elemento";
  gotoxy(3,7); cout << "Digite o elemento (n. inteiro) : ";
  cin >> n;
  // ----- Caminha na lista procurando o elemento
  p1=prim;
  while ((lista_s[p1].n!=n) && (lista_s[p1].prox!=nulo)) {
    p2=p1;               // ----- guarda endereco nodo anterior
    p1=lista_s[p1].prox; // ----- "anda" para proximo nodo
  }
  if (lista_s[p1].n==n) {
    // ----- Achou. Remove o nodo da lista
    if (p1==prim)
      prim=lista_s[p1].prox;
    else
      lista_s[p2].prox=lista_s[p1].prox; // ----- nodo anterior passa a ter proximo = nodo a frente do removido
    lista_s[p1].prox=livre;	    // ----- nodo removido passa a apontar 1o livre
    lista_s[p1].n=nulo;
    livre=p1;                          // ----- livre aponta nodo removido
    gotoxy(3,8);
    cout << "Elemento retirado da Lista";
    gotoxy(3,(alt-1)); cout << "Tecle <enter> p/ continuar";
    // ----- espera especificamente um enter p/ continuar
    ch=getch();
    while (ch!=13)
     ch=getch();
  }
  else {
    // ----- Nao Achou. Avisa o usuario
    gotoxy(3, (alt-1));
    cout << "Nao existe este elemento na lista";
    apito();
  }
} // ----- exclui()

// --------------- Funcao Mostra Conteudo da lista
void mostralista(void) {
  int p1, y;
  // ----- limpa tela e percorre a lista mostrando conteudo dos nodos
  moldura();
  gotoxy(30,3); cout << "Mostra Lista";
  gotoxy(3,7); cout << "prim  = " << prim;
  gotoxy(3,8); cout << "livre = " << livre;
  gotoxy(3,(alt-1));
  cout << "Pressione qualquer tecla para rolar a lista";
  p1=prim;
  while (lista_s[p1].prox!=nulo) {
    gotoxy(3,9); cout << "Lista[" << p1 << "] = " << lista_s[p1].n << endl;
    getch();
    p1=lista_s[p1].prox; // ----- "anda" para proximo nodo
  }
  // ----- mostra ultimo nodo
  gotoxy(3,9); cout << "Lista[" << p1 << "] = " << lista_s[p1].n << endl;
  getch();
  // ----- limpa tela e percorre a lista mostrando conteudo de nodos livre
  moldura();
  gotoxy(30,3); cout << "Mostra Lista de nodos livres";
  gotoxy(3,7); cout << "prim  = " << prim;
  gotoxy(3,8); cout << "livre = " << livre;
  gotoxy(3,(alt-1));
  cout << "Pressione qualquer tecla para rolar a lista";
  p1=livre;
  while (lista_s[p1].prox!=nulo) {
    gotoxy(3,9); cout << "Lista[" << p1 << "] = " << lista_s[p1].n << endl;
    getch();
    p1=lista_s[p1].prox; // ----- "anda" para proximo nodo
  }
  // ----- mostra ultimo nodo
  gotoxy(3,9); cout << "Lista[" << p1 << "] = " << lista_s[p1].n << endl;
  for(y=0; y<max; y++){
    cout << "\n n = " << lista_s[y].n << " prox = " << lista_s[y].prox;
    getch();
  }
  getch();
} // ----- mostrafila()

// --------------- Programa Principal

int main() {

  cria_lista();
  int op=0;
  while (op!=5) {
    op=menu();
    switch (op) {
      case 1: inclui(); break;
      case 2: exclui(); break;
      case 3: mostralista(); break;
      case 4: cria_lista(); break;
      case 5: clrscr();
	      exit(0);
      default : printf("Bug!\n");
		exit(1); // Encerra programa com codigo erro.
    }
  }
  getch();
  return 0;
}

