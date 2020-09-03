/*********************************************************
*Autor: Daniel Silva da Fonseca                          *
*Compilador:BC 3.1                                       *
*Ambiente:                                               *
*Modelo de memoria: Small                                *
*Data: 10/03/2011                                        *
*Objetivo:Aprender a                                     *
*-ler uma quantidade indeterminada de dados              *
*-diferen‡a entre a tela de scroll do DOS e a tela cheia *
**********************************************************/
#include <string.h>
#include <constream.h>
void main();
const int max=20;
int nf=-1;
struct pessoa {
    int nmat;
    char nome[40];
    char endereço[40];
    char curso[20];// --------------- Funcao Consulta Funcionario
void consulta(void) {
  int i, nmat;
  // ----- limpa tela e percorre vetor de registro mostrando
  //       dados do funcionario
  clrscr();
  cout << "\t\t\tConsulta de Funcionarios\n\n";
  cout << "\tNumero de matricula : ";
  cin >> nmat;
  for (i=0; nmat!=grupo[i].nmat; i++);
  cout << "\tNome .............. : " << grupo[i].nome << endl;
  cout << "\tenderco ........... : " << grupo[i].endereco << "\n\n";
  cout << "\tcurso.............. :
  cout << "\tTecle <enter> p/ continuar";
  getch();
}

void consulta(void) {
  int i, nmat;
  clrscr();
  cout << "\t\t\tConsulta de Alunos\n\n";
  cout << "\tNumero de matricula : ";
  cin >> nmat;
  for (i=0; nmat!=grupo[i].nmat; i++);
  cout << "\tNome .............. : " << grupo[i].nome << endl;
  cout << "\tendereço ........... : " << grupo[i].endereco << "\n\n";
  cout << "\tcurso ........... : " << grupo[i].curso << "\n\n";
  cout << "\tnota ........... : " << grupo[i].nota << "\n\n";
  cout << "\tTecle <enter> p/ continuar";
  getch();
}
int main() {
  int op=0;
  int i,j;
  while (op!=5) {
    op=menu();
    switch (op) {
      case 1: inclui(); break;
      case 3: consulta(); break;
      case 5: clrscr(); exit(0);
      default : printf("Bug!\n");
		exit(1); // Encerra programa com codigo erro.
    }
  }
  getch();
  return 0;
}

    