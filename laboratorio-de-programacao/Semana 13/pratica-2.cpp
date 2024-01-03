#include <stdio.h>
#include <locale.h>
#define TAMANHO 15

int encontrarMaiorValor(const int vetor[], int tamanho);
void dividirPorMaiorValor(const int vetor[], int tamanho, double resultado[]);

int main() {
	setlocale(LC_ALL,"Portuguese");
    int vetor[TAMANHO];
    double vetorResultado[TAMANHO];

    printf("Digite os %d números inteiros:\n", TAMANHO);
    for (int i = 0; i < TAMANHO; i++) {
        scanf("%d", &vetor[i]);
    }

    int maiorValor = encontrarMaiorValor(vetor, TAMANHO);
    dividirPorMaiorValor(vetor, TAMANHO, vetorResultado);

    printf("Vetor resultante:\n");
    for (int i = 0; i < TAMANHO; i++) {
        printf("%.2f ", vetorResultado[i]);
    }
    printf("\n");

    return 0;
}

int encontrarMaiorValor(const int vetor[], int tamanho) {
    int maior = vetor[0];
    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
    }
    return maior;
}

void dividirPorMaiorValor(const int vetor[], int tamanho, double resultado[]) {
    int maiorValor = encontrarMaiorValor(vetor, tamanho);
    for (int i = 0; i < tamanho; i++) {
        resultado[i] = (double)vetor[i] / maiorValor;
    }
}

