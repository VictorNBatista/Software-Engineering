/* 
    Listas Lineares Sequencias -> Vetores
        Organiza os elementos de forma sequencial, eles ficam armazenados em 
        posi��es contiguas na m�moria. Neste tipo de lista � interessante que se saiba 
        a quantidade de elementos que ser�o armazenados antes de realizar qualquer tipo de opera��o.

Listas Lineares Encadeadas
        � um conjunto de linear de estruturas que s�o autoreferenciadas, chamadas de N�S (nodos), 
        que s�o conectados por Links(liga��es ou encadeamentos) de ponteiros. Ela � acessada por meio 
        de um ponteiro que aponta para o primeiro n� da Lista. Os n�s subsequentes s�o acessados por meio 
        de ponteiro de liga��o que existe em cada n�.

        Tipos de listas que iremos estudar
            Filas -> fifo (First in - first out)
            Pilhas -> Lifo (Last in - first out)
            Listas duplamente encadeadas
            Listas circulares
*/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

// Criando uma estrutura de n� da lista
typedef struct Node{
    int data;
    struct Node *next;
}Node;
//********************************************
// Fun��o para criar um novo N�
Node *createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Erro ao alocar mem�ria para o N�.");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
//********************************************
// Fun��o para INSERIR um novo n� no in�cio da lista
void insertAtBeginning(Node **head, int data){
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}
//********************************************
// Fun��o para REMOVER um novo n� da lista
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
    printf("O Elemento %d n�o foi encontrado na lista. \n",data);
}
//********************************************
// Fun��o para buscar um elemento na lista
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
// Fun��o para imprimir a lista
void printList(Node *head){
    Node *currentNode = head;
    
    while(currentNode != NULL){
        printf("[%d]-> ",currentNode->data);
        currentNode = currentNode->next;
    }
    printf("NULL \n");
}
//********************************************
// Fun��o Principal
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

    // Imprimindo a lista ap�s a remo��o de um elemento
    printf("*** Lista ap�s a remo��o do elemento 20 ***\n\n\n");
    printList(head);

    // Procurando um elemento na lista
    Node *searchResult = searchInList(head, 10);
    if(searchResult != NULL){
        printf("\nO elemento 10 foi encontrado com sucesso!!!");
    }
    else{
        printf("\nO elemento 10 n�o foi encontrado!!!");
    }
    // Liberando a mem�ria alocada 
    while (head != NULL){
        Node *temp = head;
        head = head->next;
        free(temp);
	}
}
