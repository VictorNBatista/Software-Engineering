/*

** Pilhas **

São um conjunto de dados m que só é possível inserir
um novo elemento no topo da pilha, e só pode remover
um elemento do topo da pilha.
É uma estrutura semelhante a uma lista, só que em pilha é utilizado
o conceitom de LIFO - Last In, First Out - último elemento que entra
é o primeiro a sair.

Uma estrutura do tipo pilha tem as seguintes operações a ser implementadas:

* push - Insere um dado na pilha, pode-se chamar também de "empilhar"
* pop - Retira um dado da pilha, pode-se chamar de "desempilhar"

*/

#include<stdio.h>
#include<stdlib.h>

#define Tam_Pilha 100

// Estrutura que irá conter a pilha com o topo e o vetor de itens
struct pilha{
	int topo;
	int itens[Tam_Pilha];
};

int empty(struct pilha *p){
	if(p->topo == -1){
		return 1;
	}
	return 0;
}

// Retorna um elemento do topo da pilha
int pop(struct pilha *p){
	if(empty(p)){
		printf("\n Pilha Vazia");
		exit(1);
	}
	//retorna o item do topo da pilha atual e diminui a posição
	return (p->itens[p->topo--]);
}

//Inclui um elemento no topo da pilha
void push(struct pilha *p, int n_iten){
	if(p->topo == (Tam_Pilha -1)){
		printf("\n Estouro da Pilha");
		exit(1);
	}
	//após verificar se não gaberia estouro da capacidade da pilha,
	//é criado uma nova posição na pulha e o elemento é armazenado.
	p->itens[++(p->topo)] = n_iten;
	return;
}

//retorna o tamanho da pilha
int size(struct pilha *p){
	//é bom lembrar que em C, o primeiro elemento de um vetor está inserido no
	//índice zero.
	return p->topo + 1;
}

//retorna o elemento do topo da pilha
int stackpop(struct pilha *p){
	return p->itens[p->topo];
}

//Porgrama principal
main(){
	struct pilha x;
	x.topo = -1;
	
	//inserindo elementos na pilha
	push(&x, 1);
	push(&x, 2);
	push(&x, 3);
	push(&x, 4);
	push(&x, 5);
	
	//mostrando o tamanho da pilha
	printf("\n Tamanho da Pilha: %d.",size(&x));
	printf("\n O elemento %d está no topo da Pilha.", stackpop(&x));
	
	//mostrando os elementos
	printf("\n Removedo %d...", pop(&x));
	printf("\n Removedo %d...", pop(&x));
	printf("\n Removedo %d...", pop(&x));
	printf("\n Removedo %d...", pop(&x));
	printf("\n O elemento %d está no topo da Pilha.", stackpop(&x));
}
