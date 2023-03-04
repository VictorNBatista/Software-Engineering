#include<stdio.h>
#include<locale.h>
#include<math.h>
#include<stdlib.h>

main()
{
	setlocale(LC_ALL,"Portuguese");
	int n;
	float c, s, div;
	c = 0;
	s = 0;
	printf("Entre com o valor de n: ");
	scanf("%d",&n);
	while(n != 0)
	{
		c++;
		div = n/c;
		s = s + div;
		printf("Entre com o valor de n: ");
		scanf("%d",&n);
	}
	printf("\nO somatório dos termos é: %.2f",s);

}



