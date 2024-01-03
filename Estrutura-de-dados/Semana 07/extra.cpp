#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>

typedef struct{
	int entrada;
	int atendimento;
}Cliente;

main(){
	setlocale(LC_ALL,"Portuguese");
	srand(time(NULL));
	
	int tempo_simulacao = 720;
	int intervalo_entrada = 4;
	int intervalo_atendimento = 4;
	
	int max_clt_fila = 0;
	int espera_max = 0;
	
	Cliente fila[1000];
	
	int tempo_atual = 0;
	
	printf("-------------------------------------------------------------------------\n");
	printf("***Simulação com o intervalo de espera e atendimento de 1 a 4 minutos***");
	printf("\n-------------------------------------------------------------------------\n");
	//Determinando o minuto de chegada do primeiro cliente
	int primeiro_entrada = (rand() % 4) + 1;
	tempo_atual = primeiro_entrada;
	
	while(tempo_atual < tempo_simulacao){
		//Verificando chegada do proximo cliente
		if(rand() % intervalo_entrada == 0){
			fila[max_clt_fila].entrada = tempo_atual;
			fila[max_clt_fila].atendimento = (rand() % intervalo_atendimento) + 1;
			max_clt_fila++; 
		}
		//Atendendo prox cliente, quando possivel
		if (max_clt_fila > 0){
			if(tempo_atual - fila[0].entrada >= fila[0].atendimento){
				int espera = tempo_atual - fila[0].entrada;
				espera_max = (espera > espera_max) ? espera : espera_max;
				for(int i=0;i<max_clt_fila - 1;i++){
					fila[i] = fila[i+1];
				}
				max_clt_fila--;
			}
		}
		
		//Determinando o tempo de conclusao do atendimento do cliente
		if(max_clt_fila > 0){
			int tempo_conclusao = tempo_atual + rand() % intervalo_atendimento + 1;
			tempo_atual = tempo_conclusao;
		} else{
			tempo_atual++;
		}
	}
	
	printf("Número máximo de clientes na fila: %d\n", max_clt_fila);
	printf("Espera máxima experimentada por um cliente: %d minutos",espera_max);
	printf("\n-------------------------------------------------------------------------\n");
	
	//Mudando o intervalo para 1 a 3 minutos
	intervalo_entrada = 3;
	intervalo_atendimento = 3;
	max_clt_fila = 0;
	espera_max = 0;
	tempo_atual = 0;
	
	printf("\n\n-------------------------------------------------------------------------\n");
	printf("***Simulação com o intervalo de espera e atendimento de 1 a 3 minutos***");
	printf("\n-------------------------------------------------------------------------\n");
	
	//Repetindo a simulacao com os novos dados
	primeiro_entrada = (rand() % 3) + 1;
	tempo_atual = primeiro_entrada;
	
	while(tempo_atual < tempo_simulacao){
		//Verificando chegada do proximo cliente
		if(rand() % intervalo_entrada == 0){
			fila[max_clt_fila].entrada = tempo_atual;
			fila[max_clt_fila].atendimento = (rand() % intervalo_atendimento) + 1;
			max_clt_fila++; 
		}
		//Atendendo prox cliente, quando possivel
		if (max_clt_fila > 0){
			if(tempo_atual - fila[0].entrada >= fila[0].atendimento){
				int espera = tempo_atual - fila[0].entrada;
				espera_max = (espera > espera_max) ? espera : espera_max;
				for(int i=0;i<max_clt_fila - 1;i++){
					fila[i] = fila[i+1];
				}
				max_clt_fila--;
			}
		}
		
		//Determinando o tempo de conclusao do atendimento do cliente
		if(max_clt_fila > 0){
			int tempo_conclusao = tempo_atual + rand() % intervalo_atendimento + 1;
			tempo_atual = tempo_conclusao;
		} else{
			tempo_atual++;
		}
	}
	
	printf("Novo número máximo de clientes na fila: %d\n", max_clt_fila);
	printf("Nova espera máxima experimentada por um cliente: %d minutos",espera_max);
	printf("\n-------------------------------------------------------------------------\n");
}
















