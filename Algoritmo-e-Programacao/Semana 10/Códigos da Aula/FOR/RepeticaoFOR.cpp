#include<stdio.h>
#include<locale.h>
#include<math.h>
#include<stdlib.h>
#define alunos 5

main()
{
	setlocale(LC_ALL,"Portuguese");
	float n1, n2, MA, MG, S;
	int c,ap;
	
	S= 0;
	ap= 0;
	for(c=0;c<alunos;c++)
	{
		printf("Entre com a nota 1 do aluno %d: ",c+1);
		scanf("%f",&n1);
		printf("Entre com a nota 2 do aluno %d: ",c+1);
		scanf("%f",&n2);
		MA = (n1+n2)/2;
		S = S + MA;
		if(MA<4)
		printf("O aluno foi reprovado com a média: %.2f",MA);
		else if(MA<6)
		printf("O aluno está de recuperação com a média: %.2f",MA);
		else
		{
		printf("O aluno está aprovado com a média: %.2f",MA);
		ap = ap + 1;
		}
		printf("\n\n");
	}
	
	MG = S/alunos;
	printf("\tA média geral dos 5 alunos é: %.2f",MG);
	printf("\n\tO número total de aprovados são: %i",ap);

}



