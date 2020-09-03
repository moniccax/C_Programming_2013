#include <constream.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

class real{
   private:
     float x, y;
   public:
     real (float x0=0, float y0=0) : x(x0), y(y0) {} //construtor

     void armazena (float q, float w){
       x=q;
       y=w;
     }//end armazena

     void print () {
       cout << "( " << x << " + " << y << "i )" << endl;
     }

     real operator + ( real& k ) const { //sobrecarga soma
       real aux;  //variavel temporaria
       aux.x=x+k.x;
       aux.y=y+k.y;
       return aux;
     }

     real operator - ( real& k ) const { //sobrecarga
       real aux; //variavel temporaria
       aux.x=x-k.x;
       aux.y=y-k.y;
       return aux;
     }

     int operator == ( real& k ) {
       if ( (x==k.x) && (y==k.y))
	 return 1;
       else
	 return 0;
     }

     friend ostream& operator << ( ostream& stream, real& k ) {
       stream << k.x << " + y " << k.y;
       return stream;
     }

     friend istream& operator >> ( istream& stream, real& k ) {
       float x1, y1;
       stream >> x1 >> y1;
	 if (stream.good () ) {
	   k.x=x1;
	   k.y=y1;
	 }
       return stream;
     }
};

int main(){


  clrscr();
  real l(5.0, 3.0), m, s;
  clrscr();

  m.armazena(3.0, 5.0);
  m=(1.0, 2.0);

  cout << " L= ";
  l.print();

  cout << " M= ";
  m.print();

  cout << " S= ";
  s.print();

  s=l+m;
  cout << " L + M = ";
  s.print();

  s=l-m;
  cout << " L - M = ";
  s.print();

  cout << " M = " ;
  cin >> m;
  cout << " M = " ;
  m.print();

  if (l==m)
    cout << "L e' igual a M. ";

  getch();
  return 0;
}