#include <constream.h>
#include <process.h>

const int max=5;
int *pilha=new int[max];
int *topo=new int;

void mostra(){
  for(int i=0; i<max; i++){
    cout << "\n\n\tPilha[" << i << "]=" << pilha[i];
  }
  getch();
}

void limpa(){
  topo=&pilha[max-1];
  for(int i=0;i<max;i++)
    pilha[i]=0;
}

void empilha(int x){
  if(topo!=(pilha-1)){
    *topo=x;
    topo--;
  }
  else{
    cout <<"\n\n\tPilha cheia";
    getch();
  }
}

int desempilha(void){
  int n;
  if(topo==&pilha[max-1]){
    cout << "\n\n\tNao ha' nada para ser desempilhado";
    getch();
    return 0;
  }
  else{
    topo++;
    n=*topo;
    cout << "\n\n\tElemento desempilhado e':" << n;
    return n;
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

    if (opt == 2) {
      a = desempilha();
      if ( a ){
	cout << "Elemento desempilhado : " <<  a;
	getch();
      }
    }
    if( opt ==3)
      mostra();

    if( opt ==4)
      limpa();

  } while(opt);
}

