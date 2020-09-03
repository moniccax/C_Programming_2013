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
#define max 100
#define lim 10

// --------------- Define vetor global. Porque ? Quais as alternativas ?
int vet[max];

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
      cout << "i=" << i << " - " << v[i] << " - " << v[i+1] << endl;
      getch();
    }
  if (ok)
    cout << "Vetor ordenado!" << endl;
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
  BolhaCrescente(vet, max);
//  SelecaoCrescente(vet, max);
//  InsercaoCrescente(vet, max);
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
