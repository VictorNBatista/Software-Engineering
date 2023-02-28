
#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
 setlocale(LC_ALL, "Portuguese");
 int a,b,c;
 printf("Digite o primeiro valor: ");
 scanf("%i", &a);
 printf("Digite o segundo valor: ");
 scanf("%i", &b);
 printf("Digite o terceiro valor: ");
 scanf("%i", &c);
 
 if(a<b+c && b<a+c && c<b+a)
 {
 	if(a==b && b==c)
 	printf("\n\t É um triângulo equilátero");
 	
 	else if(a!=b && b==c || b!=c && a==c || c!=b && b==a)
 	printf("\n\t É um triângulo isósceles");
 	
 	else if(a!=b && b!=c)
 	printf("\n\t É um triângulo escaleno");
 }
 else
 printf("\n\t Não é um triângulo");
}

