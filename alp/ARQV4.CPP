#include <stdlib.h>
#include <stdio.h>
#include <constream.h>

/*int main(){
  FILE *file;
  file=fopen("c:\\bc31\\bin\\Momo.Txt", "w");  //determinar local
  fprintf(file,"Pao com mortadela."); //file pois eh o ponteiro >> mensagem
  fclose(file);
  return 0;
}*/  //criou arquivo

/*
int main(){
  FILE *file;
  file=fopen("c:\\bc31\\bin\\Momo.Txt", "r");

  if (file == NULL){   //nao aponta endereco de memoria
    printf("Arquivo nao pode ser aberto\n");
    getch();
    exit (0);
  }

  char frase[100];

  while(fgets(frase, 100, file)!=NULL){
    printf("%s", frase);
    getch();
  }

  fclose(file);
  return 0;
} */ //mostra o q ta no arquivo

int main(){
  FILE *file;
  file=fopen("c:\\bc31\\bin\\Momo.Txt", "a");

  if (file == NULL){   //nao aponta endereco de memoria
    printf("Arquivo nao pode ser aberto\n");
    getch();
    exit (0);
  }

  fprintf(file, "\nPrimeira linha");

  char frase[]="\nSegunda linha";
  fputs(frase, file);

  char caractere='3';
  fputc(caractere,file);

  fclose(file);
  getch();
}   //acrescenta ao arquivo
