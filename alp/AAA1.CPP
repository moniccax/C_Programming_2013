#include <constream.h>
#include <process.h>

//  lista simplesmente encadeada sobre vetor com
//  alocacao dinamica e ponteiros dinamicos com conteudo
//  de endereco

const int max=5;

struct nodo {
  int n;
  nodo* prox;
};

nodo* head;
nodo* tail;

void enfileira(){
  int n;
  nodo* p;
  p = new nodo;
  if(p!=NULL){
    cout << "\nElemento: ";
    cin >> n;
    if (tail==NULL){
      p->n=n;
      p->prox=NULL;
      head=p;
      tail=p;
    }
    if (tail==NULL){
      p->n=n;
      p->prox=NULL;
      head=p;
      tail=p;
    }
    else{
      p->n=n;
      p->prox=NULL;
      tail->prox=p;
      tail=p;
    }
  }
  else {
    cout << "\nNao ha espaco livre";
    getch();
  }
}

void desenfileira(){
  int n;
  nodo* p;
  if (head!=NULL){
    p=head;
    n=head->n;
    head=head->prox;
    delete p;
    if (head==NULL)
      tail=NULL;
    cout << "\n\nElemento retirado: " << n;
    getch();
  }
  else {
    cout << "Nao existe elemento para desenfileirar";
    getch();
  }
}

void limpafila(){
  nodo* p;
  while (head!=NULL){
    p=head;
    head=head->prox;
    delete p;
  }
  tail==NULL;
}

void inicializa(){
  head=NULL;
  tail=NULL;
}

int menu(){
  int resp=0;
  while ((resp<1)||(resp>4)) {
    cout << "\n\t1 - enfileira ";
    cout << "\n\t2 - desenfileira";
    cout << "\n\t3 - limpa";
    cout << "\n\t4 - sair";
    cin >> resp;
  }
  if ((resp<1)||(resp>5)){
    cout << "\nopcao invalida" ;
    getch();
  }
  return resp;
}

int main(){
  inicializa();
  int op=0;
  while (op!=5){
    op=menu();
    switch(op){
      case 1: enfileira(); break;
      case 2: desenfileira(); break;
      case 3: limpafila(); break;
      case 4: clrscr(); exit (0);
    }
  }
  getch();
  return 0;
}