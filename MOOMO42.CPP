#include <constream.h>
#include <math.h>

void main(){
  clrscr();
  float x1=1.0, x2=1.0, y1=1.0, y2=1.0, d=0.0;
  while ((x1!=0)&&(x2!=0)&&(y1!=0)&&(y2!=0)){
    cout<<"\tDigite as coordenadas x e y do primeiro ponto: "<<endl;
    cin>>x1>>y1;
    cout<<"\t\nDigite as coordenadas x e y do segundo ponto: "<<endl;
    cin>>x2>>y2;
    d=(x2-x1)+(y2-y1);
    cout<<"\t\nA distancia do par de ponto lido e': "<<d<<endl;
  }//end while 
  getch();
}