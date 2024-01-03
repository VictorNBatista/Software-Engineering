#include <stdio.h>
#include <math.h>
#include <locale.h>

void preencher_vetor(int vetor[], int tamanho);
void mostrar_vetor(int vetor[], int tamanho);
float encontrar_maior(int vetor[], int tamanho);
void dividir_elementos(int vetor[], int tamanho);

main()
{
	setlocale(LC_ALL,"Portuguese");
	int vetor[15];
	printf("Preenchendo o vetor... \n");
	preencher_vetor(vetor, 15);
	mostrar_vetor(vetor, 15);
	printf("\n\nDivindo os valores do vetor pelo maior elemento... \n");
	dividir_elementos(vetor, 15);
	  
}

void preencher_vetor(int vetor[], int tamanho){
    for (int i = 0; i < tamanho; i++) {
        printf("Digite o valor para a posição %d: ", i);
        scanf("%d", &vetor[i]);
    }
}

void mostrar_vetor(int vetor[], int tamanho){
	printf("Vetor digitado: ");
	for (int i = 0; i < tamanho; i++) {
        printf("%i ", vetor[i]);
    }
}

float encontrar_maior(int vetor[], int tamanho){
	float maior;
	maior = vetor[0];
	for(int i=0; i<tamanho;i++){
		if (vetor[i]>maior)
		maior = vetor[i];
	}
	return maior;
}

void dividir_elementos(int vetor[], int tamanho){
	float maior;
	float conta[tamanho];
	maior= encontrar_maior(vetor, tamanho);
	for(int i=0; i<tamanho;i++){
		conta[i] = vetor[i] / maior;
	}
	printf("Novo vetor após a divisão: ");
	for(int i=0; i<tamanho;i++){
		printf("%.2f ",conta[i]);
	}
}
