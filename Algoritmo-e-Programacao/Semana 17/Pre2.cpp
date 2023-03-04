#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>

main()
{
 setlocale(LC_ALL, "Portuguese");
 int nota[10][3], i,j, menor, prova1, prova2, prova3;
 printf("Entre com as notas dos alunos\n");
 for(i=0;i<=9;i++)
 {
 	printf("\nNotas do aluno %d\n",i+1);
 	for(j=0;j<=2;j++)
 	{
 		printf("Prova %d: ",j+1);
 		scanf("%d",&nota[i][j]);
	}
 }
 
 system("cls");
 printf("Relatório das notas\n");
 prova1 = prova2 = prova3 = 0;
	for(i=0;i<=9;i++)
	{
	 	printf("\nPara o aluno %d as notas foram:\n",i+1);
	 	menor = 10;
	 	for(j=0;j<=2;j++)
	 	{
	 		if(nota[i][j] <= menor)
	 		menor = nota[i][j];
	 		
	 		printf("Nota para a prova %d foi: %d\n", j+1, nota[i][j]);
		}
		printf("Para este aluno a menor nota foi: %d\n",menor);
		
		for(j=0;j<=2;j++)
		{
			if(menor == nota[i][j] && j == 0)
			{
				prova1++;
				break;
			}
			else if(menor == nota[i][j] && j == 1)
			{
				prova2++;
				break;
			}
			else if(menor == nota[i][j] && j == 2)
			{
				prova3++;
				break;
			}
		}
	}
	printf("\n\nQuantidade de alunos que tiveram menor notas na prova 1 foi de %d\n", prova1);
    printf("Quantidade de alunos que tiveram menor notas na prova 2 foi de %d\n", prova2);
    printf("Quantidade de alunos que tiveram menor notas na prova 3 foi de %d\n", prova3);
}

