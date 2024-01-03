#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdbool.h>

typedef struct{
	int numero;
	char nome[50];
	char curso[100];
	float nota1;
	float nota2;
} Alunos;



int verificarRepeticao(Alunos *aluno, int valor, int indice) {
    for (int i = 0; i < indice; i++) {
        if (aluno[i].numero == valor) {
            return 1; 
        }
    }
    return 0; 
}

int encontrarIndice(Alunos *aluno, int valor, int indice){
	for(int i=0; i<indice; i++){
		if(aluno[i].numero == valor){
			return i;
		}
	}
	return -1;
}



void registrar(Alunos *aluno, int n);
void armazenar(Alunos *aluno, FILE *arq, int n);
void alterar_notas(Alunos *aluno, FILE *arq, int n);

main() {
    setlocale(LC_ALL, "Portuguese");
    Alunos aluno[100];
    FILE *arq;
    int n, i;

    printf("Quantidade de alunos a serem registrados: ");
    scanf("%i", &n);
	
	registrar(aluno, n);
    
    armazenar(aluno, arq, n);
    	
	alterar_notas(aluno, arq, n);
    
}

void registrar(Alunos *aluno, int n){
	for(int i=0; i<n; i++){
	printf("\nNúmero: ");
    scanf("%i", &aluno[i].numero);
    if (verificarRepeticao(aluno, aluno[i].numero, i)) {
        printf("O número inserido já existe. Insira um número diferente.\n");
        i--; // Reverter a iteração para inserir um novo valor
        continue; // Pular para a próxima iteração
    }
    printf("Nome: ");
    scanf(" %[^\n]", aluno[i].nome);
    printf("Curso: ");
    scanf(" %[^\n]", aluno[i].curso);
    printf("Nota 1: ");
    scanf("%f", &aluno[i].nota1);
    printf("Nota 2: ");
    scanf("%f", &aluno[i].nota2);
    }
}

void armazenar(Alunos *aluno, FILE *arq, int n){
	arq = fopen("Alunos.txt", "w+");
	
	if (arq == NULL) {
        printf("Erro na abertura do arquivo");
    }
    
	for(int i=0; i<n; i++){	
    fprintf(arq, "Número: %i \nNome: %s \nCurso: %s" 
			"\nNota 1: %.2f \nNota 2: %.2f\n\n", aluno[i].numero, aluno[i].nome, aluno[i].curso, aluno[i].nota1, aluno[i].nota2);
    }
    
    fclose(arq);
    printf("\nOs dados foram passados com sucesso!!");
}

void alterar_notas(Alunos *aluno, FILE *arq, int n){
	int op;
	printf("\nGostaria de alterar a nota de algum aluno? 1-sim/ 2-não\n");
    scanf("%i",&op);
	
	do{
	switch(op){
		case 1:
		int numero,ind,qual;
		float nota;
		printf("Digite o número do aluno: ");
		scanf("%i",&numero);
		ind = encontrarIndice(aluno, numero, n);
		if(ind != -1){
			printf("Qual nota deseja alterar? (1/2)\n");
			scanf("%i",&qual);
			printf("Digite o novo valor: ");
			scanf("%f",&nota);
			if(qual == 1){
			aluno[ind].nota1 = nota;
			}
			else{
			aluno[ind].nota2 = nota;
			}	
		}
		else{
			printf("Este aluno não foi encontrado.");
		}
		armazenar(aluno, arq, n);
		break;
			
		case 2:
			break;		
	}
	
	printf("\nGostaria de alterar outra nota? 1-sim/ 2-não\n");
	scanf("%i",&op);
	}while(op != 2);
}
