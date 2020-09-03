#include <constream.h>

void main (void){
  float f, celsius;
  clrscr();
  cout << "\n\t Farenheit";
  cout << "\t Celsius";
  for (f=50.0; f<=150.0; f++){
    celsius=(5.0/9.0)*(f-32.0);
    cout << "\n\t" << f;
    cout << "\t\t" << celsius;
  } //end of for
  getch();
}