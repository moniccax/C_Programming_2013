#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
	int x, *p;
	
	x = 10;
	p = &x;
	
	printf("\n\n ----------------p = &x;\n");
	
	printf(" x = %d\n", x);
	printf(" &x = %d\n", &x);
	printf(" p = %d\n", p);
	printf(" *p = %d\n", *p);
	
	*p = 12;
	
	printf(" ----------------*p = 12;\n");
		
	printf(" x = %d\n", x);
	printf(" &x = %d\n", &x);
	printf(" p = %d\n", p);
	printf(" *p = %d\n", *p);
	
	
	printf("\n\n");
	system("pause \n");
}