#include <constream.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

class Elevador{
  private:
    int andares, capacidade;
  public:
    int qnt_p, andar_a;
    int getAndares();
    void setAndares(int a);
    int getCapacidade();
    void setCapacidade(int c);
    void inicializa(int c, int a);
    void entra();
    void sai();
    void sobe();
    void desce();
};

int Elevador :: getAndares(){
  return andares;
}

void Elevador :: setAndares(int a){
  andares=a;
}

int Elevador :: getCapacidade(){
  return capacidade;
}

void Elevador :: setCapacidade(int c){
  capacidade=c;
}

void Elevador :: inicializa(int c, int a){
  capacidade=c;
  andares=a;
  qnt_p=0;
  andar_a=0;
}

void Elevador :: entra(){
  if (capacidade<qnt_p)
    qnt_p++;
}

void Elevador :: sai(){
  if (capacidade>qnt_p)
    qnt_p--;
}

void Elevador :: sobe(){
  if (andar_a<andares)
    andar_a++;
}

void Elevador :: desce(){
  if (andar_a>0)
    andar_a--;
}

int main(){
  clrscr();
  Elevador x;
  x.inicializa(2,10);
  x.entra();
  x.sai();
  x.sobe();
  x.desce();
  getch();
  return 0;
}