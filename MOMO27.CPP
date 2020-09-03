#include <constream.h>
#include <math.h>

void main(void){
  clrscr();
  float s=0.0, total=0.0, num=1.0, sinal=1.0;

  for (num=1.0; num<=10.0; num++){
    s=num/(pow(num,2));
    total+=s*(sinal);
    sinal=sinal*(-1.0);
    cout << "\t" << sinal;
  }//end of for

  cout << "\n\n\n" << total;
  getch();
}
