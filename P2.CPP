#include <constream.h>
#include <stdio.h>
#include <process.h> // exit()

const int max=5;
int topo=max; // pre decrementado
int pilha[max];

int menu(void){
  int resp=0;
  while ((resp<1) || (resp>5)){
    cout << " Pilha simples pre decrementada" << endl;
    cout << "  1 - Empilheirar" << endl;
    cout << "  2 - Desempilheirar" << endl;
    cout << "  3 - Mostrar" << endl;
    cout << "  4 - Limpar" << endl;
    cout << "  5 - Sair" << endl;
    cin >> resp;
    if ((resp<1) || (resp>5)){
      cout << "Opcao invalida!";
    } //if
  } //while
  clrscr();
  return resp;
}

void empilhar(){
  int n;
  cout << "\nDigite valor que deseja empilhar:" << endl;
  cin >> n;
  if (topo>0){
    pilha[topo]=n;
    topo--;
  }  //if
  else
    cout << "\n\nPILHA CHEIA";
}

void desempilhar(){
  int n;
  if (topo<0){
    n=pilha[topo];
    topo++;
  }  //if
  cout << n ;
}

void mostrarpilha(){
  cout << "\nTopo:" << topo;
  for(int i=0; i<max; i++)
    cout <<"\nPilha["<<i<<"] = " << pilha[i];
}

void limparpilha(){
  for(int i=0; i<max; i++)
    pilha[i]=0;
}

void main(){
  int op=0;
  while(op!=5){
    op = menu();
    switch(op){
      case 1: empilhar(); break;
      case 2: desempilhar(); break;
      case 3: mostrarpilha(); break;
      case 4: limparpilha(); break;
      case 5: ; break;
    } //switch
  }//while
}