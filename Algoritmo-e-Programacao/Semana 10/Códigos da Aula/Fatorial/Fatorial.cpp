#include<stdio.h>
#include<locale.h>
#include<math.h>

main()
{

	setlocale(LC_ALL,"Portuguese");
	int n, c, fat, aux;
	c = 0;
	fat = 1;
	printf("Entre com o n�mero que ser� fatorado: ");
	scanf("%i",&n);
	aux = n;
	
	while(c<n)
	{
	fat = fat*aux;
	c++;
	aux = n-c;
	}
	printf("\nO fatorial de %i �: %i",n,fat);
}



