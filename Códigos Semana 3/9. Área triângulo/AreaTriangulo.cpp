#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
setlocale(LC_ALL,"Portuguese");
   float b, h;
   printf("Digite o valor da base: ");
   scanf("%f", &b);
   printf("Digite o valor da altura: ");
   scanf("%f", &h);
   
   printf("\n\t O valor da área do triângulo é: %.2f", (b*h/2));
}

