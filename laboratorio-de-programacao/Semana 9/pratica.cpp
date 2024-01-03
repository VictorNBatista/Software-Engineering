#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>
#define N 2

void contas_saldos(int contas[N], float saldos[N]);
void menu(int contas[N], float saldos[N]);

int verificarRepeticao(int contas[N], int valor, int indice) {
    for (int i = 0; i < indice; i++) {
        if (contas[i] == valor) {
            return 1; 
        }
    }
    return 0; 
}

int encontrarIndice(int contas[N], int valor, int indice) {
    for (int i = 0; i < indice; i++) {
        if (contas[i] == valor) {
            return i; 
        }
    }
    return -1; 
}

main()
{
 setlocale(LC_ALL, "Portuguese");
	int contas[N];
	float saldos[N];
	printf("*Bem vindo ao controle banc�rio*");
	printf("\n\nCadastre as contas e os saldos\n");
	contas_saldos(contas,saldos);
	menu(contas,saldos);
}

void contas_saldos(int contas[N], float saldos[N]){
	for (int i = 0; i < N; i++) {
        int codigo;
        printf("\n%i� Conta", i + 1);
        printf("\nC�digo: ");
        scanf("%i", &codigo);
        
        if (verificarRepeticao(contas, codigo, i)) {
            printf("O c�digo inserido j� existe. Insira um c�digo diferente.\n");
            i--; // Reverter a itera��o para inserir um novo valor
            continue; // Pular para a pr�xima itera��o
        }
        
        contas[i] = codigo;
        printf("Saldo: ");
        scanf("%f", &saldos[i]);
    }
}

void menu(int contas[N], float saldos[N]){
	int op=0;
	while(op != 4){
	printf("\n**MENU**");
	printf("\nSelecione o que deseja realizar"
			"\n1. Efetuar dep�sito"
			"\n2. Efetuar saque"
			"\n3. Consultar o ativo banc�rio (Somat�rio dos saldos de todos os clientes)"
			"\n4. Encerrar programa\n");
	scanf("%i",&op);
	
	switch(op){
		case 1:
		int codigo1,i;
		float deposito;	
		printf("C�digo da conta: ");
		scanf("%i",&codigo1);
		i = encontrarIndice(contas,codigo1,N);
		if (i != -1) {
		printf("Valor do dep�sito: ");
		scanf("%f",&deposito);	
        saldos[i] += deposito;
        printf("Saldo atual: R$%.2f\n",saldos[i]);
    	}
		else {
        printf("Esta conta n�o foi encontrada.\n");
        }
		break;	
	
	
		case 2:
		int codigo2,in;
		float saque;
		printf("C�digo da conta: ");
		scanf("%i",&codigo2);
		in = encontrarIndice(contas,codigo2,N);
		
		if (in != -1) {
		printf("Valor do saque: ");
		scanf("%f",&saque);
		
			if(saldos[in] >= saque){
			saldos[in] = saldos[in] - saque;
       		printf("Saldo atual: R$%.2f\n",saldos[in]);
			}
			else{
			printf("Saldo insuficiente.");
			}
				
    	}
		else {
        printf("Esta conta n�o foi encontrada.\n");
        }
        
		break;		


		case 3:
		float soma;
		soma=0;	
		for(int c=0; c<N; c++){
			soma + saldos[c];
		}
		printf("\nO ativo banc�rio � de: R$%.2f",soma);
		break;
		
		case 4:
		break;	
			
	}
	}		
}

