#include <constream.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

char oqvai[255];

char* left(char* oqveio, int n) {
  strcpy (oqvai, oqveio);
  oqvai[n]='\0';
  return oqvai;
}

char* right(char* oqveio, int n){
  strcpy(oqvai, oqveio+(strlen(oqveio)-n));
  return oqvai;
}

char* mid(char* oqveio, int pos, int tam){
  strcpy(oqvai, oqveio+(strlen(oqveio)-pos));
  oqvai[tam]='\0';
  return oqvai;
}

int main(){
  clrscr();
  cout<<"\n\tTeste left(\"O pao esta gostoso\",5): " << left("O pao esta gostoso",5);
  cout<<"\n\tTeste right(\"O pao esta gostoso\",7): "<<right("O pao esta gostoso", 7);
  cout<<"\n\tTeste mid(\"O pao esta gostoso\", 5 , 3): "<<mid("O pao esta gostoso", 5, 3);
  getch();
  return 0;
}