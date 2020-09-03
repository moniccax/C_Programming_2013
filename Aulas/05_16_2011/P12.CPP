/*****************************************************************
 * Autor: Gilmar Machado Grossi                                  *
 * Compilador: BC 3.1 Borland                                    *
 * Ambiente: Tela de scroll do DOS                               *
 * Modelo de memoria: Small                                      *
 * Data: 02/05 e 03/05 de 2011                                   *
 * Objetivo: Ser um programa exemplo para as aulas praticas de   *
 *           algoritmo e logica de programacao, mostrando o uso  *
 *	     de vetores e de registro. Tambem e mostrado o uso   *
 *	     da tela cheia do DOS.                               *
 *****************************************************************/

// ----- Inclui as bibliotecas necessarias

#include <iostream.h> // cout, cin, endl
#include <stdio.h> // printf e scanf
#include <conio.h> // clrscr() e getch()
#include <dos.h> // sound(), nosound() e delay()
#include <process.h> // exit()
#include <string.h> // funcoes para manipulacao de vetor de char
#include <fstream.h> // funcoes de arquivo em C++

// --------------- Declaracao de variaveis globais
#define esc 27
  // ----- largura e altura da tela. Varia com o S.O., a resolucao
  //       e o tipo de monitor. O padrao DOS puro e' 25 linhas x 80 colunas
  //       Com XP, a 1024x768, e monitor CRT 3x4 de 15" deu 48 lin. x 80 col.
  //       Com XP, a 1280x1024, LCD 3x4 de 15" deu 48 lin. x 80 col.
  //       Com 7, a 1024x600, LCD 16x9 de 10" deu 24 lin. x 80 col.
  const int larg=80, alt=24;

  const int max=20;
  int nf=-1; // indice para apontar ultimo dado gravado no vetor grupo
  struct pessoa {
    int nmat;
    char nome[40];
    float salario;
  }; // ----- struct pessoa

  /* ----- grupo e' um vetor de registro que armazena os dados de
	   todos os funcionarios durante a execucao do programa */
  pessoa grupo[max];

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
    gotoxy(28,3);  cout << "Controle de Funcionarios";
    gotoxy(28,7);  cout << "1 - Incluir";
    gotoxy(28,8);  cout << "2 - Excluir";
    gotoxy(28,9);  cout << "3 - Consultar";
    gotoxy(28,10); cout << "4 - Listar";
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

// --------------- Funcao Inclui Funcionario
void inclui(void) {
  int i, j, nmat;
  // ----- localiza uma posicao vaga no vetor de registros
  if (nf<max)
    i=nf+1;
  else {
    moldura();
    gotoxy(3, (alt-1));
    cout << "Nao ha espaco para Inclusao de Funcionarios";
    apito();
    exit(1);
  } // ----- else do if (nf<max)
  // ----- limpa tela e pede os dados do funcionario
  moldura();
  gotoxy(30,3); cout << "Inclusao de Funcionarios";
  gotoxy(3,7); cout << "Numero de matricula : ";
  cin >> nmat;
  // ----- localiza funcionario no vetor de registros
  for (j=0; ((nmat!=grupo[j].nmat) && (j<=nf)); j++);
  if (nmat==grupo[j].nmat) {
    // ---- Ja existe funcionario com este numero de matricula
    gotoxy(3, (alt-1));
    cout << "Ja existe funcionario com esta matricula";
    apito();
  }
  else {
    grupo[i].nmat=nmat;
    gotoxy(3,8); cout << "Nome .............. : ";
    cin >> grupo[i].nome;
    gotoxy(3,9); cout << "Salario ........... : ";
    cin >> grupo[i].salario;
    // ----- atualiza ponteiro ultimo colocado no vetor de registros
    nf++;
  } // ----- else do if (nmat==grupo[i].nmat)
} // ----- inclui()

// --------------- Funcao Exclui Funcionario
void exclui(void) {
  char ch;
  int i, nmat;
  /* ----- limpa tela e pede numero de matricula para localizar
	   dados do funcionario no vetor de registros */
  moldura();
  gotoxy(30,3); cout << "Exclusao de Funcionarios";
  gotoxy(3,7); cout << "Numero de matricula : ";
  cin >> nmat;
  // ----- localiza funcionario no vetor de registros
  for (i=0; ((nmat!=grupo[i].nmat) && (i<=nf)); i++);
  if (nmat!=grupo[i].nmat) {
    // ----- nao achou funcionario com esta matricula
    gotoxy(3, (alt-1));
    cout << "Nao existe funcionario com esta matricula";
    apito();
  }
  else {
    // ----- mostra dados do funcionario para confirmacao da exclusao
    gotoxy(3,8);
    cout << "Nome .............. : " << grupo[i].nome;
    gotoxy(3,9);
    cout << "Salario ........... : " << grupo[i].salario;
    gotoxy(3,(alt-1)); cout << "Tecle <enter> p/ confirmar exclusao";
    // ----- espera especificamente um enter p/ confirmar exclusao
    ch=getch();
    if (ch==13) {
      /* ----- exclui funcionario do vetor copiando os registros
	       seguintes 1 posicao para cima do localizado */
      for (; i<=nf; i++) {
	grupo[i].nmat=grupo[i+1].nmat;
	strcpy(grupo[i].nome, grupo[i+1].nome);
	grupo[i].salario=grupo[i+1].salario;
      } // ----- for (; i<=nf; i++)
      // ----- atualiza ponteiro ultimo colocado no vetor de registros
      nf--;
    } // ----- if (ch==13)
  } // ----- else do if ((nmat!=grupo[i].nmat) && (i<=nf))
} // ----- exclui()

