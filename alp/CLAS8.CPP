#include <constream.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

class automovel {
  private:
    float gasolina, distancia, resto;
  public:
    float combustivel;
    void abastecer (float combust);
    void percorreu ();
    void restou(float dist);
};

void automovel :: abastecer (float combust){
  combustivel=0;
  resto=0;
  distancia=0;
  if (combust>50)
    combustivel=50;
  else
    combustivel=combust;
}

void automovel :: percorreu (){
  distancia=0;
  distancia=combustivel*15.0;
  cout<<"\n\n\tA distancia percorrida foi: "<<distancia;
}

void automovel :: restou(float dist){
  resto=(dist/15);
  cout<<"\n\tSobrou a seguinte qtd de combustivel: "<<resto;
}

void main(){
  clrscr();
  automovel x, y;
  x.abastecer(70);
  x.percorreu();
  x.restou(200);

  y.abastecer(20);
  y.percorreu();
  y.restou(400);
  getch();
}