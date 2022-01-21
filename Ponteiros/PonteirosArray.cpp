#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv)
{
	int vet[5] = {1,2,3,4,5};
	int *p = vet;

	printf("\n --- Referencias do Vetor --- \n");
	
	printf("\n vet: %d \n", vet);
	printf(" &vet[0]: %d \n", &vet[0]);
    printf(" *p: %d \n", *p);
	
	printf("\n --- Imprimindo por referencia --- \n");
	
	printf("\n *(p+i)\n");
	for(int i = 0; i < 5; i++)
	{
	   printf(" %d,", *(p+i));	
	}
	printf("\n\n p[i]\n");
	for(int i = 0; i < 5; i++)
	{
	   printf(" %d,", p[i]);	
	}
	
	printf("\n\n --- Conteudo por referencia --- \n\n");
					
	printf("  vet[2]: %d \n", vet[2]);				
	printf(" *(vet+2): %d \n", *(vet+2));
	
	printf("\n --- Endereco --- \n\n");
					
	printf(" &vet[2]: %d \n", &vet[2]);				
	printf(" vet+2: %d \n", vet+2);
	
	printf("\n\n");
	system("pause \n");
}