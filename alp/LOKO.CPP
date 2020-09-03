#include <constream.h>
#include <stdio.h>
#include <string.h>
class pessoa{
  private:
    int idade;
    float altura;
    char nomepessoa[255];
  public:
    void init(char* nome, int i, float h){
      strcpy(nomepessoa, nome);
      idade=i;
      altura=h;
    }
    void leia(){
      cout <<"\n\tDigite o primeiro nome: ";
      gets(nomepessoa);
      cout <<"\n\tDigite a altura: ";
      cin >> altura;
      cout <<"\n\tDigite a idade: ";
      cin >> idade;
    }
    void escreva(){
      cout <<"\n\tO nome e': " << nomepessoa;
      cout <<"\n\tA altura e': " << altura;
      cout <<"\n\tA idade e': " << idade;
    }
};

void main(){
  pessoa dados;
  char nome[255];
  int idade;
  float altura;
  clrscr();
  dados.init("Teste", 1, 1);
  dados.escreva();
  getch();
  clrscr();
  dados.leia();
  dados.escreva();
  getch();
}