#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
setlocale(LC_ALL,"Portuguese");
  float d, t;
  printf("Digite aqui o valor do depósito: ");
  scanf("%f",&d);
  printf("Valor da taxa: ");
  scanf("%f" ,&t);
  
  printf("\n\t O seu rendimento é de: %.2f", (d*t/100));
  printf("\n\t O momante final é de: %.2f", (d+(d*t/100)));
}

