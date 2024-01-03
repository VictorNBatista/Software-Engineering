/*

** Pilhas **

S�o um conjunto de dados m que s� � poss�vel inserir
um novo elemento no topo da pilha, e s� pode remover
um elemento do topo da pilha.
� uma estrutura semelhante a uma lista, s� que em pilha � utilizado
o conceitom de LIFO - Last In, First Out - �ltimo elemento que entra
� o primeiro a sair.

Uma estrutura do tipo pilha tem as seguintes opera��es a ser implementadas:

* push - Insere um dado na pilha, pode-se chamar tamb�m de "empilhar"
* pop - Retira um dado da pilha, pode-se chamar de "desempilhar"

*/

#include<stdio.h>
#include<stdlib.h>

#define Tam_Pilha 100

// Estrutura que ir� conter a pilha com o topo e o vetor de itens
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
	//retorna o item do topo da pilha atual e diminui a posi��o
	return (p->itens[p->topo--]);
}

//Inclui um elemento no topo da pilha
void push(struct pilha *p, int n_iten){
	if(p->topo == (Tam_Pilha -1)){
		printf("\n Estouro da Pilha");
		exit(1);
	}
	//ap�s verificar se n�o gaberia estouro da capacidade da pilha,
	//� criado uma nova posi��o na pulha e o elemento � armazenado.
	p->itens[++(p->topo)] = n_iten;
	return;
}

//retorna o tamanho da pilha
int size(struct pilha *p){
	//� bom lembrar que em C, o primeiro elemento de um vetor est� inserido no
	//�ndice zero.
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
	printf("\n O elemento %d est� no topo da Pilha.", stackpop(&x));
	
	//mostrando os elementos
	printf("\n Removedo %d...", pop(&x));
	printf("\n Removedo %d...", pop(&x));
	printf("\n Removedo %d...", pop(&x));
	printf("\n Removedo %d...", pop(&x));
	printf("\n O elemento %d est� no topo da Pilha.", stackpop(&x));
}
