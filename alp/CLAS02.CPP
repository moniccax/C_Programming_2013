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
    Pessoa povo[10];
    int ult;
  public:
    void valordeult();
    void armazenaPessoa(char n[255], int i, float a);
    void removePessoa(char n[255]);
    int buscaPessoa(char n[255]);
    void imprimePovo();
    void imprimePessoa(int i);
    void couut();
};

    void Agenda:: armazenaPessoa(char n[255], int i, float a) {
      strcpy(povo[ult].nome , n);
      povo[ult].idade=i;
      povo[ult].altura=a;
      ult++;
    } //armazenaPessoa

    void Agenda :: valordeult(){
      int i;
      for(i=0 ; i<10 ; i++) {
	strcpy(povo[i].nome, "vazio");
	povo[i].idade=0;
	povo[i].altura=0;
      }
      ult=0;
    }

    void Agenda :: removePessoa(char n[255]){
      int i=0;
      while((i<10) && (strcmp(povo[i].nome , n)!=0 )) {
	i++;
      } //while
      if(strcmp(povo[i].nome , n)!=0) {
	cout << "ERROR!";
      } //if
      else if(strcmp(povo[i].nome , n)==0) {
	strcpy(povo[i].nome , "vazio");
	povo[i].idade=0;
	povo[i].altura=0.0;
      } //else if
    }  //voidAgenda

    int Agenda :: buscaPessoa(char n[255]){
      int i;
      while((i<10) && (strcmp(povo[i].nome , n)!=0 )) {
	i++;
      }//while
      if(strcmp(povo[i].nome , n)!=0) {
	i=11;
      } //if
      return i;
    }  //buscaPessoa

    void Agenda :: imprimePovo() {
      for (int c=0; c<10; c++){
	cout<<"\t"<<povo[c].nome;
	cout<<"\t"<<povo[c].idade;
	cout<<"\t"<<povo[c].altura<<endl;
      }  //for
    }  //Agenda

     void Agenda :: imprimePessoa(int i){
       cout<<povo[i].nome<<endl;
       cout<<povo[i].idade<<endl;
       cout<<povo[i].altura<<endl;
     }   //imprimePessoa

     void Agenda :: couut(){
       cout<<povo[1].nome;
       cout<<povo[1].idade;
       cout<<povo[1].altura;
     }


int main(){
  clrscr();
  void valordeult();
  void armazenaPessoa(char n[255], int i, float a);
  void removePessoa(char n[255]);
  int buscaPessoa(char n[255]);
  void imprimePovo();
  void imprimePessoa(int i);
  void couut();

  char n[255];
  int i;
  float alt;
  Agenda x;
  x.valordeult();
  for (int h=0; h<10; h++){
    cout<<"Digite o nome, idade e altura: ";
    cin>>n>>i>>alt;
    x.armazenaPessoa(n, i, alt);
  }
  x.imprimePessoa(1);
  x.removePessoa("Igor");
  x.buscaPessoa("Monica");
  x.couut();
  x.imprimePovo();
  getch();
  return 0;
}
