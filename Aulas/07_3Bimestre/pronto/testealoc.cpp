#include <iostream>
#include <conio.h>

using namespace std;

int main(){
    int teste,i,teste2;
    cout <<"\n \t digite o numero de numeros desejados: ";
    cin >> teste;
    char* a=new char[teste];
    char* b=new char[teste];
    char* c=new char[teste];
    for (int i=0; i<teste; i++)
   {
      cout << "\n entre com o" << i + 1 << " numero: ";
      cin >> a[i] >> b[i] >> c[i];
   }
   for (int i=0; i<teste; i++)
     cout << "\n Teste numero " << i + 1 << " = "<< a[i] << b[i]<< c[i]<< endl;
   delete [] a;
   delete [] b;
   delete [] c;
   getch();
   return 0;
 }
