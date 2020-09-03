#include <constream.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

class Poligono{
  private:
    int x1, x2, x3, x4, y1, y2, y3, y4, raio;
  public:
    Poligono(){
      raio=0;
      x1=0;
      x2=0;
      x3=0;
      x4=0;
      y1=0;
      y2=0;
      y3=0;
      y4=0;
    }

    void Circulo(int x, int y, int r){
      x1=x;
      y1=y;
      raio=r;
    }

    void Triangulo(int x, int y, int xx, int yy, int xxx, int yyy){
      x1=x;
      y1=y;
      x2=xx;
      y2=yy;
      x3=xxx;
      y3=yyy;
    }

    void QuatroLados(int a, int b, int c, int d, int e, int f, int g, int h){
     x1=a;
     x2=c;
     x3=e;
     x4=g;
     y1=b;
     y2=d;
     y3=f;
     y4=h;
    }

    int Quadrado(Poligono& p){
      if((y3-y1==y4-y2)&&(x2-x1==x4-x3)&&(y4!=0)&&(y3!=0)&&(y2!=0)&&(x4!=0)&&(x2!=0)&&(x1!=0))
	return 1;
      else
	return 0;
    }
};

int main(){
  getch();
  return 0;
}