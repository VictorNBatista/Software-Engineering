#include<stdio.h>
#include<math.h>
#include<locale.h>

main(){
	setlocale(LC_ALL,"Portuguese");
	int n,r,c,pa;
	printf("Digite o primeiro elemento da PA: ");
	scanf("%i",&n);
	printf("Agora digite a razão da PA: ");
	scanf("%i",&r);
	printf("Agora digite a quantidade de elementos da PA: ");
	scanf("%i",&c);
	
	pa = n;
	printf("\n%i",pa);
	
	for(int cont=1;cont<c;cont++)
	{
		pa = pa + r;
		printf("\n%i",pa);
	}
	
	if(r>0)
	printf("\nA PA é crescente");
	else
	printf("\nA PA é decrescente");
}


