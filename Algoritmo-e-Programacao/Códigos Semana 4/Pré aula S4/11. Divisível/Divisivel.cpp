#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
 setlocale(LC_ALL, "Portuguese");
 int n;
 printf("Digite um valor: ");
 scanf("%i", &n);
 
 if(n%5==0 && n%3==0)
 {
 	printf("\n\t O número %i é divisível por 3 e 5");
 }
 else if(n%3 == 0)
 {
 	printf("\n\t O número %i é divisível por 3");
 }
 else if(n%5 == 0)
 {
 	printf("\n\t O número %i é divisível por 5");
 }
}

