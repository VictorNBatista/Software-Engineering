#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>

main()
{
 setlocale(LC_ALL, "Portuguese");
 int m,n,soma=0;
 
 printf("Digite o valor inicial: ");
 scanf("%i",&m);
 printf("Digite o valor final: ");
 scanf("%i",&n);
 
 while(m<n)
 {
 	for(int c=m;c<=n;c++)
 	{
 		soma = soma + c;
	}
 
 printf("\nA soma dos termos entre %i e %i é: %i",m,n,soma);
	
 printf("\n\n");
 printf("Digite o valor inicial: ");
 scanf("%d",&m);
 printf("Digite o valor final: ");
 scanf("%d",&n);
 }
}

