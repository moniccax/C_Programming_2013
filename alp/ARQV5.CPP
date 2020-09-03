#include <stdlib.h>
#include <stdio.h>
#include <constream.h>

int main(){
  FILE *arq;
  char carac;
  arq = fopen("c:\\bc31\\bin\\ALO.Txt", "w");
  if (arq == NULL)
    cout << "Erro ao abrir.\n";
  else {
    printf("Digite um caractere: \n");
    cin >> carac;
    while (carac != 'f'){
      fputc(carac, arq);
      if (ferror(arq))
	cout << "Erro ao gravar o caractere";
      else
	cout << "Gravado.";
      cout << "Digite outro caractere";
      cin >> carac;
    }
  }
  getch();
  fclose (arq);
  return 0;
}


