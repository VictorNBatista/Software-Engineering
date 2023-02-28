#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
 setlocale(LC_ALL, "Portuguese");
 float km,l,kl;
 printf("Digite a quilometragem: ");
 scanf("%f",&km);
 printf("Digite a quantidade de gasolina gasta: ");
 scanf("%f",&l);
 
 kl = (km/l);
 
 if(kl<8)
 printf("\n\t Venda o carro!");
 else if(kl>=8 && kl<=14)
 printf("\n\t Econômico!");
 else if(kl>12)
 printf("\n\t Super Econômico!");
}

