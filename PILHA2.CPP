/***************************************
* Autor: Felippe Miranda Ribas         *
* Data: 14/12/2012                     *
* - Pilha simples sobre um vetor       *
*   estatico                           *
***************************************/

#include <constream.h>
#include <stdio.h>
#include <process.h> // exit()

const int max=5;
int topo=0, pilha[max]; // pos-incrementado
//topo=max+1;

int menu(void){
  int resp=0;
  while ((resp<1) || (resp>5)){
    cout << "\t\tPilha simples sobre um vetor estatico " << endl;
    cout << "  1 - Empilhar" << endl;
    cout << "  2 - Desempilhar" << endl;
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

void empilha(void){
  int n;

  if (topo<max){
    cout << "Digite um elemento para ser empilhado " << endl;
    cin >> n;
    pilha[topo]=n;
    topo++;
  } // if
  else {
    cout << "Nao ha espaco para enfilerar um elemento " << endl;
    getch();
  } // else do if
} // efileira()

int desempilha(void){
  int n;
  char ch;
  if (topo>0){
    topo--;
    n=pilha[topo];
    //cout << "O elemento retirado foi; " << n << endl;
    //cout << "Digite <enter> para sair \n" << endl;
    //ch=getch();
    //while (ch!=13)
    //  ch=getch();
  }
  else
    cout << "Nao ha elemento a ser retirado ";
  return n;
}

void mostrapilha(void){
  int i;
  cout << "Topo: " << topo << endl;
  for (i=0; i<max; i++){
    cout << "pilha[" << i << "] = " << pilha[i] << endl;
    getch();
  }
}

void limpapilha(void){
  int i;
  topo=0;
  for (i=0; i<max; i++)
    pilha[i]=0;
}


int main(){
  int x, i, topo;
  int pilha[5];

  int op=0;
  while (op!=5){
    clrscr();
    op=menu();
  //  cout << "Digite: " << endl;
  //  cin >> op;
    switch (op){
      case 1: empilha();
	      break;
      case 2: cout << "O elemento retirado foi: "<< desempilha() << endl;
	      getch();
	      break;
      case 3: mostrapilha(); break;
      case 4: limpapilha(); break;
      case 5: clrscr();
	      exit(0);
      default: printf ("Bug!\n");
	       exit(1);
    }
  }
  getch();
  return 0;
}