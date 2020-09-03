#include <constream.h>

void main(){
  clrscr();
  float  massai, massaf;
  int seg=0, min=0, hor=0;
  cout << "Digite a massa inicial: ";
  cin >> massai;
  massaf=massai;

  while (massaf>0.5){
    massaf=(massaf/2.0);
    seg+=50;
  }//end of while

  cout << "\n\tMassa inicial:  "<< massai;
  cout << "\n\tMassa final:  " <<  massaf;

  while (seg>60){
    min=seg/60;
    seg=min%60;
  }

  while (min>60) {
   hor=min/60;
   min=hor%60;
  }

  cout << "\nO tempo e'  " << hor << ":" << min << ":" << seg;
  getch();
}