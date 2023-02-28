#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
 setlocale(LC_ALL, "Portuguese");
 float antigo,a1,a2,a3,res;
 printf("Digite o preço antigo: ");
 scanf("%f", &antigo);
 
 a1 = (antigo + (antigo*0.05));
 a2 = (antigo + (antigo*0.10));
 a3 = (antigo + (antigo*0.15));
 
 if(antigo<=50)
 	printf("\n\t O novo preço é: R$%.2f", res = a1);
 else if(antigo>50 && antigo<=100)
 	printf("\n\t O novo preço é: R$%.2f", res = a2);
 else if(antigo>100)
 	printf("\n\t O novo preço é: R$%.2f", res = a3);

 if(res<=80)
 	printf("\n\t Barato!!!");
 else if(res>80 && res<=120)
 	printf("\n\t Normal");
 else if(res>120 && res<=200)
 	printf("\n\t Caro!!!");
 else if(res>200)
 	printf("\n\t Muito Caro!!!");
}
