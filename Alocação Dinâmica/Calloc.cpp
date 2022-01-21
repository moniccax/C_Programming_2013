#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv)
{
	int *p, *p1;
	p = (int *) malloc(5*sizeof(int));
	p1 = (int *) calloc(5,sizeof(int));
	printf("    CALLOC \t\t MALLOC \n");

	for(int i = 0; i<5; i++){
		printf("  p1[%d]: = %d \t",i,p1[i]);
		printf("     p[%d]: = %d \n",i,p[i]);
	}
	
	free(p);
	free(p1);
	
	return 0;
}
