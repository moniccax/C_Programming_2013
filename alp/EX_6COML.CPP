#include <constream.h>

const int max=5;
int* topo=new int;
int* pilha=new int [max];

void limpa(){
  topo=pilha;
  for(int i=0; i<max; i++)
    pilha[i]=0;
}

void empilha(int x){
  if(topo == &pilha[max]){
    cout <<"Pilha cheia";
    getch();
  }
  else{
    *topo=x;
    topo++;
  }
}

int desempilha(){
  int x;
  if(topo == pilha){
    cout << "Pilha vazia";
    getch();
    return 0;
  }
  else{
    topo--;
    x=*topo;
    cout << "Elemento desempilhado" << x;
    return x;
  }
}

void mostra(){
  int i;
  for(i=max;i>0;i--){
    cout << "\n\n\tPilha["<<i <<"]=" << pilha[i];
    getch();
  }
}


void main(){
  limpa();
  int opt=1, a;
  do {
    clrscr();
    cout << "\n\t\t Escolha the Option : "
	 << "\n\t1-Empilation\n\t2-Desempilhation "
	 <<"\n\t3-Mostration\n\t4-Limpilhation"
	  << "\n\t0-Sair\n\t";
    cin >> opt;

    if (opt==1){
      cout <<"\n\n\tEmpilhe um numero:";
      cin >> a;
      empilha(a);
    }

    if (opt == 2)
      desempilha();

    if( opt ==3)
      mostra();

    if( opt ==4)
      limpa();

  } while(opt);
}

