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

#include <dos.h> // sound(), nosound() e delay()
#include <fstream.h>
#include "c:\bc31\bin\mylib4.h"
// --------------- Declaracao de variaveis globais
  const int max=20;
  int nf=-1, nmat; // indice para apontar ultimo dado gravado no vetor grupo
  struct pessoa {
    int nmat;
    char nome[40];
    char salario[10];
  }; // ----- struct pessoa

  /* ----- grupo e' um vetor de registro que armazena os dados de
	   todos os funcionarios durante a execucao do programa */
  pessoa grupo[max];



void molde(void) {
  int x,y;
  gotoxy(1,1);
  cout << "\xC9";
  for(x=2 ; x<80 ; x++){
    gotoxy(x,1);
    cout << "\xCD";
  }
  gotoxy(79,1);
  cout << "\xBB";
  for(y=2 ; y<25 ; y++){
    gotoxy(1,y);
    cout << "\xBA";
  }
  gotoxy(1,25);
  cout << "\xC8";
  for(x=2 ; x<80 ; x++){
    gotoxy(x,25);
    cout << "\xCD";
  }
  gotoxy(79,25);
  cout << "\xBC";
  for(y=24 ; y>1 ; y--){
    gotoxy(79,y);
    cout << "\xBA";
  }
  gotoxy(1,20);
  cout << "\xCC";
  for(x=2 ; x<79 ; x++){
    gotoxy(x,20);
    cout << "\xCD";
  }
  gotoxy(79,20);
  cout << "\xB9";
  }

void abrir(){
  int i;
  ifstream arq("c:\\bc31\\bin\\p8arq.bat", ios::in | ios::binary);
  if(arq!=NULL){
    if(arq.good()){
      i=0;
      while(!arq.eof()){
	arq.read((char*)&grupo[i], sizeof(pessoa));
	i++;
      }
    nf=i-2;
    }
    arq.close();
    clrscr();
    molde();
    gotoxy(10,22);
    cout << "Arquivo aberto com sucesso.";
    gotoxy(10,23);
    cout << "Tecle <enter> para continuar...";
    getch();
  }
  else{
    clrscr();
    molde();
    gotoxy(10,22);
    cout << "Nao ha arquivo a ser lido.";
    gotoxy(10,23);
    cout << "Criando arquivo...";
    getch();
  }
}

void salvar(){
  int i;
  molde();
  ofstream arq("c:\\bc31\\bin\\p8arq.bat", ios::out | ios::trunc | ios::binary );
  for( i=0; i<=nf; i++) {
    arq.write((char*) &grupo[i], sizeof(pessoa));
  }
  arq.close();
    clrscr();
    molde();
    gotoxy(10,22);
    cout << "Funcionarios arquivados com sucesso.";
    getch();
}


