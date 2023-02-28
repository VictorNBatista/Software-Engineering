#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
setlocale(LC_ALL,"Portuguese");
// Declaração das Variáveis
   float a, b, c;
// Entrada de Dados
   printf("Digite a 1ª nota: ");
   scanf("%f" ,&a);
   printf("Digite a 2ª nota: ");
   scanf("%f" ,&b);
   printf("Digite a 3ª nota: ");
   scanf("%f" ,&c);
// Processamento de Dados
// Saída de Dados
printf("\n\t O valor da média é: %.2f\n", ((a+b+c)/3));
}

