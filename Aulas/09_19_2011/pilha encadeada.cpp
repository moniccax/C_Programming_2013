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
  prim->ant=null;  
  ult->ant=null;
  ult->prox=null;
  
  while(resp!=5){
    system("cls");
    cout <<" \n \t Pilha encadeada";
    cout <<" \n 1- Incluir";
    cout <<" \n 2- Excluir";
    cout <<" \n 5- Sair";
    cout <<" \n \n Pilha: ";
    nodo* mostra=new nodo;
    mostra=prim;
    while(mostra->prox!=null){
       cout <<"\n \n "<< mostra->prox->n;
       mostra=mostra->prox;
    }
    cin>> resp;
    if(resp==1){
      system("cls");
      nodo* i=new nodo;
      cout <<" \n Digite um numero inteiro: ";
      cin >> i->n;
      if(prim->prox==null){
        prim->prox=i;
        ult->ant=i;
        i->prox=null;
        i->ant=null;
      }
      else{
        i->ant=p;
        p->prox=i;
        ult->ant=i;
        i->prox=null;
      }
      p=i;
    }
    if(resp==2){
      if(prim->prox!=null){
        nodo* ex=new nodo;
        ex=ult->ant;
        if(prim->prox==ex){
          prim->prox=null;
          ult->ant=null;
        }
        else{
          ex->ant->prox=null;
          ult->ant=ex->ant;
          p=ex->ant;
        }
        delete &(*ex);    
      }
      else{
        cout << " \n Nao ha elemento para ser excluido.";
        getch();
      }
    }
  }
}
