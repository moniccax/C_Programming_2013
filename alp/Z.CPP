#include <constream.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
  clrscr();
  char frase[255];
  int cons=0, vogais=0;
  cout<<"Digite uma frase:";
  gets(frase);
  while(strcmp (frase, "terminei") != 0.0){
    int len=strlen(frase);
    for (int i=0; i<len; i++){
      cout<<"-"<<frase[i];
      switch (frase[i]){
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u': vogais++;
	break;
      }//end swictch
      if ((frase[i]>='a')&&(frase[i]<='z'))
	cons++;
    }//end for
    cout<<"\nO numero de letras e': "<<cons;
    cout<<"\n\tO numero de consoantes e': "<<cons-vogais;
    cout<<"\n\tO numero de vogais e': "<<vogais;
    cout<<"\n\n\tDigite uma frase:";
    gets(frase);
    }//end while
  getch();
  return 0;
}