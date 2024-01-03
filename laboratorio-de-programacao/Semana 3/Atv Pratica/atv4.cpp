#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>
#define LINHAS 10
#define COLUNAS 5

void ler_matriz(float matriz[][COLUNAS], int linhas, int colunas);
float soma_sexta_linha(float matriz[][COLUNAS], int linhas, int colunas);

int main() {
    float matriz[LINHAS][COLUNAS];
    float soma;
    
    ler_matriz(matriz, LINHAS, COLUNAS);
    
    soma = soma_sexta_linha(matriz, LINHAS, COLUNAS);
    
    // exibir o resultado
    printf("A soma dos elementos abaixo da sexta linha da matriz e: %.2f\n", soma);
    
    return 0;
}

void ler_matriz(float matriz[][COLUNAS], int linhas, int colunas) {
    int i, j;
    
    printf("Informe os elementos da matriz %dx%d:\n", linhas, colunas);
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("matriz[%d][%d]: ", i, j);
            scanf("%f", &matriz[i][j]);
        }
    }
}

float soma_sexta_linha(float matriz[][COLUNAS], int linhas, int colunas) {
    int i, j;
    float soma = 0.0;
    
    for (i = 5; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            soma += matriz[i][j];
        }
    }
    
    return soma;
}
