#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
setlocale(LC_ALL,"Portuguese");
// Declara��o das Vari�veis
   int a, b, c, d, soma;
// Entrada de Dados
   printf("Digite o 1� valor inteiro: ");
   scanf("%i" ,&a);
   printf("Digite o 2� valor inteiro: ");
   scanf("%i" ,&b);
   printf("Digite o 3� valor inteiro: ");
   scanf("%i" ,&c);
   printf("Digite o 4� valor inteiro: ");
   scanf("%i" ,&d);
// Processamento de Dados
   soma = (a+b+c+d);
// Sa�da de Dados
printf("\n\t0s Valores digitados s�o: %i\n %i\n %i\n %i\n",a,b,c,d);
printf("\n\t A soma �: %i",soma);    
}

