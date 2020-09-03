/* --------------- Por necessidade de uso local a inclusao das demais
		   bibliotecas ficou aqui. O programa usuario da Lecampo
		   necessita incluir apenas a mylib4y.h */
#include <constream.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* -------------- A rotina TECLA faz a leitura do teclado, caracter a
		  caracter, sem eco, e ainda trata as teclas estendidas
		  do IBM-PC que geram codigos de 2 bytes. O primeiro byte
		  das teclas estendidas que e' sempre zero, e' descartado,
		  e o segundo byte e' recodificado utilizando o espaco dos
		  caracteres graficos que nao sao utilizados no teclado, mas
		  somente no video. Leia o Guia do Programador IBM-PC de
		  Peter Norton para saber mais.
*/
char tecla(void) {
  char ch1, ch2;
  unsigned char by; /* um inteiro de 8 bits que por default e' "visto"
		       como char */
  ch1=getch();      // le a primeira tecla
  by=(int)ch1;      // by contem o codigo da tecla "traduzido" para inteiro
		    // sem sinal de 8 bits
  if (by==0) {      // se o 1o byte e' zero entao e' codigo estendido,
    ch2=getch();    // descarta, e le o 2o byte
    by=(int)ch2;    // "traduz" novamente em by
    // ----- recodifica as teclas de codigo estendido
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
    ch1=by; // ----- converte inteiro de 8 bits sem sinal em char
  } // ----- if (by==0)
  return ch1;
} // ----- char tecla(void)


/* --------------- ROTINA LE CAMPO

Prototipo:
void LE (int TC, int TM, int X, int Y, char str[]) {

----- VARIAVEIS PARAMETRO DE ENTRADA:
  TC -> TIPO DO CAMPO : 1 - ALFABETICO
			2 - ALFANUMERICO
			3 - NUMERICO
			4 - NUMERICO + "."
			5 - NUMERICO + "-"
			6 - Sim ou Nao SsNn
			7 - CPF
  Para TC negativo, o tipo de campo e' o mesmo, porem protegido i.e.,
  ecoa asterisco ao inves do que foi digitado. Bom para ler senhas por ex.
  TM -> TAMANHO DO CAMPO em caracteres de 1 byte.
  X  -> COLUNA da tela onde comeca o campo.
  Y  -> LINHA  da tela onde comeca o campo.
	O CURSOR SERA' POSICIONADO NA 1 POSICAO DO CAMPO
  char str[] -> vetor de char que entra vazio para ler um campo normal
		ou preenchido com o valor do campo pre-prenchido que e'
		utilizado para alteracao.
----- VARIAVEL PARAMETRO DE SAIDA:
      char str[] -> Dado lido no campo. O cursor permanecera uma posicao
		    alem da ultima digitada. A condicao de saida e' um
		    caracter <CR>
----- VARIAVEIS INTERNAS AUXILIARES

  digitado - caracter digitado
  tamanho  - quantidade de caracteres digitados
  gtc      - guarda tipo de campo recebido com sinal
  qte      - quantidade de caracteres recebidos na entrada de LE em char str[]
  C        - coluna da tela durante edicao do campo
								      */
char digitado;
int tamanho = 0;
int i, j, C, gtc, qte;
unsigned char toogle=1; // segura loop lendo caracteres do campo
char VD[6][255]; // Matriz de char para armazenar os caracteres validos para
		 // cada tipo de campo

// ----- Constantes que definem acoes de edicao no campo
const char CR = 13;          // Enter
const char BS = 8;           // BackSpace volta apagando
const char DEL = 127;        // Deleta o caracter em cima do cursor
const char HOME = 136;       // Volta ao inicio do campo
const char END = 137;        // Vai para o final do campo
const char LEFTARROW = 131;  // Seta para esquerda volta por cima sem apagar
const char RIGTHARROW = 130; // Seta para direita avanca por cima sem apagar

