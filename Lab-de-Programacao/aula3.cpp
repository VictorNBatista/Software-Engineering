#include<stdio.h>
#include<stdlib.h>

main(){
	
	int tam;
	
	//Solicitando ao usuário o tamanho para alocacao
	printf("Digite o tamanho do vetor: ");
	scanf("%d",&tam);
	
	//alocando a memoria
	int *vetDinamico = (int *)malloc(tam * sizeof(int));
	
	//verificando a disponibilidade de alocacao da memoria
	if(vetDinamico == NULL){
		printf("ERRO na Alocacao da Memoria");
		return 1;
	}
	
	//preenchendo o vetor com valores inteiros
	printf("Digite os Elementos do Vetor: \n");
	for(int i=0;i<tam;i++){
		scanf("%d",&vetDinamico[i]);
	}
	
	//----------------------------------------//
	printf("Vetor Preenchido: \n");
	for(int i=0;i<tam;i++){
		printf("%i ",vetDinamico[i]);
	}
	printf("\n");
	
	//Liberando a memoria alocada
	free(vetDinamico);
}
