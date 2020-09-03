#include <constream.h>
#include <stdio.h>
#include <dos.h>
#include <process.h>

struct nodo{
  int n;
  int prox;
};

const int nulo=-1;
const int max=5;
int prim=nulo,
    livre=0;

nodo lista_s[max];

void cria(void){
  int i;
  prim=nulo;
  livre=0;
  for (i=0; i<max; i++){
    lista_s[i].n=0;
    lista_s[i].prox=i+1;
  }
  lista_s[max-1].prox=nulo;
}

void inclui(void){
  int n, p;
  if (livre!=nulo){
    cout << "\n\tDigite um elemento a incluir " ;
    cin >> n;
    p=lista_s[livre].prox;
    lista_s[livre].n=n;
    lista_s[livre].prox=prim;
    prim=livre;
    livre=p;
  }
  else{
    cout << "\tNao ha nodos livres " << endl;
    getch();
  }
}

void exclui(void){
  int n, p1, p2;
  char ch;
  cout << "\n\tDigite um elemento a excluir " ;
  cin >> n;
  p1=prim;
  while ((lista_s[p1].n!=n) && (lista_s[p1].prox!=nulo) && (lista_s[p1].n!=nulo)){
    p2=p1;
    p1=lista_s[p1].prox;
  }
  if (lista_s[p1].n==n){

    if (p1==prim)
      prim=lista_s[p1].prox;
    else
      lista_s[p2].prox=lista_s[p1].prox;

    lista_s[p1].prox=livre;
    lista_s[p1].n=nulo;
    livre=p1;
    cout << "\tElemento retirado da lista! " << endl;

    ch=getch();
    while (ch!=13)
      ch=getch();
  }
  else{
    cout << "\tNao existe este elemnto na lista " << endl;
    getch();
  }
}

void mostralista(void) {
  int p1;
  clrscr();
  cout << "\tMostra Lista" << endl;
  cout << "prim  = " << prim << endl;
  cout << "livre = " << livre << endl;
  cout << "Pressione qualquer tecla para rolar a lista" << endl;
  p1=prim;
  while (lista_s[p1].prox!=nulo) {
    cout << "Lista[" << p1 << "] = " << lista_s[p1].n << endl;
    getch();
    p1=lista_s[p1].prox;
  }
  cout << "Lista[" << p1 << "] = " << lista_s[p1].n << endl;
  getch();
  cout << "Mostra Lista de nodos livres";
  cout << "\nprim  = " << prim;
  cout << "\nlivre = " << livre;
  cout << "\nPressione qualquer tecla para rolar a lista";
  p1=livre;
  while (lista_s[p1].prox!=nulo) {
    cout << "Lista[" << p1 << "] = " << lista_s[p1].n << endl;
    getch();
    p1=lista_s[p1].prox;
  }

  cout << "Lista[" << p1 << "] = " << lista_s[p1].n << endl;
  getch();
}

int menu(void) {
  clrscr();
  int resp=0;
  while ((resp<1) || (resp>5)) {
    //moldura();
    gotoxy(14,3);  cout << "Lista simplesmente Encadeada sobre vetor estatico";
    gotoxy(28,7);  cout << "1 - Incluir elemento";
    gotoxy(28,8);  cout << "2 - Excluir elemento";
    gotoxy(28,9);  cout << "3 - Mostrar toda a Lista";
    gotoxy(28,10); cout << "4 - Limpar a Lista";
    gotoxy(28,11); cout << "5 - Sair";
    gotoxy(28,13); cout << "Opcao: ";
    cin >> resp;
    if ((resp<1) || (resp>5)) {
     /* gotoxy(3, (alt-1));*/ cout << "Opcao Invalida";
      //apito();
    } // ----- if ((resp<1) || (resp>5))
  } // ----- while ((resp<1) || (resp>5))
  return resp;
} // ----- menu()


int main() {

clrscr();
  cria();
  int op=0;
  while (op!=5) {
    op=menu();
    switch (op) {
      case 1: inclui(); break;
      case 2: exclui(); break;
      case 3: mostralista(); break;
      case 4: cria(); break;
      case 5: clrscr();
	      exit(0);
      default : printf("Bug!\n");
		exit(1); // Encerra programa com codigo erro.
    }
  }
  getch();
  return 0;
}



