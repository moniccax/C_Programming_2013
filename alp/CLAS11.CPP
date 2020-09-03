#include <constream.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

typedef struct carro {
  int ano;
  float motor;
  char marca[30];
  char modelo[40];
  char cor[20];
  float preco;
};

class automovel{
  private:
    carro vet[100];
    int pos;
  public:
    clrscr();
    automovel(int pos0=0) : pos(pos0){} //construtor

    void valordepos(){
    for (int i=0; i<100; i++){
      vet[i].ano=0;
      vet[i].motor=0;
      strcpy(vet[i].marca, "");
      strcpy(vet[i].modelo, "");
      strcpy(vet[i].cor, "");
      vet[i].preco=0;
    }//end for
    }

    void armazena(int n, float m, char ma[10], char mo[10], char c[10], float p){
      vet[pos].ano=n;
      vet[pos].motor=m;
      strcpy(vet[pos].marca, ma);
      strcpy(vet[pos].modelo, mo);
      strcpy(vet[pos].cor, c);
      vet[pos].preco=p;
      pos++;
    }

    void varre(){
      int i=0;
      while(i<3){
	if ((strcmp(vet[i].cor, "Amarelo") == NULL) && (vet[i].preco>=20000.00))
	  cout<< "\n\tO carro da posicao " << i << " e' amarelo e custa mais de R$20000.00";
	i++;
      }//end while
    }
};

void main(){
  clrscr();
  int um;
  float dois, seis;
  char tres[255], quatro[255], cinco[255];
  automovel x;
  x.valordepos();
  for (int i=0; i<=1; i++){
    cout<<"\n\tDigite o ano e o motor: ";
    cin>>um>>dois;
    cout<<"\n\tDigite a marca: ";
    cin>>tres;
    cout<<"\n\tDigite o modelo: ";
    cin>>quatro;
    cout<<"\n\tDigite a cor: ";
    cin>>cinco;
    cout<<"\n\tDigite o preco: ";
    cin>>seis;
    x.armazena(um, dois, tres, quatro, cinco, seis);
    clrscr();
  }//end for
  x.varre();
  getch();
}
