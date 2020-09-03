#include <constream.h>

void main(void){
  clrscr();
  float s;
  for(int i=1, j=1; i<=99, j<=50; i+=2, j++)
    s+=(float)i/(float)j;
  cout<<s;

   getch();
}

//void main(void){
//  clrscr();
//  float s=0.0, num=1.0, den=1.0;
//  for (den=1.0; den<=50; den++){
//    s+=num/den;
//    num+=2;
//    cout << "\t" << den;
//  }//---end of for
//  cout << "\n\n\n" << s;
//  getch();
//}