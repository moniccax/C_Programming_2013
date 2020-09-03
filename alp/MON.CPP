#include <constream.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


class pessoa {
  private:
    char nome[255];
    int idade;
    float alt;
  public:
    void init (char *n, int i, float  h){
      strcpy(nome,n);
      idade=i;
      alt=h;
    }

  void print(){
    cout<< "Nome=" <<nome << endl;
    cout<< "Idade=" <<idade << endl;
    cout<< "Altura=" <<alt << endl;
  }

  void leia(){
    cout<< "Nome=";
    gets(nome);
    cout<< "Idade=";
    cin>>idade;
    cout<< "Alt=";
    cin>>alt;
  }
};

int main() {
  pessoa z;
  clrscr();
  z.init("Teste", 1, 1);
  z.print();
  getch();
  z.leia();
  z.print();
  getch();
  return 0;
}
