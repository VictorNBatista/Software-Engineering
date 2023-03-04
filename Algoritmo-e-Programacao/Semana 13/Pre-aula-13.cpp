#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>

main()
{
 setlocale(LC_ALL, "Portuguese");
 float h,b,area;
 printf("Digite o valor da altura: ");
 scanf("%f",&h);
 printf("Digite o valor da base: ");
 scanf("%f",&b);
 
 while(h>0 && b>0)
 {
 	area = (b*h)/2;
	printf("O valor da área do triângulo é: %.2f\n",area);
	printf("\nDigite o valor da altura: ");
 	scanf("%f",&h);
 	printf("Digite o valor da base: ");
 	scanf("%f",&b);	
 }
 
 printf("\n\nO valor digitado é inválido");
}

