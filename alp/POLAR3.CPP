#include <constream.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

class vetor{
  private:
    float x, y;

  public:
  vetor(float x0=0, float y0=0) : x(x0), y(y0){};

  void igual(float w, float z){
    x=w;
    y=z;
  }

  void print() {
    cout << x;
    cout << "    " << y <<endl;
  }

  vetor operator + (vetor& m) {
    vetor temp;
    temp.x=x+m.x;
    temp.y=y-m.y;
    return temp;
  }

  vetor operator - (vetor& m) {
    vetor temp;
    temp.x=x-m.x;
    temp.y=y-m.y;
    return temp;
  }

  vetor operator * (vetor& m){
    vetor temp;
    temp.x=x*m.x;
    temp.y=y*m.y;
    return temp;
  }
};

int main(){
  clrscr();
  vetor a(3.0, 10.0), b, s;
  b.igual(2.0, 4.0);
  cout<< " A= ";
  a.print();
  cout<<" B= ";
  b.print();
  cout<<" S= ";
  s.print();
  s=a.operator+(b);   //s=a+b
  cout<<"\n\n A+B= ";
  s.print();
  s=a-b;
  cout<<"\n A-B= ";
  s.print();
  cout<<"\n A*B= ";
  s=a*b;
  s.print();
  getch();
  return 0;
}