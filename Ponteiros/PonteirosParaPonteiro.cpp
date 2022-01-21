#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv)
{
	int x = 10; 
	int *p = &x;
	int **p1 = &p;
	
	printf("\n\n --- Imprimindo as Referencias --- \n\n");
	
	printf(" p1: %d \n", p1);//&p1
	printf(" *p1: %d \n", *p1);//&x
	printf(" **p1: %d \n", **p1);//x
	
	printf("\n\n");
	system("pause \n");
}