#include <constream.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Pessoa {
  char nome[20];
  int idade;
  float altura;
}; //struct Pessoa

class Agenda {
  private:
    Pessoa registro[10];
    int x;
  public:
    void inicializa(){
      for (int i=0; i<10; i++){
	strcpy(registro[i].nome, "Vazio");
	registro[i].idade=0;
	registro[i].altura=0.0;
      }
      x=0;
    }

    void armazena(char n[20], int i, float a){
      strcpy(registro[x].nome, n);
      registro[x].idade=i;
      registro[x].altura=a;
      x++;
    }

    void remove(char n[20]){
      int i=0;
      while ((i<10)&&(strcmp(registro[i].nome, n)!=0))
	i++;
      if ((strcmp(registro[i].nome, n))==0){
	strcpy(registro[i].nome, "Vazio");
	registro[i].idade=0;
	registro[i].altura=0.0;
      }
      else
	cout << "NAO EXISTE";
    }

    void imprime(){
      int k;
      for (k=0; k<10; k++){
	cout << "\n\n\n" << registro[k].nome;
	cout << "\t"<<registro[k].idade;
	cout << "\t"<<registro[k].altura;
	getch();
      }
    }
};

void main(){
  Agenda a;
  char no[20];
  int id;
  float al;
  a.inicializa();
  for (int i=0; i<10; i++){
    cout << "\nNome: "  ;
    gets(no);
    cout << "\nIdade: "  ;
    cin >> id;
    cout << "\nAltura: ";
    cin >> al;
    clrscr();
    a.armazena(no, id, al);
  }
  cout << "\nPessoa para remover:";
  gets(no);
  a.remove(no);
  a.imprime();
  clrscr();
  getch();
}