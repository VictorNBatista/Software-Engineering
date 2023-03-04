#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>

main()
{
 setlocale(LC_ALL, "Portuguese");
 float juros,cap,tax,dias;
 for(int c=0;c<20;c++)
 {
 	printf("EMPRÉSTIMO NÚMERO %i",c+1);
 	printf("\nInforme o capital: ");
 	scanf("%f",&cap);
 	printf("Informe o valor da taxa: ");
 	scanf("%f",&tax);
 	printf("Informe o número de dias: ");
 	scanf("%f",&dias);
 	juros = (cap*tax*dias)/365;
 	printf("O juros simples do impréstimo na taxa anual é de: %.2f\n\n",juros);
 }
}

