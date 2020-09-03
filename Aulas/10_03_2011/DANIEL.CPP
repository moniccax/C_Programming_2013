#include <constream.h>

void main(){
  clrscr();
  int v[5];
  int i=4, j=0, temp;
  v[0]=5;
  v[1]=4;
  v[2]=3;
  v[3]=2;
  v[4]=1;
  for(int c=0;c<5;c++){
  i=4;
  while(i!=0){
    if(v[i]>v[i-1])
      i--;
    else{
      temp=v[i];
      v[i]=v[i-1];
      v[i-1]=temp;
    }
  }
  }
  gotoxy(10,10);
  cout <<v[0]<<"="<<v[1]<<"="<<v[2]<<"="<<v[3]<<"="<<v[4];
  getch();
}







