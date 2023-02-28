#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
 setlocale(LC_ALL, "Portuguese");
  
  int n1,n2,n3;
  printf("Digite o primeiro número: ");
  scanf("%i",&n1);
  printf("Digite o segundo número: ");
  scanf("%i",&n2);  
  printf("Digite o terceiro número: ");
  scanf("%i",&n3);
  
  if(n1<n2)
  {
  	if(n2<n3)
  	{
  		printf("\n\t %i - %i - %i", n1, n2, n3);
	}
	  else
	  {
	  	printf("\n\t %i, %i, %i", n1, n3, n2);
	  }
  }
  else if(n2<n1)
  {
  	if(n1<n3)
  	{
  		printf("\n\t %i, %i, %i", n2, n1, n3);
	}
	else
	{
		printf("\n\t %i, %i, %i", n2, n3, n1);
	}
  }
  else if(n3<n2)
  {
  	if(n2<n1)
  	{
  		printf("\n\t %i, %i, %i", n3, n2, n1);
	}
	else
	{
		printf("\n\t %i, %i, %i", n3, n1, n2);
	}
  }
}

