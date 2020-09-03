#include <constream.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

class pessoa{
  private:
    char nome[255];
    int idade;
    float alt;
  public:
    void init(char *n, int i, float a){
      strcpy(nome, n);
      idade=i;
      alt=a;
    }

    void leia(){
      cout<<"\nNome= ";
      gets(nome);
      cout<<"\nIdade= ";
      cin>>idade;
      cout<<"\nAlt= ";
      cin>>alt;
    }

    void print(){
      cout<<"\nNome= " <<nome;
      cout<<"\nIdade= " <<idade;
      cout<<"\nAlt= " <<alt;
    }
};

int main(){
  pessoa *p_cad;
  p_cad= new pessoa;
  (*p_cad).leia();
  clrscr();
  (*p_cad).print();
  getch();
  delete p_cad;
  return 0;
}