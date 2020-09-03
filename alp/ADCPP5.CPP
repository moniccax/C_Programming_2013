#include <constream.h>
#include <stdlib.h>

int media(int s, int q){
  return (s/q);
}

void main(){
  int i, quant, soma;
  int *vet;

  cout << "\n\tDigite a qtd de notas que deseja inserir: ";
  cin >> quant;

  vet = new int;
  if(vet==NULL){
    cout<<"\n\n\n\tMemoria insuficiente";
    exit(1);
  }

  for (i=0; i<quant; i++){
    cout<<"\n\tDigite as notas dos alunos "<<(i+1)<<endl;
    cin>>vet[i];
  }

  for (i=0; i<=quant; i++){
    soma+=vet[i];
    }

  cout << "A media das notas e' : " << media(soma, quant);
  delete(vet);
  getch();
}