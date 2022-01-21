#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv)
{
	int *pvet[2];
	int x = 10, y[2] = {20, 30}; 
	pvet[0] = &x;
	pvet[1] = y;
	
	printf("\n --- Endereco --- \n\n");
					
	printf(" pvet[0]: %d \n", pvet[0]);//&x
	printf(" pvet[1]: %d \n", pvet[1]);//&y[0]
	
	printf("\n\n --- Valores --- \n\n");
	
	printf(" *pvet[0]: %d \n", *pvet[0]);//x
	printf(" pvet[1][1]: %d \n", pvet[1][1]);//y[1]
	
	printf("\n\n");
	system("pause \n");
}