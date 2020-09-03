#include <constream.h>
#include <process.h>
#include <stdio.h>

const int max=5;
int pilha[max];
int topo=-1;

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
  if(topo<max){
    cout << "\nDigite valor = " ;
    cin >> n;
    topo++;
    pilha[topo]=n;
  }
  else {
    cout << "\nPilha cheia";
    getch();
  }
}

void desempilha(){
  int n;
  if(topo>-1){
    n=pilha[topo];
    topo--;
    cout << "\nElemento desempilhado:" n;
    getch();
  }
  else
    cout << "\nSem elementos para desempilhar";
  getch();
}

void mostrapilha(){
  cout << topo;
  for(int i=0; i<max; i++)
    cout << "\nPilha["<<i<<"] = " << pilha[i];
  getch();
}

void limpapilha(){
  for(int i=0; i<max; i++)
    pilha [i]=0;
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