#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

typedef struct cliente {
    char nome[50];
    char horario[9];
    char tipo_jogo[50];
    int quantidade_jogos;
    float valor_unitario;
    float valor_total;
    struct cliente* prox;
} Cliente;

Cliente* insere(Cliente* inicio, char* nome, char* horario, char* tipo_jogo, int quantidade_jogos, float valor_unitario) {
    Cliente* novo = (Cliente*) malloc(sizeof(Cliente));
    strcpy(novo->nome, nome);
    strcpy(novo->horario, horario);
    strcpy(novo->tipo_jogo, tipo_jogo);
    novo->quantidade_jogos = quantidade_jogos;
    novo->valor_unitario = valor_unitario;
    novo->valor_total = quantidade_jogos * valor_unitario;
    novo->prox = inicio;
    return novo;
}

void grava_arquivo(Cliente* inicio) {
    FILE* fp = fopen("clientes.txt", "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    Cliente* p;
    for (p = inicio; p != NULL; p = p->prox) {
        fprintf(fp, "Nome: %s\nHorario: %s\nTipo de Jogo: %s\nQuantidade de Jogos: %d\nValor Unitario: %.2f\nValor Total: %.2f\n\n",
                p->nome, p->horario, p->tipo_jogo, p->quantidade_jogos, p->valor_unitario, p->valor_total);
    }
    fclose(fp);
}

int main() {
	setlocale(LC_ALL,"Portuguese");
    Cliente* inicio = NULL;
    char nome[50], horario[9], tipo_jogo[50];
    int quantidade_jogos;
    float valor_unitario;
    int opcao;

    do {
        printf("1. Adicionar cliente\n");
        printf("2. Encerrar programa\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Nome: ");
                scanf("%s", nome);
                printf("Horario: ");
                scanf("%s", horario);
                printf("Tipo de Jogo: ");
                scanf("%s", tipo_jogo);
                printf("Quantidade de Jogos: ");
                scanf("%d", &quantidade_jogos);
                printf("Valor Unitario: ");
                scanf("%f", &valor_unitario);
                inicio = insere(inicio, nome, horario, tipo_jogo, quantidade_jogos, valor_unitario);
                break;
            case 2:
                grava_arquivo(inicio);
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 2);

    return 0;
}

