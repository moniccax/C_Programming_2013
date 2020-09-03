/* Este programa foi apresentado como uma duvida pelos
   alunos Stela, Daniel e Thais em 13/06/2011.
   Ja funcionava. Apenas comentei e completei a ordem dos
   comandos para exercitar todas as formas de manipulacao de um
   ponteiro simples em relacao a um vetor.
*/
#include <constream.h>

int main(){

  int d[2]; //em um vetor o nome vale o endereco do 1o elemento
  int* p;   // ponteiro tipado para inteiro sabe o tamanho do elemento apontado
  void* v;  // ponteiro generico nao sabe o tamanho do que aponta
  d[0]=4;   // inicializa posicoes do vetor
  d[1]=3;
  d[2]=2;
  clrscr();
// --------------- Enderecos das variaveis e seus conteudos antes de apontar
  cout << "\n\tAntes de apontar\n";
  cout << "\n\td=" << d << " - d vale endereco do 1o elemento do vetor" ;
  cout << "\n\t&d=" << &d << " - &d vale o proprio d" ;
  cout << "\n\t*d=" << *d << " - *d conteudo da memoria apontada por d=d[0]=4";
  cout << "\n\n\tv=" << v << " - v vale um endereco (lixo) de lixo de memoria";
  cout << "\n\t&v=" << &v << " - endereco onde v fica na memoria" ;
// a linha abaixo da o erro "Not an allowed type"
//  cout << "\n\t*v=" << *v; // como nao sabe o tipo apontado nao aceita
  cout << "\n\n\tp=" << p << " - p vale um endereco de inteiro, no momento lixo";
  cout << "\n\t&p=" << &p << " - endereco onde p fica na memoria" ;
  cout << "\n\t*p=" << *p << " - conteudo da memoria apontada pelo lixo" ;
  getch();
//--------Apontando com referencia
  cout << "\n\n\t Apontando com referencia" << endl;
  v=&d;
// A linha abaixo da erro "Cannot convert int[2] * to int *"
//  p=&d;
  p=d; // Esta linha ou a de baixo funcionam a mesma coisa
//  p=(int*)v;
  cout << "\n\tDepois de v=&d e p=(int*)v" << endl;
  cout << "\n\td=" << d << " - Endereco de d";
  cout << "\n\tp=" << p << " - Endereco de d ja que p aponta d";
  cout << "\n\t&p=" << &p << " - Endereco de p";
  cout << "\n\t*p=" << *p << " - Valor apontado por p";
  cout << "\n\tv=" << v << " - Endereco de d ja que v aponta d";
  cout << "\n\t&v=" << &v << " - Endereco de v";
  cout << "\n\t*v=" << *(int*)v << " - Valor apontado por v";
  getch();
  clrscr();
// --------------- Ponteiro com operador []
  cout << "\n\tTestes com o operador []" << endl;
  cout << "\n\tp[0]=" << p[0];
  cout << "\n\tp[1]=" << p[1];
  cout << "\n\tp[2]=" << p[2];
  cout << "\n\t((int*)v)[0]=" << ((int*)v)[0];
  cout << "\n\t((int*)v)[2]=" << ((int*)v)[2];
  getch();
// --------------- Brincando com inteiro simples
  clrscr();
  int n=0;
  p=&n;
  v=&n;
  cout << "\n\tDepois de p=&n e v=&n";
  cout << "\n\tn=" << n << " - Valor de n";
  cout << "\n\t&n=" << &n << " - Endereco de n";
  cout << "\n\tp=" << p << " - Endereco de n ja que p aponta n";
  cout << "\n\tv=" << v << " - Endereco de n ja que v aponta n";
  cout << "\n\t*p=" << *p << " - Valor de n (mostra o conteudo de n) ";
  cout << "\n\t*(int*)v=" << *(int*)v << " - Valor de n (mostra o conteudo de n) ";

//-------Fim do programa
   getch();
   return 0;

}
