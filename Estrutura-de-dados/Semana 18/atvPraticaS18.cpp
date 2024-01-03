#include<locale.h>
#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um avi�o
typedef struct Aviao {
    int id;
    struct Aviao* proximo;
} Aviao;

// Estrutura para representar a fila de avi�es
typedef struct Fila {
    Aviao* inicio;
    Aviao* fim;
} Fila;

// Fun��o para inicializar a fila
Fila* inicializar() {
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

// Fun��o para verificar se a fila est� vazia
int estaVazia(Fila* f) {
    return (f->inicio == NULL);
}

// Fun��o para enfileirar um avi�o
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

// Fun��o para desenfileirar um avi�o
int desenfileirar(Fila* f) {
    if (estaVazia(f)) {
        printf("A fila est� vazia.\n");
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

// Fun��o para exibir os avi�es na fila
void exibir(Fila* f) {
	printf("Avioes presentes na fila:\n");
    if (estaVazia(f)) {
        printf("A fila est� vazia.\n");
        return;
    }
    Aviao* temp = f->inicio;
    while (temp != NULL) {
        printf("Avi�o ID: %d\n", temp->id);
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
    printf("Avi�o ID %d decolou.\n", desenfileirar(f));
    enfileirar(f, 4);
    printf("Avi�o ID %d decolou.\n", desenfileirar(f));
    printf("\n");
    exibir(f);
    return 0;
}

/*

TESTES REALIZADOS:
Inicializa��o da fila: A fila foi inicializada corretamente e verificou que estava vazia.
Enfileiramento de avi�es: Adicionei quatro avi�es � fila e verifiquei se eles foram
adicionados na ordem correta.
Desenfileiramento de avi�es: Removi avi�es da fila e verificamos se o avi�o correto
(o primeiro da fila) foi removido.
Exibi��o dos avi�es na fila: Exibi a fila ap�s cada opera��o para verificar se a fila
estava correta.


RESULTADOS OBTIDOS:
A fila foi inicializada corretamente e estava vazia ap�s a inicializa��o.
Os avi�es foram enfileirados na ordem correta.
O avi�o correto foi desenfileirado da fila.
A fila foi exibida corretamente ap�s cada opera��o.

PROBLEMAS ENFRENTADOS:
Inicialmente, houve um problema onde a fila n�o estava sendo inicializada corretamente.
Isso foi corrigido garantindo que o in�cio e o fim da fila fossem definidos como NULL durante a inicializa��o.
Tive um problema onde o avi�o errado estava sendo desenfileirado. Isso foi corrigido garantindo que sempre
removesse o avi�o do in�cio da fila.

*/
