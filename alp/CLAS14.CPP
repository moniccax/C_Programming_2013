#include <constream.h>
#include <stdlib.h>
#include <String.h>
#include <stdio.h>

class Vetor{
  private:
    float x, y;
  public:
    Vetor (float x0=0, float y0) : x(x0), y(y0){}

    Vetor Armazena (float x1, float y2) {
      x=x1;
      y=y2;
    }

    Vetor operator + (Vetor& k) const {
      Vetor temp;
      temp.x=x+k.x;
      temp.y=y+k.y;
      return temp;
    }

    Vetor operator - (Vetor& k) const {
      Vetor temp;
      temp.x=x-k.x;
      temp.y=y-k.y;
      return temp;
    }

    int operator == (Vetor& k){
      if ((x==k.x)&&(y==k.y))
	return 1;
      else
	return 0;
    }

    void get(){
      cout << "Digite o valor de x:" << endl;
      cin >> x;
      cout << "Digite o valor de y:" << endl;
      cin >> y;
    }

    void print(){
      cout << "( " << x << " + " << y << "i )" << endl;
    }
};

int main(){
  Vetor a(2.0,4.0), b, s;
  a.print();
  b.get();
  b.print();
  s=a+b;
  s.print();
  s=a-b;
  s.print();
  if(a==b)
    cout << "A 'e igual a B";
  getch();
  return 0;
}