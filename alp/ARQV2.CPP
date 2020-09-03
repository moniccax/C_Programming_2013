/*****************************************************************
 * Autor: Gilmar Machado Grossi                                  *
 * Compilador: BC 3.1 Borland                                    *
 * Ambiente: Tela de scroll do DOS                               *
 * Modelo de memoria: Small                                      *
 * Data: 04/04/2011                                              *
 * Objetivo: Ser um programa exemplo para as aulas de  algoritmo *
 *           e logica de programacao que mostra os comandos de   *
 *	     C (nao C++) para leitura em arquivo texto.          *
 *****************************************************************/

// --------------- Inclui as bibliotecas necessarias
#include <constream.h> // uma fusao de iostream e conio
		       // conio contem clrscr() , getch()
#include <stdio.h> // printf , scanf , fopen , fclose , fputc , fwrite
#include <stdlib.h> // exit()
#include <string.h> // strcpy() , strlen()

// --------------- Programa Principal
int main() {
  int i;
  char ch, linha[255];
// --------------- declaracao de um "ponteiro" (stream) de arquivo
  FILE* arq;
  clrscr();
// --------------- Abre o arquivo para leitura
  arq=fopen("c:\\bc31\\bin\\texto1.txt","r");
// --------------- Testa se abertura do arquivo deu certo
  if (arq==NULL) {
    printf("Erro ao abrir o arquivo.\n");
    getch();
    exit(1); // ----- Encerra o programa com codigo de erro
  }

// --------------- Lendo a 1a linha no arquivo texto caracter a caracter

  ch=fgetc(arq);
  while ((!feof(arq)) && (ch!='\n')) {
    cout << ch;
    ch=fgetc(arq);
  }
  cout << '\n';
  getch();
// ----- Le a 2a linha com os digitos de 0 a 9 pelo codigo ascii
  fgets(linha, 2, arq);
  while ((!feof(arq)) && (linha[0]!='\n')) {
    cout << linha;
    fgets(linha, 2, arq);
  }
  cout << endl; // ----- o mesmo que '\n' para saltar linha
  getch();
// ----- Le a 3a linha com as letras de A a Z
  fread(&ch, sizeof(ch), 1, arq);
  while ((!feof(arq)) && (ch!='\n')) {
    cout << ch;
    fread(&ch, sizeof(ch), 1, arq);
  }
  cout << endl; // ----- o mesmo que '\n' para saltar linha
  getch();
// ----- Le a 4a linha com a frase "Ultima linha de char."
  fscanf(arq, "%c", &ch);
  while ((!feof(arq)) && (ch!='\n')) {
    cout << ch;
    fscanf(arq, "%c", &ch);
  }
  printf("%c", '\n');
  getch();

// --------------- Lendo no arquivo texto linha a linha

// ----- Le a 5a linha com a frase "Gravando uma frase diretamente com fputs"
  fgets(linha, 255, arq);
  for (i=0; linha[i]!='\n'; i++);
  linha[i+1]='\0';
  cout << linha;
  getch();

// ----- Le a 6a linha com a frase "Uma linha gravada com fwrite."
//       Um limitacao seria do comando fread em arquivos textos, e'
//       nestes o tamanho do registro e' variavel, e o comando de
//       leitura deve reconhecer o '\n' e parar, o que o fread
//       nao faz. Ele tem que saber o tamanho exato em bytes do
//       que vai ser lido. No nosso caso 30 incluindo o '\n'
  fread(&linha, 30, 1, arq);
  for (i=0; linha[i]!='\n'; i++);
  linha[i]='\0';
  cout << linha << endl;
  getch();

// ----- Le a 7a linha com a frase "Uma linha gravada com fprintf"
//       O fscanf para a leitura se encontrar um espaco usando %s
//       A unica solucao e' saber o tamanho da linha. O que nao serve
//       para trabalhar com arquivos texto.
  linha[0]='\0';
  fscanf(arq, "%30c", &linha);
  for (i=0; linha[i]!='\n'; i++);
  linha[i+1]='\0';
  cout << linha;

// --------------- Checando se houve erro de gravacao
//                 Este teste deveria ter sido feito a cada uma
//                 das gravacoes anteriores.
  if ferror(arq) {
    cout << "Erro ao tentar gravar no arquivo" << endl;
    exit(1);
  }
// ----- Fecha o arquivo para esvaziar os buffers do S.O. e da stream
  fclose(arq);
  cout << "Arquivo Lido";
  getch();
  return 0;
}

