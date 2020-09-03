#include <constream.h>
#include <string.h>



struct carro {
   int ano;
   float motor;
   char marca[30];
   char modelo[40];
   char cor[20];
   float preco;
};
//grava informa‡äes na oitava posi‡Æo do vetor de struct carro.
carro vet[1];


void main(){
 clrscr();
 int i,y=3;
 vet[0].ano=1997;
 vet[0].motor=1.0;
 strcpy(vet[0].marca,"volkswagen");
 strcpy(vet[0].modelo,"gol");
 strcpy(vet[0].cor,"vermelho");
 vet[0].preco=10000;

 vet[1].ano=1997;
 vet[1].motor=1.0;
 strcpy(vet[1].marca,"volkswagen");
 strcpy(vet[1].modelo,"gol");
 strcpy(vet[1].cor,"amarelo");
 vet[1].preco=10000;

 for (i=0; (i<=1); i++){
   if(vet[i].cor=="amarelo") {
     if (vet[i].preco<=20000) {
     gotoxy(10,y);
     cout << "o carro numero "<<i<<" e amarelo e tem pre‡o de "<<vet[i].preco;
     cout << endl;
     y++;
    }
   }
 }
 getch();
}