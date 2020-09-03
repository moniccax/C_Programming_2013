#include <constream.h>
#include <process.h>
#include <stdio.h>

const int max = 5;
int* topo = new int; //pos incrementada
int* pilha =  new int[max];

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

void inicializa(){
  (*topo)=0;
  if((topo==NULL)||(pilha==NULL)){
    cout << "Memoria insuficiente";
    getch();
    exit(0);
  }
}

void empilha(){
  int n;
  if((*topo)<max){
    cout << "Elemento que deseja empilhar: ";
    cin >> n;
    (*pilha)[topo]=n;
    (*topo)++;
  }
  else
    cout << "Pilha cheia";
  getch();
}

void desempilha(){
  int n;
  if((*topo)>-1){
    n=(*pilha)[topo];
    topo--;
    cout << "\nElemento desenfileirado: " << n;
  }
  else
    cout << "\nSem elementos para desenfileirar";
  getch();
}

void mostrapilha(){
  cout << "Topo = " << (*topo);
  for (int i=0; i<max; i++)
    cout << "Pilha[" << i << "] = " << (*pilha)[topo];
  getch();
}

void limpapilha(){
  for (int i=0; i<max; i++)
    pilha[i]=0;
}

void deleta(){
  delete topo;
  delete pilha;
}

void main(){
  inicializa();
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
  deleta();
  getch();
}