#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
setlocale(LC_ALL,"Portuguese");
// Declaração de Variáveis
   float s, p;
// Entrada de Dados
   printf("Digite seu salário atual: ");
   scanf("%f" ,&s);
   printf("Digite a percentual de aumento: ");
   scanf("%f",&p);
//Processamento
//Saída de Dados
   printf("\n\t Seu salário era de: %.2f", s);
   printf("\n\t Seu aumento é de: %.2f", (s*p/100));
   printf("\n\t Seu novo salário será de: %.2f", (s+(s*p/100)));   
}

