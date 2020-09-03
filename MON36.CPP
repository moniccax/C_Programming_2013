#include <constream.h>

void main(){
  clrscr();
  float s, num, fat=1;
  int cont=0;
  for (num=63.0; num>0; num-=2){
    cont++;
    s+=num/fat;
    fat=fat*cont;
  }
  cout<<setprecision(7)<<s<<endl;
  cout<<cont<<endl;


  getch();
}