#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
 setlocale(LC_ALL, "Portuguese");
 float pagar;
 int code,n;
 printf("Coloque o código do produto");
 printf("\nCachorro quente (100) \nBauru simples (101) \nBauru com ovo (102) \nHamburguer (103) \nCheeseburguer (104) \nSuco (105) \nRefrigerante (106) \n");
 scanf("%i", &code);
 printf("Coloque a quantidade: ");
 scanf("%i", &n);	
 
 switch(code)
 {
 	case 100:
 	printf("Total a pagar: R$%.2f", (1.20*n));
 	break;
		 
	case 101:
	printf("Total a pagar: R$%.2f", (1.30*n));
 	break;
		 
	case 102:
	printf("Total a pagar: R$%.2f", (1.50*n));
 	break;
	 
	case 103:
	printf("Total a pagar: R$%.2f", (1.20*n));
 	break;
	 
	case 104:
	printf("Total a pagar: R$%.2f", (1.70*n));
 	break;
	 
	case 105:
	printf("Total a pagar: R$%.2f", (2.20*n));
 	break;
 	
 	case 106:
 	printf("Total a pagar: R$%.2f", (1*n));
 	break;	
 }
}

