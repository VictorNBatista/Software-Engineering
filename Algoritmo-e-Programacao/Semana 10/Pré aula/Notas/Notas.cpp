#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>

main()
{
 setlocale(LC_ALL, "Portuguese");
 float n1,n2,n3,ma,mg,s=0;
 int rep=0;
 for(int c=0;c<5;c++)
 {
 	printf("Nota da 1� VA:");
 	scanf("%f",&n1);
 	printf("Nota da 2� VA:");
 	scanf("%f",&n2);
 	printf("Nota da 3� VA:");
 	scanf("%f",&n3);
 	ma = (n1+n2+n3)/3;
 	s = s + ma;
 	if(ma<60)
 	{
 	printf("O aluno est� reprovado com m�dia: %.2f\n\n",ma);
 	rep = rep + 1;
 	}
 	else
 	printf("O aluno est� aprovado com m�dia: %.2f\n\n",ma);
 }
 mg = s/5;
 printf("\nA m�dia geral da turma �: %.2f",mg);
 printf("\nO total alunos abaixo da m�dia �: %i",rep);
}

