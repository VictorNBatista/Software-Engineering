#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
setlocale(LC_ALL,"Portuguese");
float a, b;
printf("Digite o primeiro n�mero: ");
scanf("%f", &a);
printf("Digite o segundo n�mero: ");
scanf("%f", &b);

if(a>b)
{
	printf("\n\t O n�mero maior �: %.f", a);
}
else
{
	printf("\n\t O n�mero maior �: %.f", b);
}
}

