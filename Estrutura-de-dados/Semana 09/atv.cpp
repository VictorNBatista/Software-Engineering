#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Node {
    float data;
    struct Node* next;
    struct Node* prev;
};

typedef struct Node Node;

Node* createNode(float data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro na alocação de memória.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtBeginning(Node** head, float data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void displayDoublyLinkedList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%.2f <-> ", current->data);
        current = current->next;
    }
    printf("\n");
}

void displayCircularLinkedList(Node* head) {
    Node* current = head;
    if (head != NULL) {
        do {
            printf("%.2f -> ", current->data);
            current = current->next;
        } while (current != head);
    }
    printf("\n");
}

int main() {
	setlocale(LC_ALL,"Portuguese");
    Node* doublyLinkedList = NULL;
    Node* circularLinkedList = NULL;

    int choice;
    float nota;

    while (1) {
        printf("Menu:\n");
        printf("1. Inserir nota no início da lista duplamente encadeada\n");
        printf("2. Inserir nota no início da lista circular\n");
        printf("3. Visualizar lista duplamente encadeada\n");
        printf("4. Visualizar lista circular\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite a nota da 1ª VA do aluno: ");
                scanf("%f", &nota);
                insertAtBeginning(&doublyLinkedList, nota);
                break;
            case 2:
                printf("Digite a nota da 1ª VA do aluno: ");
                scanf("%f", &nota);
                insertAtBeginning(&circularLinkedList, nota);
                break;
            case 3:
                printf("Lista Duplamente Encadeada: ");
                displayDoublyLinkedList(doublyLinkedList);
                break;
            case 4:
                printf("Lista Circular: ");
                displayCircularLinkedList(circularLinkedList);
                break;
            case 5:
                exit(0);
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}

