#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct ponto
{
	int x, y;
};
int main(int argc, char** argv)
{
	printf("char: %d \n", sizeof(char));	
	printf("int: %d \n", sizeof(int));
	printf("float: %d \n", sizeof(float));
	printf("double: %d \n", sizeof(double));
	printf("struct %d \n", sizeof(struct ponto));
}