#include <constream.h>
#include <stdio.h>

#define max 6

/*void Bolha(int v[], int n){
  int temp = 0;
  while(n){
    for (int b = 0; (b+1) < n; b++){
      if (v[b+1] < v[b]) {
	temp = v[b];
	v[b] = v[b+1];
	v[b+1] = temp;
      }
    }
    n--;
  }
  for(int i=0; i<max; i++)
    cout << v[i] << " - " ;
} */

void Bolha(int v[], int n){
  int temp = 0;
  for(int a=1; a<n; ++a)
    for (int b = n-1; b>=a; --b)
      if (v[b-1] > v[b]) {
	temp = v[b-1];
	v[b-1] = v[b];
	v[b] = temp;
      }
  for(int i=0; i<max; i++)
    cout << v[i] << " - " ;
}

void Selecao(int v[], int n) {
  int c, t;
  //while (n){

  // for (int j=n-1; j>0; j--){
    for(int a=0; a<n-1; ++a){
    c=a;
    t=v[a];
    for (int i=a+1; i < n; ++i)
      if (v[i] < t){
	c=i;
	t=v[i];
      }
  //  n--;
   // v[temp]=v[n];
   // v[n]=maior;
   v[c]=v[a];
   v[a]=t;
  }

  for(int x=0; x<max; x++)
    cout << v[x] << " - " ;
}

void Insercao(int v[], int n){
   int aux, j;
   for (int i=1; i<=(n-1); i++){
     j=i;
     while ((v[j] < v[j-1])&&(j>0)){
       aux = v[j];
       v[j] = v[j-1];
       v[j-1]=aux;
       j=j-1;
     }
   }
   for(int a=0; a<max; a++)
    cout << v[a] << " - " ;
}

void Shell(int v[], int n){
  int j, valor;
  int gap = 1;
  do {
    gap = 3*gap+1;
  } while (gap<n);
  do {
    gap=(gap/3);
    for (int i=0; i<n; i++){
      valor = v[i];
      j = i-gap;
      while(j>=0 && valor<v[j]) {
	v[j+gap] = v[j];
	j=j-gap;
      }
      v[j+gap] = valor;
    }
  } while(gap>1);
  for(int a=0; a<max; a++)
    cout << v[a] << " - " ;
}


int main(){
  int v[max] = {67, 34, 32, 11, 43, 23};

  //Bolha(v, max);
  Selecao(v, max);
  //Insercao(v, max);
  //Shell(v, max);
  getch();
  return 0;
}

