#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>

int n(int x);

main()
{
 setlocale(LC_ALL, "Portuguese");
int x, resultado;

printf("Digite o valor desejado: ");
scanf("%i",&x);
resultado = n(x);
printf("%i",resultado);
}

int n(int x){
	if(x<0)
	return 0;
	else
	return 1;
}

