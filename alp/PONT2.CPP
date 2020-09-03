#include <constream.h>

int total(int *a, int *b, int *tot){
  *tot=(*a)+(*b);
  return *tot;
}

void main(){
  clrscr();
  int *a, *b, *tot;
  cout << "Digite o valor de a: " << endl;
  cin >> *a;
  cout << "Digite o valor de b: " << endl;
  cin >> *b;
  cout << total(a, b, tot);
  //cout << "O total e: " << *tot;
  getch();
}