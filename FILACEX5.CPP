/***************************************
* Autor: Felippe Miranda Ribas         *
* Data: 14/12/2012                     *
* - Fila circular sobre um vetor       *
*   estatico                           *
***************************************/
#include <constream.h>
#include <stdio.h>
#include <process.h> // exit()

const int max=20;
int *head, *tail;
int * filac= new int [max];
*head=&filac[max];
*tail=filac;

int menu(void){
  int resp=0;
  while ((resp<1) || (resp>5)){
    cout << "\t\tFila circular sobre um vetor estatico " << endl;
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

  if (tail+1==head){
    cout << "Nao ha espaco " << endl;
  }
  else {
    cout << "Digite um elemento " << endl;
    cin >> n;
    fila[tail]=n;
    tail++;
    if (tail==max) // incremento circular tail
      tail=0;
  }
}

void desenfileira(void){
  int n;
  char ch;
  head++;
  if (head==max) // incremento circular de head
    head=0;
  if (head==tail){
    cout << "Nao ha elemento a ser retirado " << endl;
  }
  else {
    n=fila[head];
    head++;
    cout << "Elemento retirado: " << n << endl;
    cout << "Tecle <enter> para sair ";
    ch=getch();
    while (ch!=13)
      ch=getch();
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
  head=max;
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