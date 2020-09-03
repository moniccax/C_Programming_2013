/*****************************************************************
 * Autor: Gilmar Machado Grossi                                  *
 * Compilador: BC 3.1 Borland                                    *
 * Ambiente: Tela de scroll do DOS                               *
 * Modelo de memoria: Small                                      *
 * Data: 24/03 e 29/03 de 2011                                   *
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

// --------------- Declaracao de variaveis globais
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

// --------------- Funcao mostra menu na tela
int menu(void) {
  int resp=0;
  while ((resp<1) || (resp>5)) {
    clrscr();
    cout << "\t\t\tControle de Funcionarios\n\n";
    cout << "\t1 - Incluir\n";
    cout << "\t2 - Excluir\n";
    cout << "\t3 - Consultar\n";
    cout << "\t4 - Listar\n";
    cout << "\t5 - Sair\n\n";
    cout << "\tOpcao: ";
    cin >> resp;
    /* ----- apita um som de 275 Hz durante 0,35 seg. para
	     avisar que foi digitada opcao invalida */
    if ((resp<1) || (resp>5)) {
      cout << "\n\n\tOpcao Invalida";
      sound(275);
      delay(350);
      nosound();
    } // ----- if ((resp<1) || (resp>5))
  } // ----- while ((resp<1) || (resp>5))
  return resp;
} // ----- menu()

// --------------- Funcao Inclui Funcionario
void inclui(void) {
  int i;
  // ----- localiza uma posicao vaga no vetor de registros
  if (nf<max)
    i=nf+1;
  else {
    clrscr();
    cout << "\tNao ha espaco para Inclusao de Funcionarios\n";
    cout << "\tTecle <enter> p/ continuar\n";
    getch();
    exit(1);
  } // ----- else do if (nf<max)
  // ----- aponta proxima posicao livre no vetor de registros
  nf++;
  // ----- limpa tela e pede os dados do funcionario
  clrscr();
  cout << "\t\t\tInclusao de Funcionarios\n\n";
  cout << "\tNumero de matricula : ";
  cin >> grupo[i].nmat;
  cout << "\tNome .............. : ";
  cin >> grupo[i].nome;
  cout << "\tSalario ........... : ";
  cin >> grupo[i].salario;
} // ----- inclui()

// --------------- Funcao Exclui Funcionario
void exclui(void) {
  char ch;
  int i, nmat;
  /* ----- limpa tela e pede numero de matricula para localizar
	   dados do funcionario no vetor de registros */
  clrscr();
  cout << "\t\t\tExclusao de Funcionarios\n\n";
  cout << "\tNumero de matricula : ";
  cin >> nmat;
  // ----- localiza funcionario no vetor de registros
  for (i=0; nmat!=grupo[i].nmat; i++);
  // ----- mostra dados do funcionario para confirmacao da exclusao
  cout << "\tNome .............. : " << grupo[i].nome << endl;
  cout << "\tSalario ........... : " << grupo[i].salario << "\n\n";
  cout << "\tTecle <enter> p/ confirmar exclusao";
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
  } // ----- if (ch==13)
  nf--;
} // ----- exclui()

// --------------- Funcao Consulta Funcionario
void consulta(void) {
  int i, nmat;
  // ----- limpa tela e percorre vetor de registro mostrando
  //       dados do funcionario
  clrscr();
  cout << "\t\t\tConsulta de Funcionarios\n\n";
  cout << "\tNumero de matricula : ";
  cin >> nmat;
  for (i=0; ((nmat!=grupo[i].nmat) && (i<=nf)); i++);
  if (i<=nf) {
    cout << "\tNome .............. : " << grupo[i].nome << endl;
    cout << "\tSalario ........... : " << grupo[i].salario << "\n\n";
    cout << "\tTecle <enter> p/ continuar";
    getch();
  }
  else {
    cout << "\n\tNao existe este funcionario" << endl;
    getch();
  }
}

// --------------- Funcao Lista Funcionario
void lista(void) {
  int i;
  // ----- limpa tela e percorre vetor de registro mostrando
  //       dados do funcionario
  clrscr();
  cout << "\t\t\tLista Cadastro de Funcionarios\n\n";
  for (i=0; i<=nf; i++) {
    cout << "\tNumero de matricula : " << grupo[i].nmat << endl;
    cout << "\tNome .............. : " << grupo[i].nome << endl;
    cout << "\tSalario ........... : " << grupo[i].salario << "\n";
    cout << "\tTecle <enter> p/ continuar\n\n";
    getch();
  }
}

// --------------- Programa Principal
int main() {
  int op=0;
  int i,j;
  while (op!=5) {
    op=menu();
    switch (op) {
      case 1: inclui(); break;
      case 2: exclui(); break;
      case 3: consulta(); break;
      case 4: lista(); break;
      case 5: clrscr(); exit(0);
      default : printf("Bug!\n");
		exit(1); // Encerra programa com codigo erro.
    }
  }
  getch();
  return 0;
}

