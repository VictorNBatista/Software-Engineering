/*
	Estruturas de Dados - FILA
	
	Filas são um tipo de ED em que só se é possível inserir um novo elemento no final da fila
	e só se pode remover um elemento do início da fila.
	
	Fila é uma estrutura do tipo LISTA, e se assemelha com uma pilha, só que em uma fila é utilizado
	o conceito de FIFO - First in, First out - Primeiro elemento que entra é o primeiro elemento a sair.
	
	1 - pode ser aplicado para modelar decolagens de aviões que aguardam a decolagem
	2 - pode ser utilizado em pacotes de dados de espera para serem transmitidos pela rede
	3 - pode ser utilizado também em fila de impressoras, na qual os serviços de impressão aguardam impressão ficar disponível.
	
	Operações em Fila:
		a - Inserir na Fila
		b - Remover na Fila
		c - Mostrar a Fila
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Criando a estrutura para representar uma FILA
struct Node{
	int dado;
	struct Node* prox;
};

//Criando a estrutura da Fila (Queue)
struct Fila{
	struct Node* frente;
	struct Node* tras;
};

//Estrutura para criar uma fila vazia
struct Fila* criaFila(){
	struct Fila* fila = (struct Fila*)malloc(sizeof(struct Fila));
	fila->frente = fila->tras = NULL;
	return fila;
}
//*****************************************************************
//Protótipos das Funções
//*****************************************************************
int filaVazia(struct Fila* fila);
void insereFila(struct Fila* fila, int item);
void mostraUltElemento(struct Fila* fila);
void mostrarFila(struct Fila* fila);
void limpaFila(struct Fila* fila);

//*****************************************************************
//Função Principal
//*****************************************************************
main(){
	setlocale(LC_ALL,"Portuguese");
	
	struct Fila* fila = criaFila();
	int op, item;
	
	do{
		printf("*** Menu de Opções***\n");
		printf("1. Inserir um Item na Fila.\n");
		printf("2.Mostrar Item da Frente da Fila. \n");
		printf("3. Mostrar Fila.\n");
		printf("4. Excluir Item da frente da Fila.\n");
		printf("5. Sair \n");
		printf("Escolha uma opção.\n");
		scanf("%d",&op);
		
		switch(op){
			case 1:
				printf("Digite um Elemento a ser inserido: ");
				scanf("%d",&item);
				insereFila(fila, item);
				break;
			case 2:
				mostraUltElemento(fila);
				break;
			case 3:
				mostrarFila(fila);
				break;
			case 4:
				limpaFila(fila);
				break;
			case 5:
				printf("Saindo do Sistema... ... ...");
				break;
			default:
				printf("Opção Inválida, digite uma opção válida");					
		}
	}while(op != 5);
	//limpando a memória alocada para a Fila
	while(!filaVazia(fila)){
		limpaFila(fila);
	}
	free(fila);
}
//*****************************************************************
//Função para Verificar se Fila está Vazia
//*****************************************************************
int filaVazia(struct Fila* fila){
	return(fila->frente == NULL);
}
//*****************************************************************
//Função para inserir um elemento na fila
//*****************************************************************
void insereFila(struct Fila* fila, int item){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->dado = item;
	newNode->prox = NULL;
	//verificando se a fila está vazia
	if(filaVazia(fila)){
		fila->frente = fila->tras = newNode;
	}
	else{
		fila->tras->prox = newNode;
		fila->tras       = newNode;
	}
	printf("*** Item %d inserido na Fila. \n",item);
}
//*****************************************************************
//Função para Mostrar o primeiro elemento na Fila
//*****************************************************************
void mostraUltElemento(struct Fila* fila){
	//verificando se a fila está vazia
	if(filaVazia(fila)){
		printf(" A Fila estpa Vazia!!!\n");
	}
	else{
		printf("O Item da Frente da fila é: %d. \n",fila->frente->dado);
	}
}
//*****************************************************************
//Função para Motrar a Fila
//*****************************************************************
void mostrarFila(struct Fila* fila){
	//veriica se a fila está vazia
	if(filaVazia(fila)){
		printf("A Fila está Vazia!!!");
	}
	else{
		struct Node* atual = fila->frente;
		printf("*** Elementos na Fila ***\n");
		while(atual != NULL){
			printf("%d",atual->dado);
			atual = atual->prox;
		}
		printf("\n");
	}
}

//*****************************************************************
//Função para Excluir um elemento da Fila
//*****************************************************************
void limpaFila(struct Fila* fila){
	//verifica se a fila está vazia
	if(filaVazia(fila)){
		printf("A Fila está Vazia. Não existem mais itens para excluir. \n");	
	}
	else{
		struct Node* temp = fila->frente;
		fila->frente = fila->frente->prox;
		printf(" Item %d removido da Fila.!!! \n",temp);
		free(temp);
	}
}
