#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
  setlocale(LC_ALL, "Portuguese");
  
  float n1,n2,ma;
  printf("Digite a primeira nota: ");
  scanf("%f",&n1);
  printf("Digite a segunda nota: ");
  scanf("%f",&n2);
  
  ma = (n1+n2)/2;
  
  if(ma < 40)
  {
  	printf("\n\t Sua média é: %.1f", ma);
  	printf("\n\t Você está reprovado '-'");
  }
  else if(40 <= ma && ma < 70)
  {
  	printf("\n\t Sua média é: %.1f", ma);
  	printf("\n\t É necessário fazer um exame");
  }
  else
  {
  	printf("\n\t Sua média é: %.1f", ma);
  	printf("\n\t Prabéns!!! Você está aprovado");
  }
}

