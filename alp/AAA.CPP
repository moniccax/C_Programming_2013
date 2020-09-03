#include <constream.h>

const int max=5;
const int nulo=-1;

struct nodo{
  int n;
  int prox;
  char teste;
};

nodo lista[max];
int prim, livre;

void create(){
  prim = nulo;
  livre = 0;
  for (int i = 0; i<max; i++){
    lista[i].n = 0;
    lista[i].prox = i+1;
    lista[i].teste = 's';
  }
  lista[max-1].prox=nulo;
}


int inclui(){
  int n, p;
  if (livre==nulo){
    cout << "NO SPACE";
    getch();
    return 0;
  }
  cout << "Inteiro: ";
  cin >> n;
  p = lista[livre].prox;
  lista[livre].n = n;
  lista[livre].teste = 'c';
  lista[livre].prox = prim;

  prim=livre;
  livre=p;
  return 1;

}

int exclui(){
  int pex, panter, n; //pex=nodo a exlcuir ** panter=nodo anterior ao excluir
  cout << "\n\nDigite o elemento=";
  cin >> n;
  pex=prim; // comeca do inicio da lista
  while((lista[pex].n!=n) && (lista[pex].prox!=nulo)){
    panter = pex;
    pex = lista[pex].prox;
  }
  if(lista[pex].n == n){
    if (lista[pex].teste == 'c'){

      if(pex == prim)
	prim=lista[pex].prox;
      else
	lista[panter].prox=lista[pex].prox;

      lista[pex].prox=livre;
      livre=pex;
      lista[pex].teste = 's';
      cout << "\nElemento retirado: " << n;
      return 1;
    }
    else {
     cout << "Nao existe esse elemento";
     return 0;
    }
  }
}

int main(){
  int op;
  create();
  while(1){
    cout << "\nOP: ";
    cin >> op;
    switch(op){
      case 1:
	inclui(); break;
      case 2:
	exclui(); break;
      default: break;
    }
  }
  getch();
  return 0;
}