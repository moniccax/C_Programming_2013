#include <constream.h>
#include <process.h>

const int max=5;
int head=0;
int tail=0;
int fila[max];

int menu(){
  int resp=0;
  while((resp<1)||(resp>5)){
    cout << "\t\t Fila pos e pos-incrementada";
    cout << "\n1 - Enfileirar";
    cout << "\n2 - Desenfileirar";
    cout << "\n3 - Mostrar fila";
    cout << "\n4 - Limpar fila";
    cout << "\n5 - Sair";
    cin >> resp;
  }

 return resp;
}

void enfileirar(){
  int n;
  if (tail<max){
    cout << "\nDigite numero: " ;
    cin >> n;
    fila[tail]=n;
    tail++;
  }
  else {
    cout << "\nFila cheia";
    getch();
  }
}

void desenfileirar(){
  int n;
  if(head<tail){
    n=fila[head];
    head++;
    cout << n;
    getch();
  }
  else{
    cout << "Sem elementos para desenfileirar";
    getch();
  }
}

void mostrafila(){
  cout << "\nHead = " << head;
  cout << "\nTail = " << tail;
  for (int i=0; i<max; i++)
    cout << "\nFila[" << i << "] = " << fila[i];
  getch();
}

void limpafila(){
  head=0;
  tail=0;
  for(int i=0; i<max; i++)
    fila[i]=0;
}

void main(){
  int op;
  while(op!=5){
    op=menu();
    switch(op){
       case 1: enfileirar(); break;
       case 2: desenfileirar(); break;
       case 3: mostrafila(); break;
       case 4: limpafila(); break;
       case 5: exit(0); break;
    }
  }//while
  getch();
}