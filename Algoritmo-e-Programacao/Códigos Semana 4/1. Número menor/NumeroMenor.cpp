#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
	setlocale(LC_ALL, "Portuguese");
	 
	float n1,n2;
	printf("Digite o primeiro n�mero: ");
	scanf("%f",&n1);
	printf("Digite o segundo n�mero: ");
	scanf("%f",&n2);
 
	if(n1 < n2)
	{
		printf("\n\t O menor n�mero �: %.2f", n1);
	}
	 	else if(n2 < n1)
	 	{
	 		printf("\n\t O menor n�mero �: %.2f", n2);
		}
	 		else
			{
	 			printf("Os n�meros s�o iguais");
	 		}
}

