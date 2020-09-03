/*****************************************************************
 * Autor: Gilmar Machado Grossi                                  *
 * Compilador: BC 3.1 Borland                                    *
 * Ambiente: Tela de scroll do DOS                               *
 * Modelo de memoria: Small                                      *
 * Data: 04/04/2011                                              *
 * Objetivo: Ser um programa exemplo para as aulas de  algoritmo *
 *           e logica de programacao que mostra os comandos de   *
 *	     C++ (nao C) para gravacao em arquivo texto.         *
 *****************************************************************/

// --------------- Inclui as bibliotecas necessarias
#include <iostream.h> // uma fusao de iostream e conio
//#include <constream.h> // uma fusao de iostream e conio
		       // conio contem clrscr() , getch()
#include <stdio.h> // printf , scanf , fopen , fclose , fputc , fwrite
#include <stdlib.h> // exit()
#include <string.h> // strcpy() , strlen()
#include <fstream.h> // printf , scanf , fopen , fclose , fputc , fwrite

#define clrscr() system("clear")
#define getch() system("read a")

//using namespace std;

// --------------- Programa Principal
int main() {
  int i;
  char ch, ch2[2], linha[255];
  char linha1[]="Primeira linha, gravada com fputc.";
  char linha2[]="Ultima linha de char.";
// --------------- declaracao de um "ponteiro" (stream) de arquivo
//  FILE* arq; // nao e' necessario em C++
  clrscr();
// --------------- Abre o arquivo para escrita
//  arq=fopen("c:\\bc31\\bin\\texto1.txt","w");
//  ofstream arq("c:\\bc31\\bin\\texto1.txt", ios::out);
  ofstream arq("/home/aluno/texto1.txt", ios::out);
// --------------- Testa se abertura do arquivo deu certo
//  if (arq==NULL) {
  if (arq.fail()) {
    cout << "Erro ao abrir o arquivo.\n";
    getch();
    exit(1); // ----- Encerra o programa com codigo de erro
  }

// --------------- Gravando no arquivo texto caracter a caracter

/* ----- Grava a frase "Primeira linha."
	 Observe os 3 comandos for a seguir. Todos funcionam e fazem a
	 mesma coisa. A "string" dentro de linha1 e' terminada com '\0'
	 colocada pela inicializacao na criacao do vetor de char linha1.
	 Este fato pode ser utilizado de varias formas, como demonstrado
	 por estes comandos for.
  for (i=0; linha1[i]!=0; i++)
  for (i=0; linha1[i]; i++)
*/
  for (i=0; linha1[i]!='\0'; i++)
//    fputc(linha1[i], arq);
//    arq << linha1[i];
    arq.put(linha1[i]);
// ----- Grava o '\n' que faz mudar de linha em um arquivo texto
//  fputc('\n', arq);
  arq << '\n';
// ----- Grava na 2a linha os digitos de 0 a 9 pelo codigo ascii
//       caracter a caracter mas com fputs
  ch2[1]='\0';
  for (i=48; i<58; i++) {
    ch2[0]=i;
//    fputs(ch2, arq);
    arq << ch2;
  }
  ch2[0]='\n';
//  fputs(ch2, arq);
  arq << ch2;
// ----- Grava na 3a linha as letras de A a Z
  for (i='A'; i<='Z'; i++)
//    fprintf(arq, "%c", i);
    arq << (char)i;
//  fprintf(arq, "%c", '\n');
  arq << '\n';
// ----- Grava a frase "Ultima linha de char."
  for (i=0, ch=linha2[i]; linha2[i]!=0; i++, ch=linha2[i])
//    fwrite(&ch, sizeof(ch), 1, arq);
    arq.write(&ch, sizeof(ch));
  ch='\n';
//  fwrite(&ch, 1, 1, arq); // ----- Observe o tamanho de char = 1
    arq.write(&ch, sizeof(ch));

// --------------- Gravando no arquivo texto linha a linha

//  fputs("Gravando uma frase diretamente com fputs\n", arq);
//  arq << "Gravando uma frase diretamente com fputs\n";
  arq.put("Gravando uma frase diretamente com fputs\n");

  strcpy(linha, "Uma linha gravada com fwrite.\n");
//  fwrite(&linha, strlen(linha), 1, arq);
  arq.write(linha, strlen(linha));

//  fprintf(arq, "%s", "Uma linha gravada com fprintf\n");
  arq << "Uma linha gravada com fprintf\n";
// --------------- Checando se houve erro de gravacao
//                 Este teste deveria ter sido feito a cada uma
//                 das gravacoes anteriores.
//  if ferror(arq) {
  if (arq.fail()) {
    cout << "Erro ao tentar gravar no arquivo" << endl;
    exit(1);
  }
// ----- Fecha o arquivo para esvaziar os buffers do S.O. e da stream
  arq.close();
  cout << "Arquivo Gravado\n";
  getch();
  return 0;
}

