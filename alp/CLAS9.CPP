#include <constream.h>

const int TAM=10;

class ListaEncadeadaComVetor {
    int inicio;
    int Dados[TAM];
    int Aux[TAM];

    int achaPosUltimo();
    int achaPosLivre();

  public:
    ListaEncadeadaComVetor();
    int insereDado(int D);
    int removeDado(int D);
    void imprimeLista();
};

ListaEncadeadaComVetor :: ListaEncadeadaComVetor (){
  for (int i=0; i<TAM; i++){
    Dados[i]=0;
    Aux[i]=-1;
  }
  Dados[0]=10;
  Dados[1]=1;
  Dados[3]=9;
  Dados[5]=11;
  Dados[6]=34;
  Aux[0]=5;
  Aux[2]=5;
  Aux[3]=0;
  Aux[5]=1;
  Aux[6]=-2;
  inicio=0;
}

int ListaEncadeadaComVetor :: insereDado(int D){
  int i;
  for (i=0; i<=10; i++){
    if (Dados[i]==0){
      Dados[i]=D;
      return 1;
    }
  }
  return 0;
}

int ListaEncadeadaComVetor :: removeDado(int D){
  for(int i=0; i<=10; i++){
    if (Dados[i]==D){
      Dados[i]=0;
      return 1;
    }
  }
  return 0;
}

void ListaEncadeadaComVetor :: imprimeLista(){
  int pos=inicio;
  cout << "Lista: ";
  cout << "Inicio: " << pos << endl;
  for (int i=0; i<TAM; i++){
    cout << Dados[pos] << " (" << pos << ") ";
    pos=Aux[pos];
    if (pos == -2)
      break;
    else cout << ", ";
  }
  cout << endl;
}

int main(){
  ListaEncadeadaComVetor x;
  x.insereDado(int r);
  int removeDado(int D);
  void imprimeLista()
  getch();
  return 0;
}