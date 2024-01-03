#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>

int square(int x);

main()
{
 setlocale(LC_ALL,"Portuguese");
 int i;
 for(i=1;i<=10;i++)
 	printf("[%d] ",square(i));
}
//*************************************
int square(int x)
{
	int res;
	res = pow(x,4);
	return res;
}

