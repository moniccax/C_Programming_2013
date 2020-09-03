#include <constream.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Pessoa{
  char Nome[255];
  int Idade;
  float Altura;
};

class Agenda{
  private:
    Pessoa Povo[10];
    int w;
  public:
    void Inicializa () {
      for (int i=0; i<=5; i++){
	strcpy(Povo[i].Nome, "Vazio.");
	Povo[i].Idade=0;
	Povo[i].Altura=0.0;
      }
    }//end construtor

    void ArmazenaPessoa (char n[255], int i, float a){
      strcpy(Povo[w].Nome, n);
      Povo[w].Idade=i;
      Povo[w].Altura=a;
      w++;
    } //end ArmazenaPessoa

    void RemovePessoa (char n[255]){
      for (int i=0; i<=10; i++){
	if (strcmp(Povo[i].Nome, n) == 0)
	  (strcpy(Povo[i].Nome, " "));
      }//end  for
    } //end RemovePessoa

    void BuscaPessoa (char n[255]){
      for (int i=0; i<=10; i++){
	if (strcmp(Povo[i].Nome, n) == 0)
	  cout << "A posicao do nome digitado e' : " << w;
      }//end for
    }//end BuscaPessoa

    void ImprimePovo(){
      for (int i=0; i<=5; i++){
	cout << "Nome: " << Povo[i].Nome << endl;
	cout << "Idade: " << Povo [i].Idade << endl;
	cout << "Altura: " << Povo[i].Altura << endl;
      }//end for
    }//end ImprimePessoa

    void ImprimePessoa (int i){
      cout << "A pessoa na posicao " << i << " e' " << endl;
      cout << Povo[i].Nome << ", " << Povo[i].Idade << ", " << Povo[i].Altura;
    }
};//end class Agenda

int main(){
  Agenda A;
  char no[255];
  int id;
  float al;
  A.Inicializa();
  for (int i=0; i<=5; i++){
    cout << "\n\tDigite o primeiro Nome: ";
    cin >> no;
    cout << "\n\tDigite a Idade: ";
    cin >> id;
    cout << "\n\tDigite a Altura: ";
    cin >> al;
    A.ArmazenaPessoa(no, id, al);
    clrscr();
  }
  A.ImprimePovo();
  A.BuscaPessoa("Monica");
  getch();
  return 0;
}