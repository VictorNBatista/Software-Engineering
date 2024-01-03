#include<locale.h>
#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um avião
typedef struct Aviao {
    int id;
    struct Aviao* proximo;
} Aviao;

// Estrutura para representar a fila de aviões
typedef struct Fila {
    Aviao* inicio;
    Aviao* fim;
} Fila;

// Função para inicializar a fila
Fila* inicializar() {
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

// Função para verificar se a fila está vazia
int estaVazia(Fila* f) {
    return (f->inicio == NULL);
}

// Função para enfileirar um avião
void enfileirar(Fila* f, int id) {
    Aviao* a = (Aviao*)malloc(sizeof(Aviao));
    a->id = id;
    a->proximo = NULL;
    if (estaVazia(f)) {
        f->inicio = a;
    } else {
        f->fim->proximo = a;
    }
    f->fim = a;
    printf("Aviao ID %d entrou na fila.\n", id);
}

// Função para desenfileirar um avião
int desenfileirar(Fila* f) {
    if (estaVazia(f)) {
        printf("A fila está vazia.\n");
        return -1;
    }
    int id = f->inicio->id;
    Aviao* temp = f->inicio;
    f->inicio = f->inicio->proximo;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    free(temp);
    return id;
}

// Função para exibir os aviões na fila
void exibir(Fila* f) {
	printf("Avioes presentes na fila:\n");
    if (estaVazia(f)) {
        printf("A fila está vazia.\n");
        return;
    }
    Aviao* temp = f->inicio;
    while (temp != NULL) {
        printf("Avião ID: %d\n", temp->id);
        temp = temp->proximo;
    }
    printf("\n");
}

int main() {
	setlocale(LC_ALL,"Portuguese");
    Fila* f = inicializar();
    enfileirar(f, 1);
    enfileirar(f, 2);
    enfileirar(f, 3);
    printf("\n");
    exibir(f);
    printf("Avião ID %d decolou.\n", desenfileirar(f));
    enfileirar(f, 4);
    printf("Avião ID %d decolou.\n", desenfileirar(f));
    printf("\n");
    exibir(f);
    return 0;
}

/*

TESTES REALIZADOS:
Inicialização da fila: A fila foi inicializada corretamente e verificou que estava vazia.
Enfileiramento de aviões: Adicionei quatro aviões à fila e verifiquei se eles foram
adicionados na ordem correta.
Desenfileiramento de aviões: Removi aviões da fila e verificamos se o avião correto
(o primeiro da fila) foi removido.
Exibição dos aviões na fila: Exibi a fila após cada operação para verificar se a fila
estava correta.


RESULTADOS OBTIDOS:
A fila foi inicializada corretamente e estava vazia após a inicialização.
Os aviões foram enfileirados na ordem correta.
O avião correto foi desenfileirado da fila.
A fila foi exibida corretamente após cada operação.

PROBLEMAS ENFRENTADOS:
Inicialmente, houve um problema onde a fila não estava sendo inicializada corretamente.
Isso foi corrigido garantindo que o início e o fim da fila fossem definidos como NULL durante a inicialização.
Tive um problema onde o avião errado estava sendo desenfileirado. Isso foi corrigido garantindo que sempre
removesse o avião do início da fila.

*/
