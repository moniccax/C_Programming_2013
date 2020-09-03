#include <constream.h>
#include <process.h>
#include <stdio.h>

const int max=5;
int topo=4, pilha[max];

int menu(){
  int resp=0;
  while ((resp<1) || (resp>5)){
    cout << "\t\t\t\t Pilha decrementada";
    cout << "\n\n\t 1 - Empilhar";
    cout << "\n\t 2 - Desempilhar";
    cout << "\n\t 3 - Mostrar";
    cout << "\n\t 4 - Limpar";
    cout << "\n\t 5 - Sair" << endl;
    cin >> resp;
  }
    if((resp<1) || (resp>5)) {
      cout << "Opcao invalida";
     getch();
  }//if
  return resp;
}

void empilhar(){
  int n;
  if (topo>-1){
    cout << "\nDigite o valor:";
    cin >> n;
    pilha[topo]=n;
    topo--;
  }
  else
    cout << "\nPilha cheia";
  getch();
}

void desempilhar(){
  int n;
  if (topo<max){
    n=pilha[topo];
    cout << "Elemento desempilhado: " << n;
    topo++;
  }
  else
    cout << "Sem elementos para desempilhar";
  getch();
}

void mostrarpilha(){
  cout << "\nTopo : " << topo;
  for(int i=0; i<max; i++)
    cout << "\nPilha[" << i << "] = " << pilha[i];
  getch();
}

void limparpilha(){
  for(int i=0; i<max; i++)
    pilha[i]=0;
}

void main(){
  int op;
  while(op!=5){
    op=menu();
    switch(op){
       case 1: empilhar(); break;
       case 2: desempilhar(); break;
       case 3: mostrarpilha(); break;
       case 4: limparpilha(); break;
       case 5: exit(0); break;
    }
  }//while
  getch();
}