#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
setlocale(LC_ALL,"Portuguese");
float s, e;
printf("Digite seu sal�rio: ");
scanf("%f", &s);
printf("Digite o valor da presta��o do empr�stimo: ");
scanf("%f", &e);

if(e > s*0.2)
{
	printf("\n\t Empr�stimo n�o aprovado");
}
else 
{
	printf("\n\t O seu empr�stimo foi efetivado");
}
}

