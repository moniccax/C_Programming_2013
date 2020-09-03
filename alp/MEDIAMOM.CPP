#include <iostream>
#include <stdio>
#include <conio>
#include <constream>

int main () {
  int nota, q_alunos=0, total=0, t_alunos=0;
  float media=0;
  clrscr();
  cout << "\nQuantos alunos tem  na sala?";
  cin >> t_alunos;
  if(t_alunos<=50) {
    while (q_alunos<t_alunos){
      cout << "\nQual sua nota?";
      cin >> nota;
      total=total+nota;
      q_alunos=q_alunos+1;
    }
  else{
    cout << "\nO numero de alunos ultrapassa o limite permitido";
  }
   media=total/q_alunos;
  cout << "\nMedia geral da turma";
  return 0;
}