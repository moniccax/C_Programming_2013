#include <constream.h>

void main(){
clrscr();
  int matriz[3][2][4]={
  { {1,2,3,4},
    {5,6,7,8}},

  { {7,9,3,2},
    {4,6,8,3}},

  { {7,2,6,3},
    {0,1,9,4}
  }};
  cout<<matriz[2][1][2];
  getch();
}