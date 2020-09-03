/* Laboratorio de Linguagem de Programacao I
   Curso Tecnico de Informatica e Curso Tecnico de Redes de Comp.
   Prof. Gilmar M. Grossi - CEFET-MG
   O objetivo deste programa e' gerar um vetor com max elementos
   inteiros de 0 a lim aleatoriamente. Imprime a hora do sistema,
   ordena este vetor e torna a imprimir a hora do sistema. Permi-
   tindo assim avaliar a eficiencia de diferentes metodos de or-
   denacao.                                                       */

#include <constream.h>
#include <dos.h>
#include <stdio.h>
#include <stdlib.h>

// --------------- Define constantes globais para parametrizar o programa
#define max 5000
#define lim 1000

// --------------- Define vetor global. Porque ? Quais as alternativas ?
int vet[20000];

// --------------- Mostra hora do sistema na tela
void hora(void) {
  struct  time t;

  gettime(&t);
  printf("A hora e': %2d:%02d:%02d.%02d\n",
	 t.ti_hour, t.ti_min, t.ti_sec, t.ti_hund);
}

// --------------- Calcula a diferenca de tempo
void TempoGasto(struct time start, struct time end) {
  unsigned char h, m, s, s100;
  unsigned long s100start, s100end, aux;
  // ----- converte os tempos de inicio e fim para centesimo de segundo
  s100start =(unsigned long)start.ti_hund;
  s100start+=(unsigned long)start.ti_sec*100;
  s100start+=(unsigned long)start.ti_min*60*100;
  s100start+=(unsigned long)start.ti_hour*60*60*100;
  s100end   =(unsigned long)end.ti_hund;
  s100end  +=(unsigned long)end.ti_sec*100;
  s100end  +=(unsigned long)end.ti_min*60*100;
  s100end  +=(unsigned long)end.ti_hour*60*60*100;
  // ----- calcula a diferenca de tempo em centesimos de segundo
  aux=s100end-s100start;
  s100=(unsigned char)(aux % 100);       // centesimos de segundo
  aux=(aux-(unsigned long)s100)/100;     // segundos totais
  s=(unsigned char)(aux % 60);           // segundos
  aux=(aux-(unsigned long)s)/60;         // minutos totais
  m=(unsigned char)(aux % 60);           // minutos
  h=(aux-(unsigned long)m)/60;           // horas
  // ----- mostra duracao do loop
  printf("O tempo gasto foi: %2d:%02d:%02d.%02d\n",
	 h, m, s, s100);
}

// --------------- Preenche vetor com numeros randomicos
void Gera(int v[max], int m) {
  int i;
  randomize();
  for (i=1; i<=m; i++)
    v[i]=random(lim);
}

// --------------- Mostra 20 numeros do vetor na tela de cada vez
//                 ate ser teclado esc
void Mostra(int v[max], int m) {
  int i;
  char ch;
  clrscr();
  for (i=1; i<=m; i++) {
    if ((i % 20)==0) {
      cout << endl;
      ch=getch();
      if (ch==27)
	return;
    }
    cout << v[i] << endl;
  }
//  return 27; // retorna codigo ASCII do ESC
}

// --------------- Verifica se vetor esta' Ordenado
void VerificaOrdenacao(int v[max], int m) {
  int i;
  unsigned char ok=1;
  for (i=1; i<=(m-1); i++)
    if (v[i]>v[i+1]) {
      ok=0;
      cout << "i=" << i << "v[i]=" << v[i] << "  v[i+1]=" << v[i+1] << endl;
    }
  if (ok) {
    cout << "Vetor ordenado!" << endl;
    cout << "v[0]=" << v[0] << " v[19999]=" << v[19999] << endl;
  }
  else
    cout << "Vetor desordenado!" << endl;
}

// --------------- Ordena vetor em ordem crescente pelo metodo da Bolha
void BolhaCrescente(int v[max], int m) {
  int i,j;
  int aux;
  for (i=1; i<=(m-1); i++)
    for (j=(i+1); j<=m; j++)
      if (v[j]<v[i]) {
	aux=v[i];
	v[i]=v[j];
	v[j]=aux;
      }
}

