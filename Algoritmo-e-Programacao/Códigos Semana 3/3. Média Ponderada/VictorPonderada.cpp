#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
setlocale(LC_ALL,"Portuguese");
// Declara��o das Vari�veis
   float a, b, c, pa, pb, pc;
// Entrada de Dados
   printf("Digite a 1� nota: ");
   scanf("%f" ,&a);
   printf("Digite a 2� nota: ");
   scanf("%f" ,&b);
   printf("Digite a 3� nota: ");
   scanf("%f" ,&c);
   printf("Digite o peso da 1� nota: ");
   scanf("%f" ,&pa);
   printf("Digite o peso da 2� nota: ");
   scanf("%f" ,&pb);
   printf("Digite o peso da 3� nota: ");
   scanf("%f" ,&pc);
// Processamento de Dados
// Sa�da de Dados
   printf("\n\t A m�dia ponderada �: %.2f", ((a*pa)+(b*pb)+(c*pc))/(pa+pb+pc));   
}

