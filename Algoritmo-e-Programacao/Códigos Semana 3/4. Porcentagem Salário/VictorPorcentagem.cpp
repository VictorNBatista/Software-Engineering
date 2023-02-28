#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
setlocale(LC_ALL,"Portuguese");
// Declaração de Variáveis
   float s;
// Entrada de Dados
   printf("Digite seu salário atual: ");
   scanf("%f" ,&s);
//Processamento
//Saída de Dados
   printf("\n\t Seu novo salário será de: %.2f", (s+(s*0.25)));   
}

