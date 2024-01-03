//Lista duplamente encadeada
#include<stdio.h>
#include<stdlib.h>

struct nodo{
	int inf;
	struct nodo *ant;
	struct nodo *prox;
};

main(){
	struct nodo *inicio = NULL, *temp, *p;
	int v;
	
	//Inserindo valores na lista até digitar o valor zero
	while(1){
		printf("\nDigite um valor para ser inserido na lista: ");
		scanf("%i",&v);
		
		//testando se o valor digitado é zero
		if(v==0)
			break;
			
		//novo nodo será inserido na lista
		temp = (struct nodo*) malloc (sizeof(struct nodo));
		temp->inf = v;
		temp->prox = NULL;
		
		//testando se a lista está vazia
		if(inicio == NULL){
			inicio = temp;
			temp->ant = temp->prox = NULL;
		}
		else{
			//percorrendo a lista
			p = inicio;
			while(p->prox != NULL && p->inf != v){
				p = p->prox;
			}
			if(p->inf != v){
				p->prox = temp;
				temp->ant = p;
			}
		}
	}
	//mostrando a lista
	p = inicio;
	while(p != NULL){
		printf("%i ",p->inf);
		p = p->prox;
	}
	printf("\n\n");
}
