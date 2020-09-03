#include <constream.h>
#include <math.h>

void main(){
  float x2, x1, y1, y2, d;
  clrscr();
  while ((x1!=0.0)&&(x2!=0.0)&&(y1!=0.0)&&(y2!=0.0)){
    cout<<"Digite as coordenadas x1 e y1:"<<endl;
    cin>>x1>>y1;
    cout<<"Digite as coordenadas y1 e y2:"<<endl;
    cin>>x2>>y2;
    d=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
    cout<<"A distancia e':"<<d<<endl;
  }
  getch();
}