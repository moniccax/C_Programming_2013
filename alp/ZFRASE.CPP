#define true 1
#define false 0

#include <constream.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){
  int vogais, cons, j=0, z=0, ok;
  char frase[255];
  cout<<"\n\tDigite uma frase: ";
  gets(frase);

  while (strcmp(frase,"Terminei")!=0){
    int caracter=strlen(frase);
    vogais=0;
    cons=0;
    for (int i=0; i<caracter; i++){
      switch (frase[i]){
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
	case 'A':
	case 'E':
	case 'I':
	case 'O':
	case 'U': vogais++;
		  break;
      }//end switch
      if ((frase[i]>='A') && (frase[i]<='Z'))
	cons++;
      if ((frase[i]>='a') && (frase[i]<='z'))
	cons++;
    }//end for
    cons=cons-vogais;
    cout<< "\n\t A frase tem: "<<caracter<<" caracteres";
    cout<<"\n\t A frase tem: "<<cons<<" consoantes";
    cout<<"\n\t A frase tem: "<<vogais<<" vogais";

    ok=true;/*variavel logica que quebra o while sem uso de break
	     ao encontrar o primeiro digite de 0-9 */

    while((j<=caracter) && ok) {
      for (z='0'; z<='9'; z++)
	if (frase[j]==z)
	  ok=false;
      j++;
    }

    cout<<"\n\tO primeiro digite de 0-9 aparece na coluna: "<<j;
     
    getch();
    cout<<"\n\n\tDigite uma frase: ";
    gets(frase);
  }
  getch();
  return 0;
}