#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
 setlocale(LC_ALL, "Portuguese");
 float a,b;
 int op;
 printf("Escolha uma opera��o: Adi��o(1) - Subtra��o(2) - Multiplica��o(3) - Divis�o(4): ");
 scanf("%i", &op);
 printf("Digite o primeiro valor: ");
 scanf("%f", &a);
 printf("Diite o segundo valor: ");
 scanf("%f", &b);
 
 switch(op)
 {
 	case 1:
 	printf("\n\t O resultado da adi��o �: %.2f", (a+b));
	break;
	
	case 2:
	printf("\n\t O resultado da subtra��o �: %.2f", (a-b));
	break;
	
	case 3:
	printf("\n\t O resultado da multiplica��o �: %.2f", (a*b));
	break;
	
	case 4:
	printf("\n\t O resultado da divis�o �: %.2f", (a/b));
	break;	
 }
}

