#include <constream.h>
#include <math.h>

void main (void){
  float pa=9e7, pb=2e8, anos=0.0;
  clrscr();
  cout << "\n\t\tPopulacao de A: " << pa;
  cout << "\n\t\tPopulacao de B: " << pb;
  while (pa<=pb){
    pa*=1.03;
    pb*=1.015;
    anos++;
    }//while
    cout << "\n\tO numero de anos para ultrapassagem da populacao e':" <<anos;
    getch();
}