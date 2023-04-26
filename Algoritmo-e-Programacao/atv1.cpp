
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>

//void CalcM(int M[][]);

main()
{
	setlocale(LC_ALL,"Portuguese");
	int M[5][5];
	int i,j,aux;
	
	printf("Digite os números da Matriz\n");
	
	for(i=0;i<5;i++){
		printf("*Linha %i*\n",i);
		
		for(j=0;j<5;j++){
			printf("Coluna %i: ",j);
			scanf("%i",&M[i][j]);
		}
	}
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
		if(M[i][j]%5 == 0){
				M[i][j] = M[i][i];
			}
			else if(M[i][j]%11 == 0){
				M[i][j] = M[i][5-j];
			}
			else if(M[i][j]%13 == 0){
				M[i][j] = M[5-i][j];
			}	
		}
	}
	
	
	for(int i=0;i<5;i++){
		printf("\n");
		for(int j=0;j<5;j++){
			printf("\t%i",M[i][j]);
		}
	}
}

