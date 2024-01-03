#include<stdio.h>
#include<math.h>
#include<locale.h>

void triangulo(int x,int y);
void crescente(int x, int y, int z);
void decrescente (int x, int y, int z);
void bhaskara (int x, int y, int z);

main()
{
setlocale(LC_ALL, "Portuguese");
int a,b,c,op;


printf("Qual opera��o deseja realizar?"
		"\n1- Calcular �rea do tri�ngulo"
		"\n2- Ordenar 3 valores de forma crescente"
		"\n3- Ordenar 3 valores de forma decrescente"
		"\n4- Encontrar ra�zes de uma equa��o de 2� grau\n");
scanf("%i",&op);
switch(op){
	case 1:
			printf("C�lculo da �rea de um tri�ngulo\n\nDigite o valor da base: ");
			scanf("%i",&a);
			printf("Digite o valor da altura: ");
			scanf("%i",&b);
			triangulo(a,b);
			break;
		
	case 2:
		printf("Ordenamento crescente dos valores\n\nDigite o primeiro valor: ");
		scanf("%i",&a);
		printf("Digite o segundo valor: ");
		scanf("%i",&b);
		printf("Digite o terceiro valor: ");
		scanf("%i",&c);
		crescente(a,b,c);
		break;	
		
	case 3:
		printf("Ordenamento decrescente dos valores\n\nDigite o primeiro valor: ");
		scanf("%i",&a);
		printf("Digite o segundo valor: ");
		scanf("%i",&b);
		printf("Digite o terceiro valor: ");
		scanf("%i",&c);
		decrescente(a,b,c);
		break;
		
	case 4:
		printf("Ra�zes de uma equa��o de 2� grau\n");
		printf("\nDigite o valor de A: ");
		scanf("%i",&a);
		printf("\nDigite o valor de B: ");
		scanf("%i",&b);
		printf("\nDigite o valor de C: ");
		scanf("%i",&c);
		bhaskara(a,b,c);
		break;
}
}

void triangulo(int x,int y){
	float conta;
	conta = (x*y)/2;
	printf("\nO valor da �rea do tri�ngulo �: %.2fm�",conta);
}

void crescente(int x, int y, int z){
	int a=x, b=y, c=z;
	if(a<b && a<c)
		{
			if(b<c)
			printf("A ordem correta �: %i, %i, %i",a,b,c);
			else
			printf("A ordem correta �: %i, %i, %i",a,c,b);
		}
		else if(b<a && b<c)
		{
			if(a<c)
			printf("A ordem correta �: %i, %i, %i",b,a,c);
			else
			printf("A ordem correta �: %i, %i, %i",b,c,a);
		}
		else if(c<b && c<a)
		{
			if(b<a)
			printf("A ordem correta �: %i, %i, %i",c,b,a);
			else
			printf("A ordem correta �: %i, %i, %i",c,a,b);
		}
}

void decrescente (int x, int y, int z){
	int a=x, b=y, c=z;
	if(a>b && a>c)
		{
			if(b>c)
			printf("A ordem correta �: %i, %i, %i",a,b,c);
			else
			printf("A ordem correta �: %i, %i, %i",a,c,b);
		}
		else if(b>a && b>c)
		{
			if(a>c)
			printf("A ordem correta �: %i, %i, %i",b,a,c);
			else
			printf("A ordem correta �: %i, %i, %i",b,c,a);
		}
		else if(c>b && c>a)
		{
			if(b>a)
			printf("A ordem correta �: %i, %i, %i",c,b,a);
			else
			printf("A ordem correta �: %i, %i, %i",c,a,b);
		}
}

void bhaskara (int x, int y, int z){
	int a=x, b=y, c=z;
	float delta,x1,x2;
	delta= pow(b,2) - (4*a*c);
		if(delta>=0)
		{
		x1=(-b+sqrt(delta))/(2*a);
		x2=(-b-sqrt(delta))/(2*a);
		printf("As ra�zes encontradas s�o: X1= %.2f e X2= %.2f",x1,x2);
		}else
		printf("Ra�zes inexistentes");
}
