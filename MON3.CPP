#include <constream.h>

void main(void){
  clrscr();
  float f, c;
  for (f=50.0; f<=150.0; f++) {
    c=(5.0/9.0)*(f-32.0);
    cout << "\n\tGraus Celsius, Graus Farenheit";
    cout << c << endl;
    cout << f << endl;
 }
    getch();
}
