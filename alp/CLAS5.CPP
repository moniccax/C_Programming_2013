#include <constream.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

class Circulo{
  private:
    float area, distancia, comprimento, raio;
  public:
  void RecebeRaio(float r);
  void AumentaRaio(float porcen);
  void Print();
};

void Circulo :: RecebeRaio(float r){
  raio=r;
  area=pow(r,2)*6.28;
  distancia=0;
  comprimento=2*3.14*r;
}

void Circulo :: AumentaRaio(float porcen){
  float aumento;
  aumento=raio*(1.0+(porcen/100));
  cout<<"\n\tO percentual de aumento foi "<<porcen;
  cout<<"\n\tO raio aumentou "<<aumento;

}

void Circulo :: Print(){
  cout<<"\n\tO valor do raio do circulo e: "<<raio;
  cout<<"\n\tA area do circulo e: "<<area;
}

void main(){
  clrscr();
  Circulo x;
  x.RecebeRaio(10);
  x.AumentaRaio(10);
  x.Print();
  getch();
}