// --------------- Ordena vetor em ordem crescente pelo metodo da Selecao
void SelecaoCrescente(int v[max], int m) {
  int i, j, min, aux;
  for (i=1; i<=(m-1); i++) {
    min = i;
    for (j=(i+1); j<=m; j++) {
      if(v[j]<v[min]) {
	min = j;
      }
    }
    if (i!=min) {
      aux=v[i];
      v[i]=v[min];
      v[min]=aux;
    }
  }
}

// --------------- Ordena vetor em ordem crescente pelo metodo da Insercao
void InsercaoCrescente(int v[max], int m) {
  int i, j, chave;

  for (j=1; j<=m; j++) {
    chave=v[j];
    i=j-1;
    while (i>=0 && v[i]>chave) {
      v[i+1]=v[i];
      i--;
    }
    v[i+1]=chave;
  }
}

// --------------- Ordena vetor em ordem crescente por Shell Sort
void ShellSort(int v[max], int m) {
  int i, j, value;
  int gap=1;
  do {
    gap=3*gap+1;
  } while (gap<m);
  do {
    gap/=3;
    for (i=gap; i<=m; i++) {
      value=v[i];
      j=i-gap;
      while (j>=0 && value<v[j]) {
	v[j+gap]=v[j];
	j-=gap;
      }
      v[j+gap]=value;
    }
  } while (gap>1);
}

// --------------- Ordena vetor em ordem crescente por Quick Sort
void swap(int* a, int* b) {
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

int partition(int vec[], int left, int right) {
  int i, j;

  i = left;
  for (j = left + 1; j <= right; ++j) {
    if (vec[j] < vec[left]) {
      ++i;
      swap(&vec[i], &vec[j]);
    }
  }
  swap(&vec[left], &vec[i]);

  return i;
}

void qs(int vec[], int left, int right) {
  int r;

  if (right > left) {
    r = partition(vec, left, right);
    qs(vec, left, r - 1);
    qs(vec, r + 1, right);
  }
}

void QuickSort(int v[max], int m) {
  qs(v, 0, m);
}

// --------------- Ordena vetor em ordem crescente por Heap Sort
//                 Versao mais eficiente do Heap Sort
// ----- Recebe um vetor v[1..n] e transforma o vetor em um max-heap

void constroi_heap (int v[], int n) {
  int m, f, t;
  for (m=1; m<n; ++m) {
    f=m+1;
    while (f>1 && v[f/2]<v[f]) {
      t=v[f/2], v[f/2]=v[f], v[f]=t;
      f=f/2;
    }
  }
}

// Rearranja os elementos do vetor v[1..n]
// de modo que fiquem em ordem crescente
// ----- Bottom_up_heapsort
void HeapSort (int v[max], int n) {
  int m, f, maior, t;
  constroi_heap (v, n);
  for (m=n; m>1; --m) {
    maior=v[1];
    f=2;
    while (f<=m) {
      if (f<m && v[f]<v[f+1]) ++f;
      v[f/2]=v[f];
      f*=2;
    }
    f=f/2;
    if (f<m) {
      t=v[f], v[f]=v[m], v[m]=t;
      while (f>1 && v[f/2]<v[f]) {
	t=v[f], v[f]=v[f/2], v[f/2]=t;
	f=f/2;
      }
    }
    v[m]=maior;
  }
}

// --------------- Programa Principal
void main(void) {
  int i;
  char ch;
  struct time inicio, fim;
  clrscr();
  cout << endl;
  // ----- Preenche vetor com numeros randomicos
  Gera(vet, max);
  // ----- Mostra vetor desordenado na tela
  Mostra(vet, max);
  // ----- Mostra a hora do sistema
//  hora();
  // ----- pega relogio na entrada
  gettime(&inicio);
  // ----- Ordena vetor
//  BolhaCrescente(vet, max);
//  SelecaoCrescente(vet, max);
//  InsercaoCrescente(vet, max);
//  ShellSort(vet, max);
//  HeapSort(vet, max);
  QuickSort(vet, max);
  // ----- pega relogio na saida
  gettime(&fim);
  // ----- Mostra vetor ordenado na tela
  Mostra(vet, max);
  VerificaOrdenacao(vet, max);
  // ----- Mostra a hora do sistema
//  hora();
  // ----- Mostra o tempo gasto
  TempoGasto(inicio, fim);
  // ----- Despede e termina o programa
  cout << "Tecle <enter> para terminar" << endl;
  getch();
  exit(0);
}
