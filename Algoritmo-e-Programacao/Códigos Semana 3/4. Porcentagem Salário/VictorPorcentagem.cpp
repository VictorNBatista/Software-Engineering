#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
setlocale(LC_ALL,"Portuguese");
// Declara��o de Vari�veis
   float s;
// Entrada de Dados
   printf("Digite seu sal�rio atual: ");
   scanf("%f" ,&s);
//Processamento
//Sa�da de Dados
   printf("\n\t Seu novo sal�rio ser� de: %.2f", (s+(s*0.25)));   
}

