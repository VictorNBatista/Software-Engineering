#include<stdio.h>
#include<math.h>
#include<locale.h>

main(){
  setlocale(LC_ALL, "Portuguese");
  float n1,n2,n3,ma;
	printf("Digite a primeira nota: ");
	scanf("%f",&n1);
	printf("Digite a segunda nota: ");
	scanf("%f",&n2);
	printf("Digite a terceira nota: ");
	scanf("%f",&n3);
	
	ma = (n1+n2+n3)/3;
	
	if(ma < 60)
	{
		printf("\n\t Sua média é: %.2f", ma);
		printf("\n\t Você está reprovado '-'");
	}
	else
	{
	printf("\n\t Sua média é: %.2f", ma);
	printf("\n\t Parabéns!!! Você está aprovado");	
	}
}

