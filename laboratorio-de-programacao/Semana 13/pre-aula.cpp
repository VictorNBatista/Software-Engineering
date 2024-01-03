#include <stdio.h>
#include <locale.h>
#define LINHAS 3
#define COLUNAS 6

void preencherMatriz(int matriz[LINHAS][COLUNAS]);
void somarLinhas(const int matriz[LINHAS][COLUNAS], int somaLinhas[LINHAS]);
void multiplicarMatriz(int matriz[LINHAS][COLUNAS], const int somaLinhas[LINHAS]);
void exibirMatriz(const int matriz[LINHAS][COLUNAS]);

main() {
	setlocale(LC_ALL,"Portuguese");
    int matriz[LINHAS][COLUNAS];
    int somaLinhas[LINHAS];

    printf("Preenchendo a matriz:\n");
    preencherMatriz(matriz);

    printf("\nSomando as linhas:\n");
    somarLinhas(matriz, somaLinhas);

    printf("\nMultiplicando a matriz pelas somas das linhas:\n");
    multiplicarMatriz(matriz, somaLinhas);

    printf("\nMatriz resultante:\n");
    exibirMatriz(matriz);

}

void preencherMatriz(int matriz[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("Digite o valor para a posição [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void somarLinhas(const int matriz[LINHAS][COLUNAS], int somaLinhas[LINHAS]) {
    for (int i = 0; i < LINHAS; i++) {
        int soma = 0;
        for (int j = 0; j < COLUNAS; j++) {
            soma += matriz[i][j];
        }
        somaLinhas[i] = soma;
        printf("Soma da linha %d: %d\n", i + 1, soma);
    }
}

void multiplicarMatriz(int matriz[LINHAS][COLUNAS], const int somaLinhas[LINHAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            matriz[i][j] *= somaLinhas[i];
        }
    }
}

void exibirMatriz(const int matriz[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

