#include <constream.h>

void troca(float& n, float& m);   //prototipo
int main(){
  float n1, n2, n3;
  cout<<"Digite tres numeros: ";
  cin >> n1 >> n2 >> n3;
  if(n1>n3) troca(n1,n2);
  if(n1>n3) troca(n1,n3);
  if(n2>n3) troca(n2,n3);
  cout << "n1=" <<n1<< "\t"<< "n2="<<n2 << "\t" << "n3="<<n3<<endl;
  getch();
  return 0;
}

void troca(float& n, float& m){
  float qlqrcoisa=n;
  n=m;
  m=qlqrcoisa;
}