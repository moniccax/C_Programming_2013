#include <constream.h>

float result(){
  float cont, num=99.0, fat=1.0, serie=100.0;
  for (cont=1.0; cont<=20.0; cont++){
    serie+=num/fat;
    fat=fat*cont;
    cout<<"\tfat"<<fat;
    num--;
  }
  return serie;
}

float main(){
  clrscr();
  float s;
  s=result();
  cout<<"A serie e:"<<s<<endl;
  getch();
  return 0;
}