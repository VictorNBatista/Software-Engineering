#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
setlocale(LC_ALL,"Portuguese");
   float sb;
   printf("Digite aqui seu salário base: ");
   scanf("%f",&sb);
   
   printf("\n\t Seu salário final é de: %.2f", ((sb+(sb*0.05)-(sb*0.07))));
}

