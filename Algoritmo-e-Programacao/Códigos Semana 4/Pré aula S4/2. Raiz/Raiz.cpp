#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
setlocale(LC_ALL,"Portuguese");
float a;
printf("Digite o n�mero natural: ");
scanf("%f", &a);

if(a >= 0)
{
printf("\n\t O valor da raiz �: %.2f", sqrt(a));
}
else
{
	printf("\n\t Este n�mero n�o � v�lido");
}
}

