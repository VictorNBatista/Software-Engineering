#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
setlocale(LC_ALL,"Portuguese");
// Declaração das Variáveis
   int a, b, c, d, soma;
// Entrada de Dados
   printf("Digite o 1º valor inteiro: ");
   scanf("%i" ,&a);
   printf("Digite o 2º valor inteiro: ");
   scanf("%i" ,&b);
   printf("Digite o 3º valor inteiro: ");
   scanf("%i" ,&c);
   printf("Digite o 4º valor inteiro: ");
   scanf("%i" ,&d);
// Processamento de Dados
   soma = (a+b+c+d);
// Saída de Dados
printf("\n\t0s Valores digitados são: %i\n %i\n %i\n %i\n",a,b,c,d);
printf("\n\t A soma é: %i",soma);    
}

