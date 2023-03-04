#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>
#define n 2 
main()
{
 setlocale(LC_ALL, "Portuguese");
 int m[n][n], i, j, r[n][n], maior;
 for (i=0; i<n; i++)
 {
	for(j=0; j<n; j++)
	{
	printf("Digite o número da linha %d coluna %d da matriz: ", i, j);
	scanf("%d%*c",& m[i][j]);
	}
 }
 
 maior= m[0][0];
 for (i=0; i<n; i++)
 {         
	for (j=0; j<n; j++)
	{         
		if (m[i][j]>maior)
		{                 
		maior=m[i][j];             
		}         
	}     
 }
       
 for (i=0; i<n; i++)
 {         
	for (j=0; j<n; j++)
	{             
	r[i][j]=maior*m[i][j];         
	}     
 } 
      
 printf("\nO maior elemento da matriz é %d. A matriz resultante é:\n", maior);     
 for (i=0; i<n; i++)
 {         
	for (j=0; j<n; j++)
	{             
	printf("%d\t", r[i][j]);         
	}
	printf("\n");     
 }     
 
}


