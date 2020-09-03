/*****************************************************************
 * Autor: Gilmar Machado Grossi                                  *
 * Compilador: gcc no Linux Ubuntu 10.04                         *
 * Ambiente: Tela de scroll da Konsole                           *
 * Modelo de memoria: Small                                      *
 * Data: 01/06 de 2011                                           *
 * Objetivo: Ser um programa exemplo para as aulas praticas de   *
 *           algoritmo e logica de programacao, mostrando a      *
 *	     o uso de classes e a sobrecarga de operadores.      *
 *****************************************************************/

// ----- Inclui as bibliotecas necessarias

#include <iostream.h> // cout, cin, endl
#include <stdio.h> // printf e scanf
#include <stdlib.h> //
#include <string.h> //
 

//using namespace std;

// --------------- Declaracao de variaveis globais
#define esc 27
#define clrscr() system("cls")
#define getch() system("pause")

static const int max=255;

class String {
  private:
    char str[max];

  public:
    String() { // ----- construtor default
      str[0]='\0';
    }
    String(char ch, int n) { // ----- construtor copia n vezes ch
      int i;
      for (i=0; i<n; i++)
        str[i]=ch;
      str[i]='\0';
    }
    String(char s[]) { // ----- construtor converte vetor de char em string
      strcpy(str, s);
    }
    int len() const {
      return strlen(str);
    }
    void print() const {
      cout << str;
    }
    void println() const {
      cout << str << endl;
    }
    String operator +=(String& s) { // ----- concatena
      if (strlen(str) + strlen(s.str) < max)
        strcat(str, s.str);
      return String(str);
    }
    String operator +(String& s) { // ----- concatena
      char temp[max];
      strcpy(temp, str);
      if (strlen(str) + strlen(s.str) < max)
        strcat(temp, s.str);
      return String(temp);
    }
};

// --------------- Programa Principal
int main() {
  String s1('=',30), s2("Ola Turma"),
         s3(" - Criando a classe string"),
         s4, s5;

  clrscr();
  cout << "s1:" ; s1.println();
  cout << "s2 e s3:"; s2.print(); s3.println();
  cout << "s1:" ; s1.println();
  cout << endl;
  cout << "Tamanho de s1 : " << s1.len() << endl;
  cout << endl;
  

  s4="Depois de sofrer na ";
  s5="lecampo com vetor de char";
  s4=s4+s5;
  s4.println(); 
  s4="Que tal fazer tudo de novo";
  s5=" com a classe String";
  s4+=s5;
  s4.println();
  cout << endl;
  getch();
  return 0;
}


