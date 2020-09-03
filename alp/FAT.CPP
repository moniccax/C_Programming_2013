#include <constream.h>

void main(){
  int fat=1;
  clrscr();
  for (int i=5; i>=1; i--){
    fat=fat*i;
    cout << "\t" << fat;
  }
  getch();
}