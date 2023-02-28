#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
 setlocale(LC_ALL, "Portuguese");
 
 float venda,a1,a2,a3,a4,a5,a6;
 printf("Digite o valor da venda: ");
 scanf("%f", &venda);
 
 a1 = (700 + (venda*0.16));
 a2 = (650 + (venda*0.14));
 a3 = (600 + (venda*0.14));
 a4 = (550 + (venda*0.14));
 a5 = (500 + (venda*0.14));
 a6 = (400 + (venda*0.14));
 
 if(venda>=100000)
 	printf("\n\t Sua comissão é: R$%.2f",a1);
 else if(venda<100000 && venda>=80000)
 	printf("\n\t Sua comissão é: R$%.2f",a2);
 else if(venda<80000 && (venda>=60000))
 	printf("\n\t Sua comissão é: R$%.2f",a3);
 else if(venda<60000 && venda>=40000)
 	printf("\n\t Sua comissão é: R$%.2f",a4);
 else if(venda<40000 && venda>=20000)
 	printf("\n\t Sua comissão é: R$%.2f",a5);
 else if(venda<20000)
 	printf("\n\t Sua comissão é: R$%.2f",a6);	 		 	
}

