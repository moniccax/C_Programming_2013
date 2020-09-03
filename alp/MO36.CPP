#include <constream.h>
#include <math.h> 

float calc(); //prototipo

int main(){
  clrscr();
  float serie;

  serie=calc(); //chamando a funcao

  cout<<"A serie equivale a: "<<setprecision(7)<<serie<<endl;

  getch();
  return 0;
}
  
float calc(){
  float s=0.0, fat=1.0, cont=0.0;
  for(float num=63.0; num>0.0; num-=2.0){
    cont++;
    s+=num/fat;
    fat=fat*cont;
  }
  cout<<"O numero de termos foi: "<<cont<<endl;
  return  s;
}