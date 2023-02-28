#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
setlocale(LC_ALL,"Portuguese");
// Declaração das Variáveis
   float a, b, c, pa, pb, pc;
// Entrada de Dados
   printf("Digite a 1ª nota: ");
   scanf("%f" ,&a);
   printf("Digite a 2ª nota: ");
   scanf("%f" ,&b);
   printf("Digite a 3ª nota: ");
   scanf("%f" ,&c);
   printf("Digite o peso da 1ª nota: ");
   scanf("%f" ,&pa);
   printf("Digite o peso da 2ª nota: ");
   scanf("%f" ,&pb);
   printf("Digite o peso da 3ª nota: ");
   scanf("%f" ,&pc);
// Processamento de Dados
// Saída de Dados
   printf("\n\t A média ponderada é: %.2f", ((a*pa)+(b*pb)+(c*pc))/(pa+pb+pc));   
}

