#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
setlocale(LC_ALL,"Portuguese");
// Declara��o de Vari�veis
   float s, p;
// Entrada de Dados
   printf("Digite seu sal�rio atual: ");
   scanf("%f" ,&s);
   printf("Digite a percentual de aumento: ");
   scanf("%f",&p);
//Processamento
//Sa�da de Dados
   printf("\n\t Seu sal�rio era de: %.2f", s);
   printf("\n\t Seu aumento � de: %.2f", (s*p/100));
   printf("\n\t Seu novo sal�rio ser� de: %.2f", (s+(s*p/100)));   
}

