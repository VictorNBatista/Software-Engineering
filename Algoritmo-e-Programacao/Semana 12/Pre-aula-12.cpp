#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>

main()
{
 setlocale(LC_ALL, "Portuguese");
 int ano;
 float percent, salario;
 
 printf("Digite o ano atual: ");
 scanf("%i",&ano);
 salario = 1015;
 percent = 0.015;
 
 for(int c=2007; c<=ano; c++)
 {
 	percent = 2 * percent;
 	printf("\nPercentual é: %.2f",percent);
 	salario = salario + (salario*percent);
 	printf("\nSalário de %i é: %.2f\n",c,salario);
 }
}

