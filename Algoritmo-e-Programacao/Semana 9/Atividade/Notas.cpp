#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>

#define alunos 10

main()
{
	 setlocale(LC_ALL, "Portuguese");
	 float n1,n2,ma,mg,s=0;
	 int sa=0,sr=0;
	 for(int c=0;c<alunos;c++)
	 {
	 printf("Nota 1 do aluno %i: ",c+1);
	 scanf("%f",&n1);
	 printf("Nota 2 do aluno %i: ",c+1);
	 scanf("%f",&n2);
	 ma = (n1+n2)/2;
	 s = s + ma;
	 
	 if(ma<60)
	 {
	 	printf("Aluno reprovado com a média: %.2f\n",ma);
	 	sr = sr + 1;
	 }
	 else
	 {
	 	printf("Aluno aprovado com a média: %.2f\n",ma);
	 	sa = sa + 1;
	 }
	 }
	 mg = s/alunos;
	 printf("\nA média geral da turma é: %.2f",mg);
	 printf("\nTotal de aprovados: %i",sa);
	 printf("\nTotal de reprovados: %i",sr);
}

