#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
setlocale(LC_ALL,"Portuguese");
float sb;
   printf("Digite aqui seu sal�rio base: ");
   scanf("%f",&sb);
   
   printf("\n\t Seu sal�rio final � de: %.2f", ((sb+50-(sb*0.1))));
}

