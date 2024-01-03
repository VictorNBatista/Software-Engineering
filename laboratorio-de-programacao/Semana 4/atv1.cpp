#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>

int triangulo(int a, int b, int c);
int tptriangulo(int a, int b, int c);


main()
{
	setlocale(LC_ALL, "Portuguese");
	int a,b,c,t,tipo;
	
	printf("Digite o valor do lado A do triângulo: ");
	scanf("%i",&a); 
	printf("Digite o valor do lado B do triângulo: ");
	scanf("%i",&b); 
	printf("Digite o valor do lado C do triângulo: ");
	scanf("%i",&c);
	
	t = triangulo(a,b,c);
	
	if(t == 0){
		printf("\n\tÉ um triângulo do tipo:");
		tipo = tptriangulo(a,b,c);
	} 
	else
		printf("\n\tNão é um triângulo");
	
	
	if (tipo == 1)
		printf("\n\tequilátero");
		
	else if(tipo == 2)
		printf("\n\tisósceles");
		
	else if(tipo == 3)
		printf("\n\tescaleno");		
			
	
}

int triangulo(int a, int b, int c){
	if(a<b+c && b<a+c && c<b+a)
		return 0;
 	else
 		return 1;
}

int tptriangulo(int a, int b, int c){
	if(a==b && b==c)
 	return 1;
 	
 	else if(a!=b && b==c || b!=c && a==c || c!=b && b==a)
 	return 2;
 	
 	else if(a!=b && b!=c)
 	return 3;
}