// --------------- Funcao Consulta Funcionario
void consulta(void) {
  int i, nmat;
  // ----- limpa tela e percorre vetor de registro mostrando
  //       dados do funcionario
  moldura();
  gotoxy(30,3); cout << "Consulta de Funcionarios";
  gotoxy(3,7); cout << "Numero de matricula : ";
  cin >> nmat;
  for (i=0; ((nmat!=grupo[i].nmat) && (i<=nf)); i++);
  if (nmat!=grupo[i].nmat) {
    // ----- nao achou funcionario com esta matricula
    gotoxy(3,(alt-1));
    cout << "Nao existe funcionario com esta matricula";
    apito();
  }
  else {
    gotoxy(3,8); cout << "Nome .............. : " << grupo[i].nome;
    gotoxy(3,9); cout << "Salario ........... : " << grupo[i].salario;
    gotoxy(3,(alt-1)); cout << "Tecle <enter> p/ continuar";
    getch();
  } // ----- else do if ((nmat!=grupo[i].nmat) && (i<=nf))
}

// --------------- Funcao Lista Funcionario
void lista(void) {
  int i;
  unsigned char by;
  char ch, limpa[51];
  // ----- limpa tela e percorre vetor de registro mostrando
  //       dados do funcionario
  // ----- linha em branco para "apagar" campo
  for (i=0; i<38; i++)
    limpa[i]=' ';
  limpa[38]='\0';
  moldura();
  gotoxy(25,3); cout << "Lista Cadastro de Funcionarios";
  if (nf==(-1)) {
    gotoxy(3,(alt-1)); cout << "Nao existem dados para listar.";
    apito();
  }
  else {
    i=0;
    by=0;
    while (by!=esc) {
      gotoxy(24,7); cout << limpa;
      gotoxy(3,7); cout << "Numero de matricula : " << grupo[i].nmat;
      gotoxy(24,8); cout << limpa;
      gotoxy(3,8); cout << "Nome .............. : " << grupo[i].nome;
      gotoxy(24,9); cout << limpa;
      gotoxy(3,9); cout << "Salario ........... : " << grupo[i].salario;
      gotoxy(3,(alt-1)); cout << "Use as setas ou <esc> p/ sair";
      ch=tecla();
      by=int(ch);
      if (by==128) {
	// ----- novo codigo tecla seta p/ cima
	i--;
	if (i<0) i=nf;
      } // ----- if (ch==128)
      if (by==129) {
	// ----- novo codigo tecla seta p/ cima
	i++;
	if (i>nf) i=0;
      } // ----- if (ch==128)
    } // ----- while
  } // ----- else
} // ----- lista


// --------------- Funcao Le Arquivo
void le(void) {
  int i;
  ifstream arq("c:\\bc31\\bin\\func.dat", ios::in | ios::nocreate | ios::binary);
  // ----- uma alternativa ao arq.fail() e' o arq.good()
  // if (arq.good()) {
  if (!arq.fail()) {
    // ----- Arquivo existe, entao le
    i=0;
    while (!arq.eof()) {
      arq.read((char*)&grupo[i], sizeof(pessoa));
      i++;
    }
    nf=i-2; // ----- feof le 1 a mais e depois ainda tem i++
    arq.close();
  }
  else {
    // ----- Arquivo nao existe, continua com vetor grupo vazio
  }
}

// --------------- Funcao Grava Arquivo
void grava(void) {
  int i;
  ofstream arq("c:\\bc31\\bin\\func.dat", ios::out | ios::binary);
  // ----- uma alternativa ao arq.fail() e' o arq.good()
  if (arq.good()) {
  // if (!arq.fail()) {
    // ----- Arquivo abriu, entao grava
    for (i=0; i<=nf; i++)
      arq.write((char*)&grupo[i], sizeof(pessoa));
    arq.close();
  }
  else {
    // ----- Arquivo nao existe, continua com vetor grupo vazio
  }
}

// --------------- Programa Principal
int main() {
  int op=0;
  int i,j;
  le();
  while (op!=5) {
    op=menu();
    switch (op) {
      case 1: inclui(); break;
      case 2: exclui(); break;
      case 3: consulta(); break;
      case 4: lista(); break;
      case 5: clrscr();
	      grava();
	      exit(0);
      default : printf("Bug!\n");
		exit(1); // Encerra programa com codigo erro.
    }
  }
  getch();
  return 0;
}

