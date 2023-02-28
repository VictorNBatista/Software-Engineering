#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
setlocale(LC_ALL,"Portuguese");
float a;
printf("Digite o número natural: ");
scanf("%f", &a);

if(a >= 0)
{
printf("\n\t O valor da raiz é: %.2f", sqrt(a));
}
else
{
	printf("\n\t Este número não é válido");
}
}

