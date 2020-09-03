#include <constream.h>

void doisbeep(){
  cout << "a";
}

int main(){
  void (*p)();
  p=doisbeep;
  (*p)();
  getch();
  return 0;
}