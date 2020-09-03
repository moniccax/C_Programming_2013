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

// --------------- Declaracao de variaveis globais
#define esc 27
  // ----- largura e altura da tela. Varia com o S.O., a resolucao
  //       e o tipo de monitor. O padrao DOS puro e' 25 linhas x 80 colunas
  //       Com XP, a 1024x768, e monitor CRT 3x4 de 15" deu 48 lin. x 80 col.
  //       Com XP, a 1280x1024, LCD 3x4 de 15" deu 48 lin. x 80 col.
  //       Com 7, a 1024x600, LCD 16x9 de 10" deu 24 lin. x 80 col.
  const int larg=80, alt=24;

/* --------------- Convencoes para funcionamento da fila
fila vazia - head=max e tail=0
fila esgotada para enfileirar - tail+1=headx
fila sem elementos para desenfileirar - head==tail depois de
  if (head==max) // ----- incremento circular de head
*/

const int max=5;
int head=max, // ----- ponteiro para inicio da fila
    tail=0;  // ----- ponteiro para fim da fila

int fila[max];

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

// --------------- Funcao enfileira elemento
void enfileira(void) {
  int n;
  // ----- localiza uma posicao vaga no vetor da fila
  if (tail+1==head) {
    moldura();
    gotoxy(3, (alt-1));
    cout << "Nao ha espaco livre na fila";
    apito();
  }
  else {
    // ----- limpa tela e pede o elemento para enfileirar
    moldura();
    gotoxy(30,3); cout << "Enfileira elemento";
    gotoxy(3,7); cout << "Digite o elemento (n. inteiro) : ";
    cin >> n;
    fila[tail]=n;
    tail++;
    if (tail==max) // ----- incremento circular de tail
      tail=0;
  } // ----- else do if (tail<max)
} // ----- enfileira()

// --------------- Funcao desenfileira elemento
void desenfileira(void) {
  int n;
  char ch;
  moldura();
  gotoxy(30,3); cout << "Desenfileira elemento";
  if (head==max) // ----- incremento circular de head
    head=0;
  if (head==tail) {
    // ----- nao tem elemento para desenfileirar
    gotoxy(3, (alt-1));
    cout << "Nao existe elemento para desenfileirar";
    apito();
  }
  else {
    // ----- mostra elemento desenfileirado
    n=fila[head];
    head++;
    gotoxy(3,8);
    cout << "Elemento retirado da fila : " << n;
    gotoxy(3,(alt-1)); cout << "Tecle <enter> p/ continuar";
    // ----- espera especificamente um enter p/ continuar
    ch=tecla();
    while (ch!=13)
     ch=tecla();
  }
} // ----- desenfileira()

// --------------- Funcao Mostra Conteudo da fila
void mostrafila(void) {
  int i;
  // ----- limpa tela e percorre vetor de registro mostrando
  //       dados do funcionario
  moldura();
  gotoxy(30,3); cout << "Mostra fila";
  gotoxy(3,7); cout << "Head = " << head;
  gotoxy(3,8); cout << "Tail = " << tail;
  gotoxy(3,(alt-1));
  cout << "Pressione qualquer tecla para rolar a fila";
  for (i=0; i<max; i++) {
    gotoxy(3,9); cout << "Fila[" << i << "] = " << fila[i] << endl;
    tecla();
  }
} // ----- mostrafila()

// --------------- Funcao limpa fila
void limpafila(void) {
  int i;
  head=max, // ----- ponteiro para inicio da fila
  tail=0;   // ----- ponteiro para fim da fila
  for (i=0; i<max; i++)
    fila[i]=0;
} // ----- limpa fila

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
  return 0;
}

