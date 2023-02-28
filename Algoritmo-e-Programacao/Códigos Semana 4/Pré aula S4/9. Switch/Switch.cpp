#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
 setlocale(LC_ALL, "Portuguese");
 int valor;
 printf("Digite um valor de 1 a 7: ");
 scanf("%i", &valor);
 
 switch (valor)
 {
 	case 1:
 	printf("\n\t Domingo");
	break;
	
	case 2:
	printf("\n\t Segunda");
	break;
	
	case 3:
	printf("\n\t Terça");
	break;
	
	case 4:
	printf("\n\t Quarta");
	break;
	
	case 5:
	printf("\n\t Quinta");
	break;
	
	case 6:
	printf("\n\t Sexta");
	break;
	
	case 7:
	printf("\n\t Sábado");
	break; 	
 }
}

