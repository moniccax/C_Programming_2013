#include <constream.h>

class retangulo {   //definicao da classe
  private: //geralmente contem dados e soh eh acessado p/ funcoes membros
    int base, altura; //membros de dados
  public:
    void init (int b, int h){  //funcao membro q inicializa os dados
      base=b;
      altura=h;
    }
  void retangulo:: printdata(){         //funcao membro q imprime os dados
      cout<<"\n\tBase = "<<base<<"\tAltura = "<<altura;
      cout<<"\tArea = "<<(base*altura);
    }
};

int main(){
  clrscr();
  retangulo x, y;  //objetos da classe retangulo
  x.init(5,3);
  y.init(10,6);

  x.printdata();
  y.printdata();

  getch();
  return 0;
}