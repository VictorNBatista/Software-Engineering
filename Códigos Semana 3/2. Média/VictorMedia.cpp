#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
setlocale(LC_ALL,"Portuguese");
// Declara��o das Vari�veis
   float a, b, c;
// Entrada de Dados
   printf("Digite a 1� nota: ");
   scanf("%f" ,&a);
   printf("Digite a 2� nota: ");
   scanf("%f" ,&b);
   printf("Digite a 3� nota: ");
   scanf("%f" ,&c);
// Processamento de Dados
// Sa�da de Dados
printf("\n\t O valor da m�dia �: %.2f\n", ((a+b+c)/3));
}

