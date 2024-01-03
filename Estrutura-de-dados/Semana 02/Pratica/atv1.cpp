#include<stdio.h>
#include<stdlib.h>


main(){
	int tam, NovoTam;
	float md;
	
	printf("Digite a quantidade de alunos que terao a nota inserida: ");
	scanf("%i",&tam);
	
	float *notas = (float *)malloc(tam * sizeof(float));
	
	if(notas == NULL){
		printf("ERRO na Alocacao da Memoria");
		return 1;
	}
	
	printf("\nRecebendo as notas...\n");
	for(int i=0; i<tam; i++){
		printf("Nota aluno %i: ",i+1);
		scanf("%f",&notas[i]);
	}
	
	printf("\nMostrando as notas...\n");
	for(int i=0; i<tam; i++){
		printf("Nota aluno %i: %.2f\n",i+1,notas[i]);
	}
	
	printf("\nCalculando media...\n");
		float soma=0;
		for(int i=0; i<tam; i++){
			soma += notas[i];
		}
		md = soma/tam;
		printf("\nA media dos alunos eh: %.2f",md);
	
	int op;
	printf("\nGostaria de inserir mais notas (1-Sim/2-Nao) ?\n");
	scanf("%i",&op);
	
	switch(op){
		case 1:
		{	
			printf("Digite a nova quantidade de alunos: ");
			scanf("%i",&NovoTam);
			float *NovasNotas = (float *)realloc(notas, NovoTam * sizeof(float));
			if(NovasNotas == NULL){
			printf("ERRO na Alocacao da Memoria");
			return 1;
			}
			
			notas = NovasNotas;
			
			printf("Digite as novas notas: \n");
			for(int i=tam; i<NovoTam; i++){
			printf("Nota aluno %i: ",i+1);
			scanf("%f",&notas[i]);
			}
			
			for(int i=tam; i<NovoTam; i++){
			printf("Nota aluno %i: %.2f\n",i+1,notas[i]);
			}
			
			printf("\nCalculando nova media...\n");
			float soma=0;
			for(int i=0; i<NovoTam; i++){
				soma += notas[i];
			}
			md = soma/NovoTam;
			printf("\nA nova media dos alunos eh: %.2f",md);
			break;
		}	
			
		case 2:
			break;
	}
	
	//liberando a memoria alocada
	free(notas);
}

