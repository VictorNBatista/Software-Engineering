
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
 	printf("\n\t � um tri�ngulo equil�tero");
 	
 	else if(a!=b && b==c || b!=c && a==c || c!=b && b==a)
 	printf("\n\t � um tri�ngulo is�sceles");
 	
 	else if(a!=b && b!=c)
 	printf("\n\t � um tri�ngulo escaleno");
 }
 else
 printf("\n\t N�o � um tri�ngulo");
}

