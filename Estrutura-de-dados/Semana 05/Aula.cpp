/* 
    Listas Lineares Sequencias -> Vetores
        Organiza os elementos de forma sequencial, eles ficam armazenados em 
        posições contiguas na mémoria. Neste tipo de lista é interessante que se saiba 
        a quantidade de elementos que serão armazenados antes de realizar qualquer tipo de operação.

Listas Lineares Encadeadas
        É um conjunto de linear de estruturas que são autoreferenciadas, chamadas de NÓS (nodos), 
        que são conectados por Links(ligações ou encadeamentos) de ponteiros. Ela é acessada por meio 
        de um ponteiro que aponta para o primeiro nó da Lista. Os nós subsequentes são acessados por meio 
        de ponteiro de ligação que existe em cada nó.

        Tipos de listas que iremos estudar
            Filas -> fifo (First in - first out)
            Pilhas -> Lifo (Last in - first out)
            Listas duplamente encadeadas
            Listas circulares
*/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

// Criando uma estrutura de nó da lista
typedef struct Node{
    int data;
    struct Node *next;
}Node;
//********************************************
// Função para criar um novo Nó
Node *createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Erro ao alocar memória para o Nó.");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
//********************************************
// Função para INSERIR um novo nó no início da lista
void insertAtBeginning(Node **head, int data){
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}
//********************************************
// Função para REMOVER um novo nó da lista
void removeFromList(Node** head, int data){
    Node *currentNode = *head;
    Node *prevNode = NULL;
   
   
    while(currentNode != NULL){
        if(currentNode->data == data){
            if(prevNode == NULL){
                *head = currentNode->next;
            }
            else{
                prevNode->next = currentNode->next;
            }
            free(currentNode);
            return;
        }
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    printf("O Elemento %d não foi encontrado na lista. \n",data);
}
//********************************************
// Função para buscar um elemento na lista
Node *searchInList(Node *head, int data){
    Node *currentNode = head;

    while(currentNode != NULL){
        if(currentNode->data == data){
            return currentNode;
        }
        currentNode = currentNode->next;
    }
    return NULL;
}
//********************************************
// Função para imprimir a lista
void printList(Node *head){
    Node *currentNode = head;
    
    while(currentNode != NULL){
        printf("[%d]-> ",currentNode->data);
        currentNode = currentNode->next;
    }
    printf("NULL \n");
}
//********************************************
// Função Principal
main(){
    setlocale(LC_ALL,"Portuguese");
    Node *head = NULL;

    insertAtBeginning(&head,10);
    insertAtBeginning(&head,20);
    insertAtBeginning(&head,25);
    insertAtBeginning(&head,30);
    insertAtBeginning(&head,35);
    insertAtBeginning(&head,40);

    // Mostrando a lista Original
    printf("*** Lista Original ***\n\n\n"); 
    printList(head); // Imprimindo a lista
    removeFromList(&head, 20); // Removendo o elemento 20 da lista

    // Imprimindo a lista após a remoção de um elemento
    printf("*** Lista após a remoção do elemento 20 ***\n\n\n");
    printList(head);

    // Procurando um elemento na lista
    Node *searchResult = searchInList(head, 10);
    if(searchResult != NULL){
        printf("\nO elemento 10 foi encontrado com sucesso!!!");
    }
    else{
        printf("\nO elemento 10 não foi encontrado!!!");
    }
    // Liberando a memória alocada 
    while (head != NULL){
        Node *temp = head;
        head = head->next;
        free(temp);
	}
}
