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

#include <iostream> // cout, cin, endl
#include <stdio.h> // printf e scanf
#include <stdlib.h> //
#include <cstring> //
 

using namespace std;

// --------------- Declaracao de variaveis globais
#define esc 27
#define clrscr() system("cls")
#define getch() system("pause")

// --------------- Inicio da definicao da classe String
class String {
  private:
    static const int max=255;
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
    String left(int n) const {
      int i;
      String temp;
      for (i=0; i<n; i++)
        temp.str[i]=str[i];
      temp.str[n]='\0';
      return temp;
    }
    int operator ==(String& s) { // ----- igualdade
      int i;
      for (i=0; str[i]==s.str[i]; i++)
        if ((str[i]=='\0') && (s.str[i]=='\0'))
          return 1; // ----- e' igual
      return 0; // ----- nao e' igual
    }
    friend ostream& operator << (ostream& stream, String& s) { // ----- op. insercao
      stream << s.str;
      return stream;
    }
    friend istream& operator >> (istream& stream, String& s) { // ----- op. extracao
      stream >> s.str;
      return stream;
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
// --------------- Fim da definicao da classe String

// --------------- Inicio da Reembalagem das funcoes da classe String pelo
//                 Padrao da programacao estruturada
String Esq(String s, int qte) {
  String tmp;
  tmp=s.left(qte);
  return tmp;
}
       
// --------------- Fim da Reembalagem das funcoes da classe String pelo
//                 Padrao da programacao estruturada

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
  s4=s1;
  if (s1==s4) {
    cout << "Agora s1 e' igual a S4 = ";
    s1.println();
  }
  cout << endl; 
  cin >> s1;
  cout << "S1 de novo=" << s1 << endl;
  cout << endl;
  s1=s1.left(3); 
  cout << "left 3 de S1 =" << s1 << endl;
  cout << endl; 
  cout << "left 2 de S1 =" << Esq(s1,2) << endl;
  cout << endl; 
  getch();
  return 0;
}


