#include <constream.h>
#include <math.h>

float trian (float l);

int main(){
  clrscr();
  float lado, total;
  cout<<"Digite o lado de um triangulo equilatero";
  cin>>lado;

  total=trian(lado);

  cout << "A area do triangulo e'" << total <<endl;
  getch();
  return 0;
}
float trian (float l){
  float area;
  area=((pow(l,2.0))*1.7)/4.0;
  return area;
}