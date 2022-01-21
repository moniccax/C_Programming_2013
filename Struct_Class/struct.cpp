#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

class Pessoa {
protected:
	char nome[100];
	char cor[14];
	int titulo;
	char torcida[10];


};
class Time : Pessoa {
private:
	int RA;
public:
	Aluno() {

	}
	int pegaRA() {
		return RA;
	}
	void gravaNomeAluno(char* nomeAluno) {
		strcpy(nome, nomeAluno);
	}
	char* pegaNomeAluno() {
		return nome;
	}


	Cor() {

	}
	
	void gravaNomeCor(char* nomeCor) {
		strcpy(cor, nomeCor);
	}
	char* pegaNomeCor() {
		return cor;
	}

	Titulo() {

	}

	void gravaNomeTitulo(char* nomeTitulo) {
		strcpy(titulo, nomeTitulo);
	}
	char* pegaNomeTitulo() {
		return titulo;
	}

	Torcida() {

	}
	
	void gravaNomeTitulo(char* nomeTorcida) {
		strcpy(torcida, nomeTorcida);
	}
	char* pegaNomeT() {
		return torcida;
	}


};

int main(int argc, char** argv)
{
	Time a[10];
	char anome;
	char acor;
	int atitulo;
	char atorcida;

	for (int i = 0; i < 10; i++) {
		cout << "nome: ";
		cin >> anome;
		cin >> a[i].gravaNomeAluno(anome);
		cout << "cor: ";
		cin >> acor;
		cin >> a[i].gravaNomeCor(cor);
		cout << "titulo: ";
		cin >> atitulo;
		cin >> a[i].gravaNomeTitulo(atitulo);
		cout << "atorcida: ";
		cin >> atitulo;
		cin >> a[i].gravaTorcida(atorcida);

	}




}