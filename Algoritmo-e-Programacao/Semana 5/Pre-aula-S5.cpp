#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
setlocale(LC_ALL,"Portuguese");
int op;
float a,b,c;

printf("Digite o primeiro n�mero: ");
scanf("%f",&a);
printf("Digite o segundo n�mero: ");
scanf("%f",&b);
printf("Digite o terceiro n�mero: ");
scanf("%f",&c);

printf("Escolha a opera��o desejada \n1. Mostre os valores em ordem crescente \n2. Mostre os valores em ordem decrescente \n3. Mostre a raiz quadrada do maior valor encontrado \n4. Mostre o menor valor encontrado elevado a 3� pot�ncia \n");
scanf("%i",&op);

switch(op)
{
	case 1:
	if(a<b)
	{
 	if(b<c)
 	printf("\n\t A ordem crescente �: %.f - %.f - %.f", a,b,c);
 	else
 	printf("\n\t A ordem crescente �: %.f - %.f - %.f", a,c,b);
    }
 	else if(b<c)
 	{
 	if(c<a)
 	printf("\n\t A ordem crescente �: %.f - %.f - %.f", b,c,a);
 	else
 	printf("\n\t A ordem crescente �: %.f - %.f - %.f", b,a,c);
 	}
 	else if(c<a)
 	{
 	if(a<b)
 	printf("\n\t A ordem crescente �: %.f - %.f - %.f", c,a,b);
 	else
 	printf("\n\t A ordem crescente �: %.f - %.f - %.f", c,b,a);
 	}
 	break;
 	
 	case 2:
 	if(a>b)
	{
 	if(b>c)
 	printf("\n\t A ordem crescente �: %.f - %.f - %.f", a,b,c);
 	else
 	printf("\n\t A ordem crescente �: %.f - %.f - %.f", a,c,b);
    }
 	else if(b>c)
 	{
 	if(c<a)
 	printf("\n\t A ordem crescente �: %.f - %.f - %.f", b,c,a);
 	else
 	printf("\n\t A ordem crescente �: %.f - %.f - %.f", b,a,c);
 	}
 	else if(c>a)
 	{
 	if(a>b)
 	printf("\n\t A ordem crescente �: %.f - %.f - %.f", c,a,b);
 	else
 	printf("\n\t A ordem crescente �: %.f - %.f - %.f", c,b,a);
 	}
 	break;
	 
	case 3:
	if(a>b && a>c)
	printf("\n\t O valor da raiz do maior n�mero �: %.2f", sqrt(a));
	else if (b>a && b>c)
	printf("\n\t O valor da raiz do maior n�mero �: %.2f", sqrt(b));
	else
	printf("\n\t O valor da raiz do maior n�mero �: %.2f", sqrt(c));
	break;
	
	case 4:
	if(a<b && a<c)
	printf("\n\t O valor da pot�ncia do menor n�mero �: %.2f", (a*a*a));
	else if (b<a && b<c)
	printf("\n\t O valor da pot�ncia do menor n�mero �: %.2f", (b*b*b));
	else
	printf("\n\t O valor da pot�ncia do menor n�mero �: %.2f", (c*c*c));
	break; 	
}
}

