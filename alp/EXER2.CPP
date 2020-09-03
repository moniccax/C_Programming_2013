#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <constream.h>

int main(){
    int altura, maior, menor, homem=0, mulher=0, altura_mulher=0;
    clrscr();
    cout << "Qual sua altura?";
    cin >> altura;
    maior=menor=altura;
    for (int i=0; i<5; i++) {
      cout << "Qual sua altura?";
      cin >> altura;
      if (altura>maior) {
	maior=altura;
      }
      else if (altura<menor) {
	menor=altura;
      }
      char sexo;
      cout << "Qual seu sexo?";
      cin >> sexo;
      if (sexo=='f'){
	  mulher=mulher+1;
	  altura_mulher=altura_mulher+altura;
      }

      else if (sexo=='m'){
	  homem=homem+1;
      }
    }
    cout<< "Homem = "<<homem<<"\n";
    cout<< "Menor = "<<menor<<endl;
    cout<< "Maior = "<<maior<<endl;
    float media;
    media=altura_mulher/mulher;
    cout<< "Media das Alturas = " <<media<<endl;
    getch();
    return 0;

}