// --------------- Funcao mostra menu na tela
int menu(void) {
  int resp=0;
  while ((resp<1) || (resp>6)) {
    clrscr();
    molde();
    gotoxy(10,5);
    cout << "\t\tControle de Funcionarios";
    gotoxy(10,7);
    cout << "1 - Incluir";
    gotoxy(10,8);
    cout << "2 - Excluir";
    gotoxy(10,9);
    cout << "3 - Consultar";
    gotoxy(10,10);
    cout << "4 - Listar";
    gotoxy(10,11);
    cout << "5 - Altera";
    gotoxy(10,12);
    cout << "6 - Sair";
    gotoxy(10,14);
    cout << "Opcao: ";
    cin >> resp;
    /* ----- apita um som de 275 Hz durante 0,35 seg. para
	     avisar que foi digitada opcao invalida */
    if ((resp<1) || (resp>6)) {
      gotoxy(10,20);
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
  int i, j, nteste;
  // ----- localiza uma posicao vaga no vetor de registros
  if (nf<max)
    i=nf+1;
  else {
    clrscr();
    molde();
    gotoxy(10,22);
    cout << " Nao ha espaco para Inclusao de Funcionarios.";
    gotoxy(10,23);
    cout << " Tecle <enter> p/ continuar...";
    getch();
    exit(1);
  } // ----- else do if (nf<max)
  // ----- aponta proxima posicao livre no vetor de registros
  // ----- limpa tela e pede os dados do funcionario
  clrscr();
  molde();
  gotoxy(20,3);
  cout << " Inclusao de Funcionarios.";
  gotoxy(4,6);
  cout << " Numero de matricula : ";
  cin >> nteste;
  for (j=0; grupo[j].nmat!=nteste && j<=nf ; j++);
  if (nteste==grupo[j].nmat) {
      gotoxy(10,23);
      cout << " O numero de matricula ja existe.Tente novamente.";
      }
    else{
      grupo[i].nmat=nteste;
      gotoxy(4,7);
      cout << " Nome .............. : ";
     // cin >> grupo[i].nome;
      gets(grupo[i].nome);
      gotoxy(4,8);
      cout << " Salario ........... : ";
      cin >> grupo[i].salario;
      nf++;
      gotoxy(10,23);
      cout << "Funcionario arquivado. " ;
      }
    getch();

   }
  // }// ------- fecha if
  //} ----- inclui()



// --------------- Funcao Exclui Funcionario
void exclui(void) {
  char ch;
  int i, nmat;
  /* ----- limpa tela e pede numero de matricula para localizar
	   dados do funcionario no vetor de registros */
  clrscr();
  molde();
  gotoxy(25,3);
  cout << " Exclusao de Funcionarios.";
  gotoxy(4,5);
  cout << " Numero de matricula : ";
  cin >> nmat;
  // ----- localiza funcionario no vetor de registros
  for (i=0; ((nmat!=grupo[i].nmat) && (i<=nf)); i++);
  if(i>nf) {
    gotoxy(10,22);
    cout << " Funcionario inexistente.";
    getch();
  }
  else{
    // ----- mostra dados do funcionario para confirmacao da exclusao
    gotoxy(4,6);
    cout << " Nome .............. : " << grupo[i].nome;
    gotoxy(4,7);
    cout << " Salario ........... : " << grupo[i].salario;
    gotoxy(10,22);
    cout << " Tecle <enter> p/ confirmar exclusao.";
    // ----- espera especificamente um enter p/ confirmar exclusao
    ch=getch();
    if (ch==13) {
      /* ----- exclui funcionario do vetor copiando os registros
	     seguintes 1 posicao para cima do localizado */
      for (; i<=nf; i++) {
	grupo[i].nmat=grupo[i+1].nmat;
	strcpy(grupo[i].nome, grupo[i+1].nome);
	strcpy(grupo[i].salario,grupo[i+1].salario);
      } // ----- for (; i<=nf; i++)
    } // ----- if (ch==13)
    nf--;
    }
  } // ----- exclui()

// --------------- Funcao Consulta Funcionario
void consulta(void) {
  int i, nmat;
  // ----- limpa tela e percorre vetor de registro mostrando
  //       dados do funcionario
  clrscr();
  molde();
  gotoxy(20,3);
  cout << " Consulta de Funcionarios.";
  gotoxy(4,5);
  cout << " Numero de matricula : ";
  cin >> nmat;
  for (i=0; ((nmat!=grupo[i].nmat) && (i<=nf)); i++);
  if (i<=nf) {
    gotoxy(4,6);
    cout << " Nome .............. : " << grupo[i].nome;
    gotoxy(4,7);
    cout << " Salario ........... : " << grupo[i].salario;
    gotoxy(10,22);
    cout << " Tecle <enter> p/ continuar...";
    getch();
  }
  else {
    gotoxy(10,22);
    cout << " Funcionario inexistente.";
    getch();
  }
}

// --------------- Funcao Lista Funcionario
void lista(void) {
  int i, seta;
  // ----- limpa tela e percorre vetor de registro mostrando
  //       dados do funcionario
  clrscr();
  molde();
  gotoxy(20,3);
  cout << " Lista Cadastro de Funcionarios.";
  i=0;
  while(seta!=13){
    if(i<0){
      clrscr();
      molde();
      gotoxy(20,3);
      cout << " Lista Cadastro de Funcionarios.";
      gotoxy(10,22);
      cout << " Nao existe funcionario anterior a este.";
      gotoxy(10,23);
      cout << " Tecle enter p/ sair...";
      getch();
      break;
    }
    if(i>nf){
      clrscr();
      molde();
      gotoxy(20,3);
      cout << " Lista Cadastro de Funcionarios.";
      gotoxy(10,22);
      cout << " Fim da lista de funcionarios.";
      gotoxy(10,23);
      cout << " Tecle enter p/ sair...";
      getch();
      break;
    }
    clrscr();
    molde();
    gotoxy(20,3);
    cout << " Lista Cadastro de Funcionarios.";
    gotoxy(4,5);
    cout << " Numero de matricula : " << grupo[i].nmat;
    gotoxy(4,6);
    cout << " Nome .............. : " << grupo[i].nome;
    gotoxy(4,7);
    cout << " Salario ........... : " << grupo[i].salario;
    gotoxy(10,22);
    cout << " Tecle enter p/ sair...";
    gotoxy(10,23);
    cout << " Tecle <seta para cima> p/ consultar o funcionario anterior.";
    gotoxy(10,24);
    cout << " Tecle <seta para baixo> p/ verificar o funcionario seguinte.";
    seta=getch();
    if(seta==72)
      i--;
    if(seta==80)
      i++;
  }
}

int altera (void) {
  int nteste, j, op, v;
  clrscr();
  molde();
  gotoxy(20,3);
  cout << " Alteracao de dados de funcionarios.";
  gotoxy(4,6);
  cout << " Digite o numero de matricula: ";
  cin >> nteste;
  for (i=0; grupo[i].nmat!=nteste && i<=nf ; i++);
  if (nteste!=grupo[i].nmat) {
      gotoxy(10,23);
      cout << " O numero de matricula nao existe.Tente novamente.";
      getch();
  }
  else{
    clrscr();
    molde();
    gotoxy(40,6);
    cout << " Nome .............. : " << grupo[i].nome;
    gotoxy(40,7);
    cout << " Salario ........... : " << grupo[i].salario;
    gotoxy(3,4);
    cout << "O que voce deseja alterar? ";
    gotoxy(3,6);
    cout <<"1 - Nome";
    gotoxy(3,8);
    cout <<"2 - Salario";
    gotoxy(3,10);
    cout <<"3 - Alterar outro funcionario";
    gotoxy(3,12);
    cout << "4 - Voltar ao menu";
    gotoxy(3,15);
    cout <<"Opcao: ";
    cin >> op;
    if(op==1){
      clrscr();
      molde();
      gotoxy(4,3);
      cout << "Numero de matricula: " << grupo[i].nmat;
      gotoxy(4,4);
      cout << "Nome: "<< grupo[i].nome;
      gotoxy(4,5);
      cout << "Salario: " << grupo[i].salario;
      gotoxy(4,10);
      cout << "Nome: " << grupo[i].nome;
      LE(1, 40, 10, 10, grupo[i].nome);
      gotoxy(22,23);
      cout << "Dados alterados com sucesso";
      getch();
    }
    if(op==2){
      clrscr();
      molde();
      gotoxy(4,3);
      cout << "Numero de matricula: " << grupo[i].nmat;
      gotoxy(4,4);
      cout << "Nome: "<< grupo[i].nome;
      gotoxy(4,5);
      cout << "Salario: " << grupo[i].salario;
      gotoxy(4,10);
      cout << "Salario: " ;
      gotoxy(13,10);
      cout << grupo[i].salario;
      LE(4, 10, 13, 10, grupo[i].salario);
      gotoxy(22,23);
      cout << "Dados alterados com sucesso";
      getch();
    }
    if(op==3){
      clrscr();
      altera();
    }
    if(op==4) {
      return (op);
    }
   if ((op<1) || (op>4)) {
      gotoxy(4,23);
      cout << "Opcao Invalida";
      gotoxy(4,24);
      cout << "Tecle <enter> para voltar ao menu.";
      sound(275);
      delay(350);
      nosound();
      getch();

   }
  }
 }


// --------------- Programa Principal
int main() {
  abrir();
  int op=0;
  int i,j;
  while (op!=7) {
    op=menu();
    switch (op) {
      case 1: inclui(); break;
      case 2: exclui(); break;
      case 3: consulta(); break;
      case 4: lista(); break;
      case 5: altera(); break;
      case 6: clrscr(); salvar(); exit(0);
      default : printf("Bug!\n");
		exit(1); // Encerra programa com codigo erro.
    }
  }
  getch();
  return 0;
}