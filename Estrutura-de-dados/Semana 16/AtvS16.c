#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Estrutura do nó da pilha
struct No {
    int dado;
    struct No* prox;
};

// Função para criar um novo nó
struct No* novoNo(int dado) {
    struct No* no = (struct No*) malloc(sizeof(struct No));
    no->dado = dado;
    no->prox = NULL;
    return no;
}

// Função para verificar se a pilha está vazia
int estaVazia(struct No* topo) {
    return !topo;
}

// Função para inserir um elemento na pilha
void push(struct No** topo, int dado) {
    struct No* no = novoNo(dado);
    no->prox = *topo;
    *topo = no;
    printf("%d empilhado\n", dado);
}

// Função para remover um elemento da pilha
int pop(struct No** topo) {
    if (estaVazia(*topo)) {
        return INT_MIN;
    }
    struct No* temp = *topo;
    *topo = (*topo)->prox;
    int dado = temp->dado;
    free(temp);

    return dado;
}

// Função para mostrar a pilha
void mostrarPilha(struct No* topo) {
    while (!estaVazia(topo)) {
        printf("%d\n", topo->dado);
        topo = topo->prox;
    }
}

// Função para esvaziar a pilha
void esvaziarPilha(struct No** topo) {
    while (!estaVazia(*topo)) {
        pop(topo);
    }
}

int main() {
	setlocale(LC_ALL,"Portuguese");
    struct No* topo = NULL;

    int opcao, valor;
    do {
        printf("\n1. Push\n2. Pop\n3. Mostrar Pilha\n4. Verificar se a pilha está vazia\n5. Esvaziar a pilha\n6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser empilhado: ");
                scanf("%d", &valor);
                push(&topo, valor);
                break;
            case 2:
                printf("%d desempilhado\n", pop(&topo));
                break;
            case 3:
                mostrarPilha(topo);
                break;
            case 4:
                if (estaVazia(topo)) {
                    printf("A pilha está vazia\n");
                } else {
                    printf("A pilha não está vazia\n");
                }
                break;
            case 5:
                esvaziarPilha(&topo);
                printf("A pilha foi esvaziada\n");
                break;
            case 6:
                printf("Saindo do programa\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 6);

    return 0;
}

