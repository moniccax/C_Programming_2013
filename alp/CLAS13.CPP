#include <constream.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

class Vetor{
  private:
    int x, y;

  public:
    Vetor (int x0=0, int y0=0) : x(x0), y(y0) {}

    void Armazena(int a, int b){
      x=a;
      y=b;
    }

    void Print(){
      cout << "( " << x << " + " << y << "i )" << endl;
    }

    Vetor operator -(Vetor& u) const { // ----- Sobrecarga operador subtracao
      Vetor aux;
      aux.x=x-u.x;
      aux.y=y-u.y;
      return aux;
    }

    Vetor operator +(Vetor& u) const { // ----- Sobrecarga operador multiplicação
      Vetor aux;
      aux.x=x+u.x;
      aux.y=y+u.y;
      return aux;
    }
};

void main(){
  clrscr();
  Vetor q(3,4), w, s;
  w.Armazena(5,6);
  cout << "W= ";
  w.Print();
  cout << "Q= ";
  q.Print();
  cout << "W+Q= ";
  s=w+q;
  s.Print();
  cout << "W-Q= ";
  s=w-q;
  s.Print();
  getch();
}