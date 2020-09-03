#include <constream.h>
#include <stdlib.h>

void main(){
  int quant, i;
  int *vet;

  cout << "Digite a qtd de valores que deseja inserir no vetor: ";
  cin >> quant;

  vet = new int;
  if(vet==NULL){
    cout<<"memoria insuficiente";
    exit(1);
  }

  for (i=0; i<=quant; i++){
    cout<<"Digite o valor de vet na posicao "<<i<<endl;
    cin>>vet[i];
  }

  for (i=0; i<quant; i++){
    cout<<"I="<<vet[i];
    }

  delete(vet);
  getch();
}