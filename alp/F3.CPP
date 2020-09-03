#include <constream.h>
#include <stdio.h>
#include <process.h>

const int max=5;
int head=0, // head pre incrementado
    tail=-1; // tail pos incrementado
int fila[max];

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
    if((resp<1) || (resp>5)) {
      cout << "Opcao invalida";
     getch();
  }//if
  return resp;
}
}

void enfileira(void){
  int n;
  tail++;
  if(tail<max){
    cout << "\nDigite o valor do numero a ser inserido: ";
    cin >> n;
    fila[tail]=n;
  }
  else {
    tail--;
    cout << "\nFila cheia!";
  } //else
  getch();
  clrscr();
} //enfileira

void desenfileira(){
  int n;
  if(head<tail){
    n=fila[head];
    cout << "\nElemento retirado: " << n;
    head++;
  } //if
  else {
    cout << "\nNao ha elemento para ser retirado";
    }  //else
  clrscr();
}//desenfileira

void mostrafila(){
  cout << "\nHead= " << head << "\tTail= " << tail;
  for (int i=0; i<max; i++){
    cout << "\nFila[" <<i<< "]= " << fila[i];
    getch();
  } //for
  clrscr();
} //mostrafila

void limpafila(){
  for (int i=0; i<max; i++)
    fila[i]=0;
} //limpafila

void main(){
  int chama=0;
  while(chama!=5){

    chama=menu();

    switch (chama){
      case 1: enfileira(); break;
      case 2: desenfileira(); break;
      case 3: mostrafila(); break;
      case 4: limpafila(); break;
      case 5: ; exit(0);
      default: printf("Bug!");
	      exit(1);
    }//switch
  getch();
  }//while
} //main