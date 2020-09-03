#include <iostream.h>
#include <conio.h>
#include <math.h>

void main(void) {

  clrscr ();
  float ang, seno, cosseno, rad;

  cout << "Escreva os caracteres do angulo";
  cin >> ang;

  rad=ang*3.141592/180;

  seno=sin(rad);
  cosseno=cos(rad);

  cout << "O seno do seu angulo e:" << seno << endl;
  cout << "O cosseno do seu angulo e:" << cosseno << endl;
  getch();

}