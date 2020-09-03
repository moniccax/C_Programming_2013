#include <constream.h>

void main(void){
  float s;
  int num1=37, num2=38, den=1;
  clrscr();
  //for (den=1.0; den<=37.0, den=++)
  while (den<=37){
    s+=((float)num1*(float)num2)/(float)den;
    num1--;
    num2--;
    den++;
  }
  cout << "\n\tA soma e':" << s;
  getch();
}