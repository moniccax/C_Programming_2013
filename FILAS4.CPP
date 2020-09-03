/*******************************
* Autor: Felippe Miranda Ribas *
* Data: 14/12/2012             *
* Fila simples sobre um vetor  *
*  est[atico                   *
*******************************/
#include <constream.h>
#include <stdio.h>
#include <process.h> // exit()

const int max=5;
int head=0, // head pre-incrementado
    tail=0; // tail pos-incrementado

int fila[max];

int menu(void){
  int resp=0;
  while ((resp<1) || (resp>5)){
    cout << "\t\tFila simples sobre um vetor estatico " << endl;
    cout << "  1 - Enfilerar" << endl;
    cout << "  2 - Desenfileirar" << endl;
    cout << "  3 - Mostrar" << endl;
    cout << "  4 - Limpar" << endl;
    cout << "  5 - Sair" << endl;
    cin >> resp;
    if ((resp<1) || (resp>5)){
      cout << "Opcao invalida!";
    }
  }
  return resp;
}

void enfileira(void){
  int n;

  if (tail<max){
    cout << "Digite um elemento para ser enfileirado ";
    cin >> n;
    fila[tail]=n;
    tail++;
  } // if
  else {
    cout << "Nao ha espaco para enfilerar um elemento ";
    getch();
  } // else do if
} // efileira()

void desenfileira(void){
  int n;
  char ch;
  if (head<=tail){
    n=fila[head];
    cout << "O elemento retirado foi; " << n << endl;
    cout << "Digite <enter> para sair \n" << endl;
    ch=getch();
    while (ch!=13)
      ch=getch();
    head++;
  }
  else {
    cout << "Nao ha elemento a ser retirado ";
    getch();
  }
}

void mostrafila(void){
  int i;
  cout << "Head: " << head << endl;
  cout << "Tail: " << tail << endl;
  for (i=0; i<max; i++){
    cout << "fila[" << i << "] = " << fila[i] << endl;
    getch();
  }
}

void limpafila(void){
  int i;
  head=-1;
  tail=0;
  for (i=0; i<max; i++)
    fila[i]=0;
}


int main(){
  int i, head, tail;
  int fila[5];

  int op=0;
  while (op!=5){
    clrscr();
    op=menu();
  //  cout << "Digite: " << endl;
  //  cin >> op;
    switch (op){
      case 1: enfileira(); break;
      case 2: desenfileira(); break;
      case 3: mostrafila(); break;
      case 4: limpafila(); break;
      case 5: clrscr();
	      exit(0);
      default: printf ("Bug!\n");
	       exit(1);
    }
  }
  getch();
  return 0;
}