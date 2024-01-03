#include <stdio.h>
#include <math.h>
#include <locale.h>

typedef struct{
	int numero;
	char nome[50];
	char curso[100];
	float nota1;
	float nota2;
} Alunos;

main()
{
	setlocale(LC_ALL,"Portuguese");
	Alunos a;
	FILE *arq;
	
	arq = fopen("Alunos.txt", "w");
	
	if(arq == NULL){
		printf("Erro na abertura do arquivo");
	}
	
	printf("\nColoque os dados do aluno:");
	printf("\nNúmero: ");
	scanf("%i",&a.numero);
	printf("Nome: ");
	scanf(" %[^\n]",&a.nome);
	printf("Curso: ");
	scanf(" %[^\n]",&a.curso);
	printf("Nota 1: ");
	scanf("%f",&a.nota1);
	printf("Nota 2: ");
	scanf("%f",&a.nota2);
	
	printf("\nPassando dados para o arquivo...");
	fprintf(arq, "Número: %i \nNome: %s \nCurso: %s \nNota 1: %.2f \nNota 2: %.2f", a.numero, a.nome, a.curso, a.nota1, a.nota2);
	fclose(arq);
	
	printf("\nOs dados foram passados com sucesso!!");
}
