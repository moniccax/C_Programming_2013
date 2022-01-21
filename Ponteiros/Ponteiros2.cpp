#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
	int *p, *p1, x = 10, y = 20;
	char *c;

	printf(" ------------------- \n\n");			
	p = &x;
	printf(" *p = %d \n", *p);
	p1 = p;	
	printf(" *p1 = %d \n", *p1);

	//ERRADO!!!
	//float y = 20.0;
	//p1 = &y;
	
	printf("\n ------------------- \n\n");
	*p = 0x5DC;
	printf(" p = 0x5DC: %d \n", p);
	p++;
	printf(" p = p++: %d \n", p);
	p = p + 15;
	printf(" p = p + 15: %d \n", p);
	p = p - 2;
	printf(" p = p - 2: %d \n", p);
	
    printf("\n ------------------- \n\n");
    
	p = &x;
	p1 = &y;
	
	if (p == p1)
		printf("Ponteiros iguais \n");
	else
		printf("Ponteiros diferentes \n");	
	
					
	printf("\n\n");
	system("pause \n");
}