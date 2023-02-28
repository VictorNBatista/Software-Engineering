#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
setlocale(LC_ALL,"Portuguese");
float s, e;
printf("Digite seu salário: ");
scanf("%f", &s);
printf("Digite o valor da prestação do empréstimo: ");
scanf("%f", &e);

if(e > s*0.2)
{
	printf("\n\t Empréstimo não aprovado");
}
else 
{
	printf("\n\t O seu empréstimo foi efetivado");
}
}

