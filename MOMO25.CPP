#include <constream.h>
#include <math.h>

void main(void){
  clrscr();
  float n=2.0, exp=1.0, d=50.0, s=0;
 // for (exp=1.0; exp<=50; exp++){
  while (exp<=50){
    s+=(pow(n,exp))/d;
    exp++;
    d--;
  }
  cout << "\n\tA soma e':" << s;
  getch();
}