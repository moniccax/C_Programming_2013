#include <constream.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream.h>

const int max=11;

int main(){
  float *x;
  x=new float;
  if (x==NULL){
    cout << "Memoria insuficiente";
    exit (1);
  }
  for (*x=1; *x<=10; (*x)++)
    cout <<  "x=" << *x << endl;
  delete (x);
  getch();

  int *y;
  y=new int[max];
  if (y==NULL){
    cout << "Memoria insuficiente";
    exit (1);
  }
  for (int i=1; i<=10; i++){
    y[i]=i;
    cout << "y=" << y[i] << endl;
  }
  getch();
  return 0;
}