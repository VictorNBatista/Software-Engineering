#include <stdio.h>
#include <math.h>
#include <locale.h>

int tamanho = 5;
void preencher_vetor(int vetor[], int tamanho);
void ordenar_vetor(int vetor[], int tamanho);
void juntar_vetores(int vetor1[], int vetor2[], int tamanho, int resultado[]);
void imprimir_vetor(int vetor[], int tamanho);

main()
{
	setlocale(LC_ALL,"Portuguese");
	int vetor1[tamanho], vetor2[tamanho], vetor3[tamanho*2];
	
	printf("Preenchendo o vetor 1:\n");
    preencher_vetor(vetor1, tamanho);
    printf("Preenchendo o vetor 2:\n");
    preencher_vetor(vetor2, tamanho);
    ordenar_vetor(vetor1, tamanho);
    ordenar_vetor(vetor2, tamanho);
    juntar_vetores(vetor1, vetor2, tamanho, vetor3);
    printf("\nVetor 3 com a junção dos vetores 1 e 2 ordenado: ");
    imprimir_vetor(vetor3, 10);
}

void preencher_vetor(int vetor[], int tamanho){
	for(int i=0;i<tamanho;i++){
		printf("Digite o valor para a posição %d: ", i);
        scanf("%d", &vetor[i]);
	}
}

void imprimir_vetor(int vetor[], int tamanho){
	
	for(int i=0;i<tamanho;i++){
		printf("%i ",vetor[i]);
	}
}

void ordenar_vetor(int vetor[], int tamanho) {
    int i, j, aux;
    for (i = 0; i < tamanho-1; i++) {
        for (j = i+1; j < tamanho; j++) {
            if (vetor[i] < vetor[j]) {
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}

void juntar_vetores(int vetor1[], int vetor2[], int tamanho, int resultado[]) {
    int i;
    for (i = 0; i < tamanho; i++) {
        resultado[i] = vetor1[i];
    }
    for (i = tamanho; i < tamanho*2; i++) {
        resultado[i] = vetor2[i-tamanho];
    }
    ordenar_vetor(resultado, tamanho*2);
    
}
