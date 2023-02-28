#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
setlocale(LC_ALL,"Portuguese");
float lb,as,ef,nf;
printf("Nota Trabalho laboratório: ");
scanf("%f",&lb);
printf("Nota Avaliação Semestral: ");
scanf("%f",&as);
printf("Nota Exame Final: ");
scanf("%f",&ef);

nf = (((lb*2)+(as*3)+(ef*5))/10);

if(0 < nf && nf <= 2.9)
{
	printf("\n\t Sua nota final é: %.1f", nf);
	printf("\n\t Você está reprovado");
}
else if(3 < nf && nf <= 4.9)
{
	printf("\n\t Sua nota final é: %.1f", nf);
	printf("\n\t Você está de recuperação");
}
else
{
	printf("\n\t Sua nota final é: %.1f", nf);
	printf("\n\t Você está aprovado");
}
}

