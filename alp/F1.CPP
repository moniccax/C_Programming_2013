#include <constream.h>
#include <stdio.h>
#include <process.h>

const int max=5;
int head=-1, // head pre incrementado
    tail=-1, // tail pre incrementado
    fila[max];

int menu(){
  int resp=0;
  while ((resp<1) || (resp>5)){
    cout << "\t\t\t\t Fila simples ";
    cout << "\n\n\t 1 - Enfileirar";
    cout << "\n\t 2 - Desenfileirar";
    cout << "\n\t 3 - Mostrar";
    cout << "\n\t 4 - Limpar";
    cout << "\n\t 5 - Sair" << endl;
    cin >> resp;
    if((resp<1) || (resp>5))
      cout << "Opcao invalida";
    getch();
  }
  return resp;
}

void enfileira(){
  int n;
  cout << "\n\nDigite o valor a ser inserido: ";
  cin >> n;
  tail++;
  if (tail<max)
    fila[tail]=n;
  else {
    tail--;
    cout << "\nNao ha espaco para enfileirar";
    getch();
  }
  clrscr();
}

void desenfileira(){
  int n;
  head++;
  if (head<=tail){
    n=fila[head];
    cout << "\nElemento retirado foi: " <<  n;
  }
  else {
    head--;
    cout << "\nNao ha elemento para ser retirado";
  }
  getch();
}

void mostrafila(){
 cout << "\nHead= "<< head <<"\tTail= " << tail;
 for (int i=0; i<max; i++){
    cout << "\nFila[" << i << "]= " << fila[i];
    getch();
 }
}

void limpafila(){
  head=-1;
  tail=-1;
  for(int i=0; i<max; i++){
    fila[i]=0;
  }
}

void main(){
  int op=0;
  while(op!=5){

  op=menu();

    switch(op){
      case 1: enfileira(); break;
      case 2: desenfileira(); break;
      case 3: mostrafila(); break;
      case 4: limpafila(); break;
      case 5: ;
	      exit(0);
      default: cout << "Bug";
	       exit(1);
    } //switch

  } //while
  getch();
} //main