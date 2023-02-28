#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
 setlocale(LC_ALL, "Portuguese");
 float a,b;
 int op;
 printf("Escolha uma operação: Adição(1) - Subtração(2) - Multiplicação(3) - Divisão(4): ");
 scanf("%i", &op);
 printf("Digite o primeiro valor: ");
 scanf("%f", &a);
 printf("Diite o segundo valor: ");
 scanf("%f", &b);
 
 switch(op)
 {
 	case 1:
 	printf("\n\t O resultado da adição é: %.2f", (a+b));
	break;
	
	case 2:
	printf("\n\t O resultado da subtração é: %.2f", (a-b));
	break;
	
	case 3:
	printf("\n\t O resultado da multiplicação é: %.2f", (a*b));
	break;
	
	case 4:
	printf("\n\t O resultado da divisão é: %.2f", (a/b));
	break;	
 }
}

