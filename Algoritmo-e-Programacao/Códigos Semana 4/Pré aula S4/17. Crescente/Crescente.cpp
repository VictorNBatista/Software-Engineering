#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
 setlocale(LC_ALL, "Portuguese");
 int a,b,c;
 printf("Digite o primeiro n�mero: ");
 scanf("%i",&a);
 printf("Digite o segundo n�mero: ");
 scanf("%i",&b);
 printf("Digite o terceiro n�mero: ");
 scanf("%i",&c);
 
 if(a<b)
 {
 	if(b<c)
 	printf("\n\t A ordem crescente �: %i - %i - %i", a,b,c);
 	else
 	printf("\n\t A ordem crescente �: %i - %i - %i", a,c,b);
 }
 else if(b<c)
 {
 	if(c<a)
 	printf("\n\t A ordem crescente �: %i - %i - %i", b,c,a);
 	else
 	printf("\n\t A ordem crescente �: %i - %i - %i", b,a,c);
 }
 else if(c<a)
 {
 	if(a<b)
 	printf("\n\t A ordem crescente �: %i - %i - %i", c,a,b);
 	else
 	printf("\n\t A ordem crescente �: %i - %i - %i", c,b,a);
 }
}

