#include <constream.h>
#include <process.h>

const int max=5;
int* head=new int;
int* tail=new int;
int* fila=new[max];

int menu(){
  int resp=0;
  while((resp<1)||(resp>5)){
    cout << "\t\t Fila circular pre e pos-incrementada";
    cout << "\n1 - Enfileirar";
    cout << "\n2 - Desenfileirar";
    cout << "\n3 - Mostrar fila";
    cout << "\n4 - Limpar fila";
    cout << "\n5 - Sair";
    cin >> resp;
  }

 return resp;
}

void criafila(){
  (*head)=max;
  (*tail)=0;
  if((head==NULL)||(tail==NULL)||(fila==NULL)){
    cout << "MEMORIA CHEIA";
    exit(1);
  }
}

void enfileirar(){
  int n;
 if ((*tail)+1==(*head))
    cout << "Fila cheia";
  else {
   cout << "Digite valor:";
   cin >> n;
   (*fila)[tail]=n;
   (*tail)++;
   if ((*tail)==max){
     (*tail)=0;
   } //if
  } //else
}

void desenfileira(){
  int n;
  if((*head)==max)
    (*head)=0;
  if((*head)==(*tail)){
    cout << "Sem elementos para desenfileirar";
    getch();
  }
  else{
    n=(fila)[*head];
    (*head)++;
    cout << "Elemento retirado=" <<n;
    getch();
  }
}

void mostrafila(){
  cout << "head=" << (*head);
  cout << "\ntail=" << (*tail);
  for(int i=0; i<max; i++)
    cout << "\nfila[" << i << "] = " << (fila)[i];
  getch();
}

void limpafila(){
  for(int i=0; i<max; i++)
    fila[i]=0;
}

void deletarfila(){
  delete head;
  delete tail;
  delete fila;
}

void main(){
  criafila();
  int op;
  while(op!=5){
    op=menu();
    switch(op){
       case 1: enfileirar(); break;
       case 2: desenfileira(); break;
       case 3: mostrafila(); break;
       case 4: limpafila(); break;
       case 5: exit(0); break;
    }
  }//while
  deletarfila();
  getch();
}