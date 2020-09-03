#include <constream.h>
#include <process.h>

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

struct nodo{
  int n;
  int prox;
};

const int nulo = -1;
const int max = 5;

int *prim = new int;
int *livre = new int;

nodo *lista = new nodo [max];

void cria(){
  prim = &lista[nulo].n-1;
  livre = &lista[nulo].prox;
  for (int i=-1; i<max; i++){
    lista[i].n=0;
    lista[i].prox=i+1;
  }
  lista[max-1].prox=nulo;
}

int inclui(){
  int n, p;
  if ((*livre)==nulo){
    cout << "\nNao ha espaco";
    getch();
    return 0;
  }
  cout << "\n\nDigite o elemento: ";
  cin >> n;
  p = lista[*livre].prox;
  lista[*livre].n=n;
  lista[*livre].prox=*prim;
  *prim=*livre;
  *livre=p;
  return 1;
}

void exclui(){
  int n, p1, p2;
  cout << "Digite o elemento";
  cin >> n;
  p1=*prim;
  while ((lista[p1].n!=n)&&(lista[p1].prox!=nulo)){
    p2=p1;
    p1=lista[p1].prox;
  }
  if (lista[p1].n==n){

      if (lista[p1].prox==*livre){
    }

    lista[p2].prox=lista[p1].prox;
    lista[p1].prox=*livre;
    *livre=p1;
    cout << "\nElemento retirado da lista";
  }
  else {
    cout << "\nNao existe este elemento na lista";
    getch();
  }
}

int main(){
  *prim=nulo;
  *livre=0;
  cria();
  int op=0;
  while (op!=5){
    op=menu();
    switch(op){
      case 1: inclui(); break;
      case 2: exclui(); break;
      case 3: clrscr(); exit (0);
      case 4: clrscr(); exit (0);
    }
  }
  getch();
  delete [] lista;
  return 0;
}