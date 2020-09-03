#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <process.h>

const int max=5;
int head=-1, tail=0;

int fila[max];

void enfileira(){
  int n;
  if(tail<max){
    cout << "digite um elemento";
    cin >> n;
    fila[tail]=n;
    tail++;
  }
  else
    cout << "nao ha espaco";
  getch();
}

void desenfileira(){
  head++;
  int n;
  char ch;
  if (head<tail){
    n=fila[head];
    cout << "elemento retirado: " << n;
    getch();
  }
  else {
    head--;
    cout << "nao tem elementos p desenfileirar";
    getch();
  }
}

void mostrafila(){
  int i;
  for (i=0; i<max; i++){
    cout << "\n\nfila[" <<i <<"] = " << fila[i];
    getch();
  }
}

void limpafila(){
  int i;
  head=-1;
  tail=0;
  for (i=0; i<max; i++)
    fila[i]=0;
}

int main(){
  int i, head, tail;
  int fila[5];
  enfileira();
  enfileira();
  enfileira();
  enfileira();
  enfileira();
  enfileira();
  mostrafila();
  desenfileira();
  limpafila();
  mostrafila();
  getch();
}

