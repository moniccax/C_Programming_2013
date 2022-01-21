#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv)
{
	int *p;
	p = (int *) malloc(5*sizeof(int));
	if (p == NULL){
		printf("Erro: Sem memoria! \n");
		exit(1);
	}	
	for(int i = 0; i<5; i++){
		printf("Digite p[%d]: ",i);
		scanf("%d", &p[i]);
	}
	
	free(p);
	
	return 0;
}
