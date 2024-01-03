#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no {
    int valor;
    struct no* proximo;
} No;

void inserir_na_fila(No** fila, int num) {
    No *aux, *novo = (No*) malloc(sizeof(No));
    if (novo) {
        novo->valor = num;
        novo->proximo = NULL;
        if (*fila == NULL)
            *fila = novo;
        else {
            aux = *fila;
            while (aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo;
        }
    } else
        printf("\nErro ao alocar memória.\n");
}

void liberar_fila(No* fila) {
    while (fila) {
        No* temp = fila;
        fila = fila->proximo;
        free(temp);
    }
}

int main() {
	setlocale(LC_ALL,"Portuguese");
    No* fila = NULL;
    int total_tempo_espera = 0;
    int pacientes_atendidos = 0;
    int num_pacientes;

    printf("Digite o número de pacientes na UPA: ");
    scanf("%d", &num_pacientes);

    for (int i = 0; i < num_pacientes; ++i) {
        int tempo_atendimento;
        printf("Digite o tempo de atendimento para o paciente %d (em minutos): ", i + 1);
        scanf("%d", &tempo_atendimento);
        inserir_na_fila(&fila, tempo_atendimento);
    }

    No* atual = fila;
    while (atual != NULL) {
        total_tempo_espera += atual->valor;
        pacientes_atendidos++;
        atual = atual->proximo;
    }

    if (pacientes_atendidos > 0) {
        float tempo_medio_espera = (float)total_tempo_espera / pacientes_atendidos;
        printf("Tempo médio de espera dos pacientes na fila: %.2f minutos\n", tempo_medio_espera);
        printf("Quantidade de pacientes atendidos em um turno de 24h do médico: %d\n", pacientes_atendidos);
    } else {
        printf("Nenhum paciente foi atendido.\n");
    }

    // Liberar a memória alocada para os nós da fila
    liberar_fila(fila);

    return 0;
}


