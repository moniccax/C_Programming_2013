#include <constream.h>
#include <process.h>

const int max=5;
int head=max, //pre decrementado
    tail=max-1; //pos decrementado
int fila[max];

int menu(){
  int resp=0;
  while((resp<1)||(resp>5)){
    cout << "\t\tFila circula pre e pos-decrementada";
    cout << "\n1 - Enfileirar";
    cout << "\n2 - Desenfileirar";
    cout << "\n3 - Mostrar fila";
    cout << "\n4 - Limpar fila";
    cout << "\n5 - Sair";
    cin >> resp;
  }
  clrscr();
 return resp;
}

void enfileira(){
  int n;
  if ((head==max)&&(tail==0))
   cout << "Nao ha espaco";
  if (tail==head){
    cout << "Nao ha espaco";
  }
  else {
    cout << "\n\t Digite o que deseja enfileirar:";
    cin >> n;
    fila[tail]=n;
    tail--;
    if (tail==0){
      tail=max-1;
    }
  }
}

void desenfileira(){
  int n;
  if(head==max)
    head=max-1;
  if(tail==head)
    cout << "\nSem elementos para desenfileirar";
  else {
    n=fila[head];
    head--;
  }
  cout << "\nElemento retirado = "<<n;
  getch();
}

void mostrafila(){
  cout << "\nHead = " << head;
  cout << "\nTail = " << tail;
  for (int i=0; i<max; i++){
    cout << "\n\tFila[" << i<<"] = " << fila[i];
  }
  getch();
}

void limpafila(){
  for (int i=0; i<max; i++){
    fila[i]=0;
  }
}

void main(){
  int op;
  while(op!=5){
    op=menu();
    switch(op){
       case 1: enfileira(); break;
       case 2: desenfileira(); break;
       case 3: mostrafila(); break;
       case 4: limpafila(); break;
       case 5: exit(0); break;
    }
  }//while
  getch();
}