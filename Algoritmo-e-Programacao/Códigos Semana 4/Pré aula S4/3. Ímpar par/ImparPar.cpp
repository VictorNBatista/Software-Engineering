#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
setlocale(LC_ALL,"Portuguese");
int a;
printf("Digite um número inteiro: ");
scanf("%i", &a);

if(a % 2 == 0)
{
	printf("\n\t O número é par");
}
else
{
	printf("\n\t O número é ímpar");
}
}

