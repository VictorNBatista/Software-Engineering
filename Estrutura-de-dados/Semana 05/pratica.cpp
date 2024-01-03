/*
	Listas Lineares Sequenciais ->Vetores
		Organiza os elementos de forma squencial, eles ficam aramazenados
		em posições contíguas na memória. Neste tipo de lista é interessante
		que se saiba a quantidade de elementos que serão aramazenados antes de
		realizar qualquer tipo de operação.
		
	
	Listas Lineares Encadeadas
		é um conjunto de linear de estruturas que são autoreferenciadas, chamadas
		de NÓS (nodos), que são conectados por links (ligações ou encadeamentos) de
		ponteiros. Ela é acessada por meio de um ponteiro que aponta para o primeiro
		nó da lista. Os nós subsequentes são acessados por meio de ponteiro de ligação
		que existe em cada nó.
		
		Tipos de listas que iremos estudar:
			Filas - FIFO (first in - first out)
			Pilhas - LIFO (last in - first out)
			listas duplamente encadeadas
			listas circulares
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Criando uma estrutura de nó da lista
typedef struct Node{
	char data;
	struct Node* next;
}Node;
//****************************************

//Função para criar um novo Nó
Node* createNode(char data){
	Node* newNode = (Node*)malloc(sizeof(Node));
	if(newNode == NULL){
		printf("Erro ao alocar memória para o Nó.");
		exit(EXIT_FAILURE);
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
//******************************************

// Função para INSERIR um novo nó no início lista
void insertAtBeginning(Node** head, char data){
	Node* newNode = createNode(data);
	newNode->next = *head;
	*head = newNode;
}
//******************************************

//Função para REMOVER um nó da lista
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
	printf("O elemento %c não foi encontrado na lista. \n",data);
}

//Função para buscar um elemento na lista
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

//Função para imprimir a lista
void printList(Node* head){
	Node* currentNode = head;
	
	while(currentNode != NULL){
		printf("[%c]-> ",currentNode->data);
		currentNode = currentNode->next;
	}
	printf("NULL \n");
}
//************************************************

//Função principal
main(){
	setlocale(LC_ALL,"Portuguese");
	Node* head = NULL;
	char letra,remov;
	
	printf("Digite todas as letras do alfabeto(dê enter ao adicionar uma letra): \n");
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
	
	
	// Imprimindo a lista após a remoção de um elemento
	printf("*** Lista Após Remoção do elemento %c ***\n",remov);
	printList(head);
	
	// Liberando a memória alocada
	while(head != NULL){
		Node* temp = head;
		head = head->next;
		free(temp);
	}
}
