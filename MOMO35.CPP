#include <constream.h>
#include <math.h>

double fat(double n){
  double r;
  if ((n==1) || (n==0)){
    return 1;
  }
  else {
    r=(fat(n-1)*n);
    return r;
  }

}

int main(){
  clrscr();
  double num=100, s, den;
  double cont=0;
  for (cont=0; cont<=20; cont++){
    s+=num/den;
    den=fat(cont);
    num--;
    cout << "\t" << den;
  }
  cout<< "\n\n\n" << s;
  getch();
  return 0;
}