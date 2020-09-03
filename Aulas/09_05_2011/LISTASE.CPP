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

// --------------- Declaracao de variaveis globais
#define esc 27
  // ----- largura e altura da tela. Varia com o S.O., a resolucao
  //       e o tipo de monitor. O padrao DOS puro e' 25 linhas x 80 colunas
  //       Com XP, a 1024x768, e monitor CRT 3x4 de 15" deu 48 lin. x 80 col.
  //       Com XP, a 1280x1024, LCD 3x4 de 15" deu 48 lin. x 80 col.
  //       Com 7, a 1024x600, LCD 16x9 de 10" deu 24 lin. x 80 col.
  const int larg=80, alt=24;

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

char tecla(void) {
  char ch1, ch2;
  unsigned char by; // um inteiro de 8 bits que por default e' visto como char
  ch1=getch();
  by=(int)ch1; // by contem o codigo da tecla "traduzido" para inteiro sem sinal de 8 bits
  if (by==0) {
    ch2=getch();
    by=(int)ch2;
    switch (by) {
      // ----- Seta para cima
      case 72 : by=128;
		break;
      // ----- Seta para baixo
      case 80 : by=129;
		break;
      // ----- Seta para direita
      case 77 : by=130;
		break;
      // ----- Seta para esquerda
      case 75 : by=131;
		break;
      // ----- DEL
      case 83 : by=127;
		break;
      // ----- Insert
      case 82 : by=135;
		break;
      // ----- Home
      case 71 : by=136;
		break;
      // ----- End
      case 79 : by=137;
		break;
      // ----- Page Up
      case 73 : by=138;
		break;
      // ----- Page Down
      case 81 : by=139;
		break;
      // ----- F1
      case 59 : by=140;
		break;
      // ----- F2
      case 60 : by=141;
		break;
      // ----- F3
      case 61 : by=142;
		break;
      // ----- F4
      case 62 : by=143;
		break;
      // ----- F5
      case 63 : by=144;
		break;
      // ----- F6
      case 64 : by=145;
		break;
      // ----- F7
      case 65 : by=146;
		break;
      // ----- F8
      case 66 : by=147;
		break;
      // ----- F9
      case 67 : by=148;
		break;
      // ----- F10
      case 68 : by=149;
		break;
      // ----- F11
      case 133 : by=150;
		break;
      // ----- F12
      case 134 : by=151;
		break;
    } // ----- switch (by)
    ch1=by;
  } // ----- if (by==0)
  return ch1;
} // ----- char tecla(void)

// --------------- Funcao apita um som de 275 Hz durante 0,35 seg.
void apito(void) {
  sound(275);
  delay(350);
  nosound();
  cout << " - Tecle <enter> p/ continuar";
  getch();
}

// --------------- Funcao apita um som de 275 Hz durante 0,35 seg.
void moldura(void) {
  int i;
  char Cima[81], Baixo[81], Meio[81], Comum[81];
  const char CimaEsq=201;
  const char CimaDir=187;
  const char BaixoEsq=200;
  const char BaixoDir=188;
  const char Vert=186;
  const char Horiz=205;
  const char TDir=185;
  const char TEsq=204;
  // --------------- Monta linha de Cima da Moldura
  Cima[0]=CimaEsq;
  for (i=1; i<=(larg-2); i++)
    Cima[i]=Horiz;
  Cima[(larg-1)]=CimaDir;
  Cima[larg]='\0';
  // --------------- Monta linha Comum da Moldura
  Comum[0]=Vert;
  for (i=1; i<=(larg-2); i++)
    Comum[i]=' ';
  Comum[(larg-1)]=Vert;
  Comum[larg]='\0';
  // --------------- Monta divisoria com caixa de status da Moldura
  Meio[0]=TEsq;
  for (i=1; i<=(larg-2); i++)
    Meio[i]=Horiz;
  Meio[(larg-1)]=TDir;
  Meio[larg]='\0';
  // --------------- Monta de baixo da Moldura
  Baixo[0]=BaixoEsq;
  for (i=1; i<=(larg-2); i++)
    Baixo[i]=Horiz;
  Baixo[(larg-1)]=BaixoDir;
  Baixo[larg]='\0';
  // --------------- Escreve Moldura na Tela
  clrscr();
  cout << Cima;
  cout << Comum;
  cout << Comum;  // ----- Nesta linha deve-se colocar o Titulo
  cout << Comum;
  cout << Meio;   // ----- Divisao do Titulo
  for (i=1; i<=(alt-8); i++)
    cout << Comum;// << endl;
  cout << Meio;   // ----- Divisao da linha de Status
  cout << Comum;
  cout << Baixo;
}
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
    lista_s[p2].prox=lista_s[p1].prox; // ----- nodo anterior passa a ter proximo = nodo a frente do removido
    lista_s[p1].prox=livre;            // ----- nodo removido passa a apontar 1o livre
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
  int p1;
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

