#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
	setlocale(LC_ALL, "Portuguese");
	 
	float n1,n2;
	printf("Digite o primeiro número: ");
	scanf("%f",&n1);
	printf("Digite o segundo número: ");
	scanf("%f",&n2);
 
	if(n1 < n2)
	{
		printf("\n\t O menor número é: %.2f", n1);
	}
	 	else if(n2 < n1)
	 	{
	 		printf("\n\t O menor número é: %.2f", n2);
		}
	 		else
			{
	 			printf("Os números são iguais");
	 		}
}

