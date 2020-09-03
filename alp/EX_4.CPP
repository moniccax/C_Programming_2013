#include <constream.h>

const int max=3;
int head=-1, tail=0, fila[max];

void enfileira(int x){
  if(tail<max){
    fila[tail]=x;
    tail++;
  }
  else{
    cout << "Fila cheia";
    getch();
  }
}

int desenfileira(void){
  head++;
  int n;
  if(head==tail){
    cout <<"Nao ha' nada para desenfileirar";
    return 0;
  }
  else{
    n=fila[head];
//    head++;
    return n;
  }
}
void main(){
  int opt=1, a;
  do {
    clrscr();
    cout << "\n\t\t Escolha the Option : "
	 << "\n\t1-Enfilation\n\t2-Desenfilation "
	  << "\n\t0-Sair\n\t";
    cin >> opt;

    if (opt==1){
      cout <<"\n\n\tEnfilere um numero:";
      cin >> a;
      enfileira(a);
    }

    if (opt == 2) {
      a = desenfileira();
      if ( a ){
	cout << "Elemento desenfileirado : " <<  a;
	getch();
      }
    }
  } while(opt);
}


