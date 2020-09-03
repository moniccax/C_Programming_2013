#include <conio.h>
#include <constream.h>
#include <iostream.h>

int main()

{
    int num,resto;

    clrscr ();
    cout << "\n\tEscreva um numero inteiro";
    cin >> num;
    resto=num%2;

    if (resto==0) {
      cout << "\n\tNumero par";
    }
    else{
      cout << "\n\tNumero impar";
    }

    resto=num%3;
    if (resto==0)  {
      cout << "\n\tMultiplo de 3";
    }

  getch();
  return 0;
}