#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
setlocale(LC_ALL,"Portuguese");
   float r;
   printf("Digite o valor do raio: ");
   scanf("%f", &r);
   
   printf("\n\t O valor da �rea do tri�ngulo �: %.2f", (3.14*(r*r)));
}

