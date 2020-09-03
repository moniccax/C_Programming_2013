#include <constream.h>

const int max=5;
int *head, *tail;
int *filac=new int[max];

void limpa(){
  head=&filac[max-1];
  tail=filac-1;
  for(int i=0;i<max;i++)
    filac[i]=0;
}

void enfileirac(int x){
  tail++;
  if(tail==&filac[max])
      tail=filac;
  if(tail+1==head){
    cout << "\n\n\tFila cheia";
    getch();
  }
  else{
    *tail=x;

  }
}

int desenfileirac(void){
  head++;
  int n;
  if(head==&filac[max]){
    head=filac;
  }
  if(head-1==tail){
    cout <<"\n\n\tFila vazia";
    head--;
    getch();
    if(head==filac)
      head=&filac[max-1];
    return 0;
  }
  else{
    n=*head;
    cout <<"\n\n\tElemento desenfileirado: " << n;
    getch();
    return n;
  }
}

void mostra(){
  for(int i=0; i<max; i++){
    cout <<"\n\n\tFila[" <<i<<"]= " << filac[i];
    getch();
  }
}

void main(){
  limpa();
  int opt=1, a;
  do {
    clrscr();
    cout << "\n\t\t Escolha the Option : "
	 << "\n\t1-Enfilation\n\t2-Desenfilation "
	 <<"\n\t3-Mostration\n\t4-Linfilation"
	  << "\n\t0-Sair\n\t";
    cin >> opt;

    if (opt==1){
      cout <<"\n\n\tEmpilhe um numero:";
      cin >> a;
      enfileirac(a);
    }

    if (opt == 2)
      desenfileirac();

    if( opt ==3)
      mostra();

    if( opt ==4)
      limpa();

  } while(opt);
}











