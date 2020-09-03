#include <conio.h>
#include <constream.h>
#include <dos.h>

void main(void) {

  int i;
  char ch;

  clrscr();
  i=0;
  ch='x';
  while (ch=='x') {
    gotoxy(5,5);
    cout << "          ";
    gotoxy(5,5);
    cout << "I=" << i;
    i=i+1;
    // ----- O delay é substituido por um trecho de código a ser avaliado
    delay(1000);
    if (i==30000)
      i=0;
    if (kbhit()!=0)
      ch=getch();
  }
}