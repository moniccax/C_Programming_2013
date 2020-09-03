#include <constream.h>


void main(){
  int y=2;
  int *x;
  x=&y;
  *x=5;
  cout << y;
  getch();
}