#include <iostream.h>
#include <conio.h>
#include <constream.h>
#include <math.h>

int main(){
  float a, b, c, delta;
  clrscr();
  cout << "Escreva as variaveis de uma equacao do segundo grau";
  cin >> a >> b >> c;

  delta=pow(b,2)-4*a*c;

  cout << "O valor descriminante da equacao e=" << delta << endl;

  if (delta==0)
  cout << "Suas raizes sao reais e identicas";

  else if (delta>0) {
  cout << "Suas raizes sao reais";
  }

  else if (delta<0) {
  cout << "Nao ha raizes";
  }

  getch();
  return 0;

}