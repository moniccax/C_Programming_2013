#include <constream.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

typedef struct potencia{
  float potenc;
};

class ar{
  private:
    potencia pot[11];
    float x;
  public:
    ar();
    void temp(float tempi, float P);
   // void condicionador();
};

ar :: ar(){
 for (int i=0; i<=10; i++){
    pot[i].potenc=x;
    x+=1.8;
 }
}

/*void ar :: condicionador(){
  x=0;
  for (int i=0; i<=10; i++){
    pot[i].potenc=x;
    x+=1.8;
  }//end for
}*/

void ar :: temp(float tempi, float P){
  int resultante;
  resultante=tempi-(pot[P].potenc);
  cout<<"\nA temp e: "<<resultante;
}

void main(){
  clrscr();
  ar z, w;
  z.temp(25, 5);
// w.condicionador();
  w.temp(31, 10);
  getch();
}