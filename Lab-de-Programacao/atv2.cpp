#include <stdio.h>
#include <stdlib.h> 

typedef struct {
    int matricula;
    char nome[20];
    char nasc[10];
} aluno;

void cadastro(aluno* alunos, int n);
void mostrar(aluno* alunos, int n);

int main() {
    int n;
    printf("Numero de alunos que serao armazenados: ");
    scanf("%i", &n);

    // Alocar memória inicial usando malloc
    aluno* alunos = (aluno*)malloc(n * sizeof(aluno));

    if (alunos == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1; // Terminar com código de erro
    }

    printf("\nCadastrando alunos...\n");
    cadastro(alunos, n);

    printf("\nMostrando dados...\n");
    mostrar(alunos, n);

    // Liberar a memória alocada
    free(alunos);

    return 0;
}

void cadastro(aluno* alunos, int n) {
    for (int i = 0; i < n; i++) {
        printf("**Aluno %i**\n", i + 1);
        printf("Matricula: ");
        scanf("%i", &alunos[i].matricula);
        printf("Nome: ");
        scanf("%s", alunos[i].nome);
        printf("Data de nascimento (dd/mm/aaaa): ");
        scanf("%s", alunos[i].nasc);
    }
}

void mostrar(aluno* alunos, int n) {
    for (int i = 0; i < n; i++) {
        printf("**Aluno %i**\n", i + 1);
        printf("Matricula: %i\n", alunos[i].matricula);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Data de nascimento (dd/mm/aaaa): %s\n", alunos[i].nasc);
    }
}

