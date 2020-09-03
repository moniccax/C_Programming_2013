#include <constream.h>
#include <stdlib.h>
#include <string.h>

int nomefun(char *i){
  strcpy(i, "Monica linda");
  return 0;
}

int main(){
  char c[40]="Ola";
  nomefun(c);
  cout  << c;
  getch();
  return 0;
}