// ----- Inclui as bibliotecas necessarias
/*
   #include <alloc.h>
   #include <process.h>
*/
#include <stdlib.h> // exit
#include <constream.h> // cin e cout
int main(void) {
  int* id;
  id=(int*) malloc(sizeof(int));
  if (id==NULL) {
    cout << "Memoria Insuficiente para alocar um inteiro\n\n";
    exit (1);
  }
  clrscr();
  cout << endl;
  cout << "Testando alocacao dinamica" << endl;
  for (*id=1; *id<=10; (*id)++)
    cout << "I=" << *id << endl;
  cout << "Tecle <enter> para terminar" << endl;
  getch();
  free(id); //destroi id; desaloca sizeof(int) bytes
  return(0);
}
