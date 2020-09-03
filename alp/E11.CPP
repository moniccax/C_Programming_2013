#include <constream.h>
#include <stdio.h>
#include <stdlib.h>

void main(){
  clrscr();
  FILE *arq;
  arq = fopen("c:\\bc31\\bin\\ex9.txt","rb");
  if (arq==NULL){
    cout << "Nao foi possivel encontrar o arquivo\n";
    getch();
    exit(1);
  }

  int i;
  float f;
  char linha[255];

 // fgets(linha,2, arq);
 // cout << linha;
 // fread(&linha, sizeof(linha), 1, arq);
 // cout << linha;
  fscanf(arq, "%s", &linha);
  cout << linha << endl;
 // fread(&i, sizeof(int), 1, arq);
 // cout << i;
  fscanf(arq, "%d", &i);
  cout << i << endl;
 // fread(&f, sizeof(float), 1, arq);
 // cout << f;
  fscanf(arq, "%f", &f);
  cout << f << endl;

  if (ferror(arq)){
    cout << "Nao foi possivel abrir o arquivo.";
    getch();
    exit(1);
  }
  fclose(arq);
  cout << "\n\nArquivo lido.";
  getch();
}