#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
setlocale(LC_ALL, "Portuguese");
int a,b,c,op;
float conta,delta,x1,x2;

printf("Qual operação deseja realizar?\n1- Calcular área do triângulo\n2- Ordenar 3 valores de forma crescente\n3- Ordenar 3 valores de forma decrescente\n4- Encontrar raízes de uma equação de 2º grau\n");
scanf("%i",&op);
switch(op){
	case 1:
			printf("Cálculo da área de um triângulo\n\nDigite o valor da base: ");
			scanf("%i",&a);
			printf("Digite o valor da altura: ");
			scanf("%i",&b);
			conta=(a*b)/2;
			printf("\nO valor da área do triângulo é: %.2fm²",conta);
			break;
		
	case 2:
		printf("Ordenamento crescente dos valores\n\nDigite o primeiro valor: ");
		scanf("%i",&a);
		printf("Digite o segundo valor: ");
		scanf("%i",&b);
		printf("Digite o terceiro valor: ");
		scanf("%i",&c);
		
		if(a<b && a<c)
		{
			if(b<c)
			printf("A ordem correta é: %i, %i, %i",a,b,c);
			else
			printf("A ordem correta é: %i, %i, %i",a,c,b);
		}
		else if(b<a && b<c)
		{
			if(a<c)
			printf("A ordem correta é: %i, %i, %i",b,a,c);
			else
			printf("A ordem correta é: %i, %i, %i",b,c,a);
		}
		else if(c<b && c<a)
		{
			if(b<a)
			printf("A ordem correta é: %i, %i, %i",c,b,a);
			else
			printf("A ordem correta é: %i, %i, %i",c,a,b);
		}
		break;	
		
	case 3:
		printf("Ordenamento decrescente dos valores\n\nDigite o primeiro valor: ");
		scanf("%i",&a);
		printf("Digite o segundo valor: ");
		scanf("%i",&b);
		printf("Digite o terceiro valor: ");
		scanf("%i",&c);
		
		if(a>b && a>c)
		{
			if(b>c)
			printf("A ordem correta é: %i, %i, %i",a,b,c);
			else
			printf("A ordem correta é: %i, %i, %i",a,c,b);
		}
		else if(b>a && b>c)
		{
			if(a>c)
			printf("A ordem correta é: %i, %i, %i",b,a,c);
			else
			printf("A ordem correta é: %i, %i, %i",b,c,a);
		}
		else if(c>b && c>a)
		{
			if(b>a)
			printf("A ordem correta é: %i, %i, %i",c,b,a);
			else
			printf("A ordem correta é: %i, %i, %i",c,a,b);
		}
		break;
		
	case 4:
		printf("Raízes de uma equação de 2º grau\n");
		printf("\nDigite o valor de A: ");
		scanf("%i",&a);
		printf("\nDigite o valor de B: ");
		scanf("%i",&b);
		printf("\nDigite o valor de C: ");
		scanf("%i",&c);
		
		delta= pow(b,2) - (4*a*c);
		if(delta>=0)
		{
		x1=(-b+sqrt(delta))/(2*a);
		x2=(-b-sqrt(delta))/(2*a);
		printf("As raízes encontradas são: X1=%.2f e X2=%.2f",x1,x2);
		}else
		printf("Raízes inexistentes");
		break;
}
}

