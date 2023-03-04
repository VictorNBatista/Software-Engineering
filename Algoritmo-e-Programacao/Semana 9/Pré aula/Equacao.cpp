#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>

main()
{
 setlocale(LC_ALL, "Portuguese");
 int y,x;
 for(x=1;x<=10;x++)
 {
 	y = x+2;
 	printf("Resultado da equação %i é: %i\n",x,y);
 }
}

