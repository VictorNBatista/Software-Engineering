#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
setlocale(LC_ALL,"Portuguese");
float a, b;
printf("Digite o primeiro número: ");
scanf("%f", &a);
printf("Digite o segundo número: ");
scanf("%f", &b);

if(a>b)
{
	printf("\n\t O número maior é: %.f", a);
}
else
{
	printf("\n\t O número maior é: %.f", b);
}
}

