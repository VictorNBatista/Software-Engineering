#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
 setlocale(LC_ALL, "Portuguese");
 float x,y,z;
 int md;
 printf("Escolha a média a ser calculada: \n Geométrica (1) \n Ponderada (2) \n Harmônica (3) \n Aritmética (4) \n");
 scanf("%i",&md);
 printf("Digite o valor de x: ");
 scanf("%f",&x);
 printf("Digite o valor de y: ");
 scanf("%f",&y);
 printf("Digite o valor de z: ");
 scanf("%f",&z);
 
 switch(md)
 {
 	case 1:
 	printf("\n\t O valor da média é: %.2f", (cbrt(x*y*z)));
	break;
	
	case 2:
	printf("\n\t O valor da média é: %.2f", ((x+2*y+3*z)/6));
	break;
	
	case 3:
	printf("\n\t O valor da média é: %.2f", (1/((1/x)+(1/y)+(1/z))));
	break;
	
	case 4:
	printf("\n\t O valor da média é: %.2f", ((x+y+z)/3));
	break;
 }
}

