#include <constream.h>
#include <math.h>

void main(){
  clrscr();
  float num, exp=25.0, den=1.0, sinal=1.0, s;
  cout << "Digite o valor de x: ";
  cin >> num;
  for (den=1.0; den<=25.0; den++){
    s+=sinal*((pow(num, exp))/den);
    sinal*=(-1.0);
    exp--;
    cout << "\t" << s;
  }
  cout << "\n\n\n" << s;

  getch();
}