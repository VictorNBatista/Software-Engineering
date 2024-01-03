#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define MAX_PAGES 20

typedef struct{
	int timestamp;
	int pages;
}Tarefa;

typedef struct{
	Tarefa *fila;
	int tamanho;
	int frente, tras;
}Fila;

void inicializarFila(Fila *fila, int tamanho){
	fila->tamanho = tamanho;
	fila->fila = (Tarefa *)malloc(tamanho * sizeof(Tarefa));
	fila->frente = fila->tras = -1;
}

int filaVazia(Fila *fila){
	return fila->frente == -1;
}

int filaCheia(Fila *fila){
	return (fila->tras + 1) % fila->tamanho == fila->frente;
}

void enfileirar(Fila *fila, Tarefa tarefa, int segundoAtual){
	if(!filaCheia(fila)){
		if(filaVazia(fila))
		fila->frente = 0;
		
		fila->tras = (fila->tras + 1) % fila->tamanho;
		fila->fila[fila->tras] = tarefa;
		fila->fila[fila->tras].timestamp = segundoAtual;
	}
	else{
		printf("A fila de impressão está cheia.\n");
	}
}

Tarefa desenfileirar(Fila *fila, int *tempoDeEspera){
	Tarefa tarefa = {0,0};
	if(!filaVazia(fila)){
		tarefa = fila->fila[fila->frente];
		if(fila->frente == fila->tras)
			fila->frente = fila->tras = -1;
		else
			fila->frente = (fila->frente + 1) % fila->tamanho;
			
		*tempoDeEspera = tarefa.timestamp;		
	}
	return tarefa;
}

int main(){
	setlocale(LC_ALL,"Portuguese");
	srand(time(NULL));
	int tempoDeSimulacao = 3600;
	
	Fila fila;
	inicializarFila(&fila, 100);
	
	int segundoAtual = 0;
	int tempoTotal = 0;
	int tarefasConcluidas = 0;
	
	while(segundoAtual < tempoDeSimulacao){
		segundoAtual++;
		
		if(rand() % 10 < 3){
			Tarefa tarefa;
			tarefa.pages = rand() % MAX_PAGES + 1;
			enfileirar(&fila, tarefa, segundoAtual);
		}
		
		if (!filaVazia(&fila)){
			int tempoDeEspera;
			Tarefa tarefa = desenfileirar(&fila, &tempoDeEspera);
			
			int tempoDeImpressao = tarefa.pages;
			while(tempoDeImpressao > 0){
				segundoAtual++;
				tempoDeImpressao--;
				
				if(tempoDeImpressao == 0){
					tempoTotal += (segundoAtual - tempoDeEspera);
					tarefasConcluidas++;
				}
			}
		}
	}
	
	if(tarefasConcluidas > 0){
		float tempoMedioDeEspera = (float)tempoTotal / tarefasConcluidas;
		printf("Tempo médio de espera: %.2f segundos\n", tempoMedioDeEspera);
	}
	else{
		printf("Nenhuma tarefa de impressão foi concluída.\n");
	}
	
	free(fila.fila);
}
