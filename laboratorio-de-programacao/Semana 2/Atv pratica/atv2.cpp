#include<stdio.h>
#include<math.h>
#include<locale.h>

int soma(int x, int y);

main()
{
setlocale(LC_ALL,"Portuguese");
	int a,b,resultado;
	printf("Digite o primeiro valor: ");
	scanf("%i",&a);
	printf("Digite o segundo valor: ");
	scanf("%i",&b);
	resultado = soma(a,b);
	printf("O resultado da soma é: %i",resultado); 
}

int soma(int x, int y){
	return x+y;
}

