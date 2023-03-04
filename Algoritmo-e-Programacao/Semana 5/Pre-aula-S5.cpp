#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
setlocale(LC_ALL,"Portuguese");
int op;
float a,b,c;

printf("Digite o primeiro número: ");
scanf("%f",&a);
printf("Digite o segundo número: ");
scanf("%f",&b);
printf("Digite o terceiro número: ");
scanf("%f",&c);

printf("Escolha a operação desejada \n1. Mostre os valores em ordem crescente \n2. Mostre os valores em ordem decrescente \n3. Mostre a raiz quadrada do maior valor encontrado \n4. Mostre o menor valor encontrado elevado a 3ª potência \n");
scanf("%i",&op);

switch(op)
{
	case 1:
	if(a<b)
	{
 	if(b<c)
 	printf("\n\t A ordem crescente é: %.f - %.f - %.f", a,b,c);
 	else
 	printf("\n\t A ordem crescente é: %.f - %.f - %.f", a,c,b);
    }
 	else if(b<c)
 	{
 	if(c<a)
 	printf("\n\t A ordem crescente é: %.f - %.f - %.f", b,c,a);
 	else
 	printf("\n\t A ordem crescente é: %.f - %.f - %.f", b,a,c);
 	}
 	else if(c<a)
 	{
 	if(a<b)
 	printf("\n\t A ordem crescente é: %.f - %.f - %.f", c,a,b);
 	else
 	printf("\n\t A ordem crescente é: %.f - %.f - %.f", c,b,a);
 	}
 	break;
 	
 	case 2:
 	if(a>b)
	{
 	if(b>c)
 	printf("\n\t A ordem crescente é: %.f - %.f - %.f", a,b,c);
 	else
 	printf("\n\t A ordem crescente é: %.f - %.f - %.f", a,c,b);
    }
 	else if(b>c)
 	{
 	if(c<a)
 	printf("\n\t A ordem crescente é: %.f - %.f - %.f", b,c,a);
 	else
 	printf("\n\t A ordem crescente é: %.f - %.f - %.f", b,a,c);
 	}
 	else if(c>a)
 	{
 	if(a>b)
 	printf("\n\t A ordem crescente é: %.f - %.f - %.f", c,a,b);
 	else
 	printf("\n\t A ordem crescente é: %.f - %.f - %.f", c,b,a);
 	}
 	break;
	 
	case 3:
	if(a>b && a>c)
	printf("\n\t O valor da raiz do maior número é: %.2f", sqrt(a));
	else if (b>a && b>c)
	printf("\n\t O valor da raiz do maior número é: %.2f", sqrt(b));
	else
	printf("\n\t O valor da raiz do maior número é: %.2f", sqrt(c));
	break;
	
	case 4:
	if(a<b && a<c)
	printf("\n\t O valor da potência do menor número é: %.2f", (a*a*a));
	else if (b<a && b<c)
	printf("\n\t O valor da potência do menor número é: %.2f", (b*b*b));
	else
	printf("\n\t O valor da potência do menor número é: %.2f", (c*c*c));
	break; 	
}
}

