#include <iostream>
#include <conio.h>

using namespace std;
struct nodo{
  int n;
  struct nodo* prox;
  struct nodo* ant;
};
nodo* prim=new nodo;
nodo* ult=new nodo;
nodo* null=new nodo;
nodo* p=new nodo;

int main(){
  int resp;
  prim->prox=null;
  ult->ant=null;
  while(resp!=5){
    system("cls");
    nodo* mostra=new nodo;
    mostra=prim;
    cout <<" \n \t Fila encadeada";
    cout <<" \n 1- Incluir";
    cout <<" \n 2- Excluir";
    cout <<" \n 5- Sair";
    cout <<" \n \n Fila: ";
    while(mostra->prox!=null){
       cout <<"\n \n "<< mostra->prox->n;
       mostra=mostra->prox;
    }
    cin>> resp;
    if(resp==1){
      system("cls");
      nodo* i=new nodo;
      cout<< "\n Digite um numero inteiro: ";
      cin >> i->n;
      if(prim->prox==null){
        prim->prox=i;
        ult->ant=i;
        i->prox=null;
        i->ant=null;
      }
      else{
        p->prox=i;
        i->ant=p;
        i->prox=null;
        ult->ant=i;
      }
      p=i;
    }
    if(resp==2){
      nodo* ex=new nodo;
      ex=prim->prox;
      if(ult->ant==ex){
        ult->ant=null;
        prim->prox=null;
      }
      else{
        prim->prox=ex->prox;
        ex->prox->ant=null;
      }
      delete ex;
    }
  }
}
      
      
      
