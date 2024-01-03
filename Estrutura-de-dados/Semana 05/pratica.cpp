/*
	Listas Lineares Sequenciais ->Vetores
		Organiza os elementos de forma squencial, eles ficam aramazenados
		em posi��es cont�guas na mem�ria. Neste tipo de lista � interessante
		que se saiba a quantidade de elementos que ser�o aramazenados antes de
		realizar qualquer tipo de opera��o.
		
	
	Listas Lineares Encadeadas
		� um conjunto de linear de estruturas que s�o autoreferenciadas, chamadas
		de N�S (nodos), que s�o conectados por links (liga��es ou encadeamentos) de
		ponteiros. Ela � acessada por meio de um ponteiro que aponta para o primeiro
		n� da lista. Os n�s subsequentes s�o acessados por meio de ponteiro de liga��o
		que existe em cada n�.
		
		Tipos de listas que iremos estudar:
			Filas - FIFO (first in - first out)
			Pilhas - LIFO (last in - first out)
			listas duplamente encadeadas
			listas circulares
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Criando uma estrutura de n� da lista
typedef struct Node{
	char data;
	struct Node* next;
}Node;
//****************************************

//Fun��o para criar um novo N�
Node* createNode(char data){
	Node* newNode = (Node*)malloc(sizeof(Node));
	if(newNode == NULL){
		printf("Erro ao alocar mem�ria para o N�.");
		exit(EXIT_FAILURE);
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
//******************************************

// Fun��o para INSERIR um novo n� no in�cio lista
void insertAtBeginning(Node** head, char data){
	Node* newNode = createNode(data);
	newNode->next = *head;
	*head = newNode;
}
//******************************************

//Fun��o para REMOVER um n� da lista
void removeFromList(Node** head, char data){
	Node* currentNode = *head;
	Node* prevNode    = NULL;
	
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
		prevNode    = currentNode;
		currentNode = currentNode->next;
	}
	printf("O elemento %c n�o foi encontrado na lista. \n",data);
}

//Fun��o para buscar um elemento na lista
Node* searchInList(Node* head, char data){
	Node* currentNode = head;
	
	while(currentNode != NULL){
		if(currentNode->data == data){
			return currentNode;
		}
		currentNode = currentNode->next;
	}
	return NULL;
}
//************************************************

//Fun��o para imprimir a lista
void printList(Node* head){
	Node* currentNode = head;
	
	while(currentNode != NULL){
		printf("[%c]-> ",currentNode->data);
		currentNode = currentNode->next;
	}
	printf("NULL \n");
}
//************************************************

//Fun��o principal
main(){
	setlocale(LC_ALL,"Portuguese");
	Node* head = NULL;
	char letra,remov;
	
	printf("Digite todas as letras do alfabeto(d� enter ao adicionar uma letra): \n");
	for(int i=0;i<3;i++){
		scanf(" %c",&letra);
		insertAtBeginning(&head,letra);
	}
	
	printf("*** Lista Original ***\n");
	printList(head); //Imprimindo a lista
	
	//Escolhendo elemento para ser removido da lista
	printf("\nEscolha um elemento para retirar da lista: ");
	scanf(" %c",&remov);
	removeFromList(&head, remov);
	
	
	// Imprimindo a lista ap�s a remo��o de um elemento
	printf("*** Lista Ap�s Remo��o do elemento %c ***\n",remov);
	printList(head);
	
	// Liberando a mem�ria alocada
	while(head != NULL){
		Node* temp = head;
		head = head->next;
		free(temp);
	}
}
