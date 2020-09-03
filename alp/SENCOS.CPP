#include <constream.h>
#include <conio.h>
#include <math.h>

void main (void){
 float ang, rad, cosseno, seno;

 clrscr ();
 cout << "Escreva o valor de um angulo";
 cin >> ang;

 rad=ang*3.141592/180.0;

 seno=sin(rad)         ;
 cosseno=cos(rad)       ;

 cout << "O seno e=" << seno << endl;
 cout << "O cosseno e=" << cosseno << endl;

 getch();


}
