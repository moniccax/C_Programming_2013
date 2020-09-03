#include <constream.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

int main (void) {
  // -----> Aqui comeca o programa principal de fato
  char campo[255]; // Vetor de char que recebe o campo lido

  // ----- Le campo protegido
  clrscr();
  gotoxy(5,6);
  cout << "LEIA SENHA NUMERICA DE 8 POSICOES : ";
  campo[0]='\0';
  LE(-3,8,41,6,campo);
  gotoxy(5,7);
  cout << "Leu senha : " << campo << endl;
  getch();
  // ----- Le campo pre-prenchido
  gotoxy(5,9);
  cout << "LEIA NOME PREPREENCHIDO : ";
  strcpy(campo, "Jose da Silva");
  LE(1,40,31,9,campo);
  gotoxy(5,10);
  cout << "Leu : " << campo << endl;
  getch();
/*
  // ----- Le o CPF
  gotoxy(5,12);
  cout << "LEIA CPF AQUI : ";
  campo[0]='\0';
  LE(7,11,21,12,campo);
  // ----- Espera <enter> parar encerrar o programa
*/
  fflush(stdin);
  getch();
  return 0;
}
