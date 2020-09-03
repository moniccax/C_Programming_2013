#include <constream.h>
#include <process.h>

const int max=5;
int head=max, //pre decrementado
    tail=4; //pos decrementado
int fila[max];

int menu(){
  int resp=0;
  while((resp<1)||(resp>5)){
    cout << "\t\tFila pos-decrementada";
    cout << "\n1 - Enfileirar";
    cout << "\n2 - Desenfileirar";
    cout << "\n3 - Mostrar fila";
    cout << "\n4 - Limpar fila";
    cout << "\n5 - Sair";
    cin >> resp;
  }
 return resp;
}

void enfileira(){
  int n;
  while (tail>-1){
    cout << "\n\t Digite o que deseja enfileirar:";
    cin >> n;
    fila[tail]=n;
    tail--;
  }
}

void desenfileira(){
  int n;
  if (head>tail){
     head--;
     n=fila[head];
  }
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