void LE (int TC, int TM, int X, int Y, char str[]) {
  // --------------- Inicializacoes da rotina LECAMPO
  // ----- Coloca terminador de vetor de char em todas as posicoes de VD
  for (i=0; i<6; i++) {
    for (j=0; j<255; j++) {
      VD[i][j] = '\0';
    } // ----- for j
  } // ----- for i

  // ----- coloca letras A-Z e a-z em VD[0] campo 1 - alfabetico
  strcpy(VD[0], "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz ");
  // ----- coloca os digitos de zero a nove em VD[2], VD[3], VD[4] e VD[5]
  // ----- e acrescenta caracteres extras nos campos 3, 4 e 5
  strcpy(VD[2], "0123456789");
  strcpy(VD[3], "0123456789.");
  strcpy(VD[4], "0123456789-");
  strcpy(VD[5], "0123456789/-");

  // ----- coloca espaco em todas as posicoes de VD[1] campo 2 - alfanumerico
  for (i=0; i<255; i++) VD[1][i]=' ';
  // ----- coloca todos os caracteres do espaco (32) ate o 126 em VD[1] campo 2 - alfanumerico
  for (i=32; i<=126; i++) VD[1][i]=i;

  // ----- preenche o campo 6 - Sim ou Nao
  VD[6][0]='s';
  VD[6][1]='S';
  VD[6][2]='N';
  VD[6][3]='n';

  // --------------- LeCampo propriamente dita
  gtc=TC;          // ----- guarda tipo de campo caso seja negativo (protegido)
  if (TC<0)
    TC=TC*(-1);    // ----- tira sinal negativo do tipo de campo (protegido)
  qte=strlen(str); // ----- pega tamanho do campo (!=0) campo prepreenchido
  if (qte!=0) {    // ----- se campo prepreenchido, mostra conteudo recebido
    gotoxy(X,Y);
    cout << str;
    for (i=qte; i<255; i++) str[i]='\0';
  }
  gotoxy(X,Y);        // ----- posiciona cursor no inicio do campo
  while (toogle) {
    digitado=tecla();// ----- le caracter do teclado mas sem eco
    switch (digitado) {
      case DEL :
	if (tamanho!=0) {
	  tamanho--;
	  str[tamanho]='\0';
	  C=X+tamanho;
	  gotoxy(C,Y);
	  cout << ' ';
	  gotoxy(C,Y);
	} // if (tamanho != 0)
	break;
      case BS :
	if (tamanho!=0) {
	  tamanho--;
	  str[tamanho]='\0';
	  C=X+tamanho;
	  gotoxy(C,Y);
	  cout << ' ';
	  gotoxy(C,Y);
	} // if (tamanho != 0)
	break;
      case CR :
	toogle=0;
	break;
      case HOME :
	gotoxy(X,Y);
	break;
      case END :
	gotoxy(qte,Y);
	break;
      case LEFTARROW :
	if (C>X){
	C--;
	gotoxy(C,Y);
	}
	break;
      case RIGTHARROW :
	if (C<TM){
	  C++;
	  gotoxy(C,Y);
	}
	break;
      default : // ----- caracter para consistir
	if (tamanho<TM) {
	  if (strchr(VD[TC-1], digitado)!=NULL) { // Procura a ocorrencia do valor digitado no vetor de condicoes;
	    if (gtc<0)
	      cout << '*';
	    else
	      cout << digitado;
	    str[tamanho]=digitado;
	    tamanho++;
	  } // ----- if (strchr(VD[TC-1], digitado)!=NULL)
	} // ----- if (tamanho<TM)
    }  // ----- switch (digitado)
  } // ----- while (toogle)
  if (qte==0) // ----- campo prepreenchido, aproveita conteudo recebido
    str[tamanho] = '\0';
} // void LE


/*
  while (digitado != CR) {
    while ((digitado != CR && tamanho < TM) || digitado == DEL) {
      if (digitado != DEL) {
	// ----- tem caracter digitado diferente de CR e DEL. Trata ele.
	if (strchr(VD[TC-1], digitado) != NULL) { // Procura a ocorrencia do valor digitado no vetor de condicoes;
	  if (gtc<0)
	    cout << '*';
	  else
	    cout << digitado;
	  str[tamanho] = digitado;
	  tamanho++;
//	  str[tamanho] = '\0';
	}
      }
      else { // if (digitado != DEL)
	// ----- Trata o BackSpace
	if (tamanho != 0) {
	  tamanho--;
	  str[tamanho] = '\0';
	  int C = X + tamanho;
	  gotoxy(C,Y);
	  cout <<' ';
	  gotoxy(C,Y);
	} // if (tamanho != 0)
      } // else do if (digitado != DEL)
      digitado = tecla();
    } // while ((digitado != CR && tamanho < TM) || digitado == DEL)
    if (digitado!=CR)
      while ((digitado!=CR)&&(digitado!=DEL))
	digitado = tecla();
  } // while (digitado != CR)

  if (qte==0) // ----- campo prepreenchido, aproveita conteudo recebido
    str[tamanho] = '\0';

} // void LE
*/


