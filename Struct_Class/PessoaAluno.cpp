#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

class Pessoa{
	protected:
		char nome[100];
		char cpf[14];
		int dataNasc;
};
class Aluno : Pessoa{
	private:
		int RA;
    public:
    	Aluno(){
			
		}
    	int pegaRA(){ 
			return RA; 
		}
		void gravaNomeAluno(char* nomeAluno){
			strcpy(nome, nomeAluno);
		}
		char* pegaNomeAluno(){
			return nome;
		}
};

int main(int argc, char** argv)
{
	Aluno a1;
	a1.gravaNomeAluno("Vinicius");
	cout << "nome Aluno: " <<  a1.pegaNomeAluno();
}