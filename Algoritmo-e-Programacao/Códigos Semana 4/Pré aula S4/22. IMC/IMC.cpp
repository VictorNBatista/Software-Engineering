#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
 setlocale(LC_ALL, "Portuguese");
 float h,p,IMC;
 printf("Digite o seu peso: ");
 scanf("%f",&p);
 printf("Digite a sua altura: ");
 scanf("%f",&h);
 
 IMC= (p/(h*h));
 
 printf("\n\tSeu IMC é: %.1f",IMC);
 
 if(IMC<=18.5)
 	printf("\n\tAbaixo do peso");
 else if(IMC>18.5 && IMC<=24.9)
 	printf("\n\tSaudável");
 else if(IMC>24.9 && IMC<=29.9)
 	printf("\n\tPeso em excesso");
 else if(IMC>29.9 && IMC<=34.9)
 	printf("\n\tObesidade Grau 1");
 else if(IMC>34.9 && IMC<=39.9)
 	printf("\n\tObesidade Grau 2 (Severa)");
 else
 	printf("\n\tObesidade Grau 3 (Mórbida)");
}

