#include <constream.h>
#include <stdio.h>
#include <stdlib.h>
#include <process.h>

const int max=5;
int topo=0; //pos incrementado
int pilha[max];

int menu(){
  int resp=0;
  while ((resp<1)||(resp>5)){
    cout << "\n\t\tPilha simples";
    cout << "\n 1 - Empilhar";
    cout << "\n 2 - Desempilhar";
    cout << "\n 3 - Mostrar pilha";
    cout << "\n 4 - Limpar pilha";
    cout << "\n 5 - Sair\n\n";
    cin >> resp;
  }

  return resp;
}

void empilha(){
  int n;
  cout << "\nNumero que deseja empilhar:";
  cin >> n;
  if (topo<max){
    pilha[topo]=n;
    topo++;
  }
  else
    cout << "Nao ha espaco na pilha";
  getch();
}

void desempilha(){
  int n;
  if (topo>0){
    n=pilha[topo];
    topo--;
  }
  else
    cout << "Fila vazia";
  getch();
}

void mostrapilha(){
  cout << "Topo= " << topo;
  for (int i=0; i<max; i++){
    cout << "\nPosicao " << i << " = " << pilha[i];
  }
  getch();
}

void limpapilha(){
  for (int i=0; i<max; i++){
    pilha[i]=0;
  }
  getch();
}

void main(){
  int op=0;
  while(op!=5){
    clrscr();
    op=menu();
    switch(op){
      case 1: empilha(); break;
      case 2: desempilha(); break;
      case 3: mostrapilha(); break;
      case 4: limpapilha(); break;
      case 5: clrscr();
	      exit(0);
      default: printf("Bug");
	       exit(1);

    }//switch
  }//while
  getch();
}