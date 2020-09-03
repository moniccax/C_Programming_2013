#include <constream.h>
#include <process.h>

const int max = 5;
const int nulo = -1;

int prim = nulo, livre = 0;

struct nodo{
  int num;
  int prox;
};

nodo lista[max];

int menu(){
  int resp = 0;
  while ((resp<1) || (resp>5)){
     cout << "\t\t\t\nLista Encadeada";
     cout << "\n\n1 - Inclui";
     cout << "\n\n2 - Exclui";
     cout << "\n\n3 - Mostra";
     cout << "\n\n4 - Limpa";
     cout << "\n\n5 - Sai";
     cout << "\n\n\n Opcao: " ;
     cin >> resp;
     if((resp<1)||(resp>5)){
       cout << "Opcao Invalida!";
       getch();
     }
  }
  return resp;
}

void cria(){
  prim = -1; //lista vazia
  livre = 0;  //livre aponta 1a posicao do vetor ou o 1o nodo
  for(int i=0; i<max; i++){
    lista[i].num = 0;  //zera area de dados do nodo
    lista[i].prox = i+1;  //campo prox aponta proximo nodo
  }
  lista[max-1].prox=nulo; //ultimo nodo tem prox aterrado
}

void inclui(){
  int n, p;
  if(livre!=nulo){
    clrscr();
    cout << "\n\n\tInclui nodo";
    cout << "\n\n Digite o inteiro referente ao nodo: ";
    cin >> n;
    p = lista[livre].prox; //salva endereco proximo nodo livre
    lista[livre].num = n; //guarda elemento
    lista[livre].prox = prim;//novo nodo.prox aponta o antigo 1o da prim da lista
    prim = livre; //prim aponta o novo 1o nodo
    livre = p;  //livre atualizado p novo nodo livre
  }
  else
    cout << "\n\n\n\n\Nao existe nodos livres!";
  getch();
}

void exclui(){
  int n, p1, p2;
  clrscr();
  cout << "\n\n\tExclui nodo";
  cout << "\n\nDigite o elemento referente ao nodo a ser excluido";
  cin >> n;
  while((lista[p1].num != n)&&(lista[p1].num != nulo)){
    p2 = p1;
    p1 = lista[p1].prox;
  }
  if (lista[p1].num == n){
    if(p1 == prim)
      prim = lista[p1].prox;
    else
      lista[p2].prox = lista[p1].prox;
    lista[p1].prox = livre;
    livre = p1;
    cout << "\n\n\n Nodo Excluido.";
  }
  else {
    cout << "\n\n\n\tNao existe um nodo com este elemento!!";
    getch();
  }
}

void mostra(){
  int i;
  if (prim != nulo){
    i = prim;
    while (lista[i].prox != nulo){
      clrscr();
      cout << " \n\n\ntMostra lista";
      cout << "\n\nPrim = " << prim;
      cout << "\n\nLivre = " << livre;
      cout << "\n\nLista[" << i << "] = " << lista[i].num;
      getch();
      i = lista[i].prox;
    }
    if (lista[i].prox == nulo){
      clrscr();
      cout << " \n\n\ntMostra lista";
      cout << "\n\nPrim = " << prim;
      cout << "\n\nLivre = " << livre;
      cout << "\n\nLista[" << i << "] = " << lista[i].num;
      getch();
    }
  }
  else {
    clrscr();
    cout << "Lista vazia!";
    getch();
  }
}

void main(){
  cria();
  int op = 0;
  while (op!= 5){
    op = menu();
    switch(op) {
      case 1: inclui(); break;
      case 2: exclui(); break;
      case 3: mostra(); break;
      case 4: cria(); break;
      case 5: clrscr(); break;
    }
  }
  getch();
}