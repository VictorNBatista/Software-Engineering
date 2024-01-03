#include <stdio.h>
#include <locale.h>
#define SIZE 5

void preencherMatriz(int matriz[][SIZE]);
void exibirMatriz(int matriz[][SIZE]);

main() {
	setlocale(LC_ALL,"Portuguese");
    int matriz[SIZE][SIZE];

    preencherMatriz(matriz);
    printf("\n");

    exibirMatriz(matriz);
    printf("\n");

}

void preencherMatriz(int matriz[][SIZE]) {
    int i, j, valor;
    int numeros_multiplos_5[SIZE * SIZE]; 
    int numeros_multiplos_11[SIZE * SIZE]; 
    int numeros_multiplos_13[SIZE * SIZE]; 
    int qtde_multiplos_5 = 0;
    int qtde_multiplos_11 = 0;
    int qtde_multiplos_13 = 0;

    printf("Digite os valores maiores que zero para preencher a matriz:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            do {
                printf("Valor [%d][%d]: ", i, j);
                scanf("%d", &valor);
            } while (valor <= 0);

            if (valor % 5 == 0) {
                numeros_multiplos_5[qtde_multiplos_5] = valor;
                qtde_multiplos_5++;
            } else if (valor % 11 == 0) {
                numeros_multiplos_11[qtde_multiplos_11] = valor;
                qtde_multiplos_11++;
            } else if (valor % 13 == 0) {
                numeros_multiplos_13[qtde_multiplos_13] = valor;
                qtde_multiplos_13++;
            } else {
                printf("Número inválido! Digite novamente.\n");
                j--;  // Repetir a leitura do valor para a mesma posição
            }
        }
    }

    // Arrumar as posições na matriz
    int index_multiplos_5 = 0;
    int index_multiplos_11 = 0;
    int index_multiplos_13 = 0;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (i == j && index_multiplos_5 < qtde_multiplos_5) {
                matriz[i][j] = numeros_multiplos_5[index_multiplos_5];
                index_multiplos_5++;
            } else if (i < j && index_multiplos_11 < qtde_multiplos_11) {
                matriz[i][j] = numeros_multiplos_11[index_multiplos_11];
                index_multiplos_11++;
            } else if (i > j && index_multiplos_13 < qtde_multiplos_13) {
                matriz[i][j] = numeros_multiplos_13[index_multiplos_13];
                index_multiplos_13++;
            }
        }
    }
}

void exibirMatriz(int matriz[][SIZE]) {
    int i, j;
    printf("\nMatriz:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }
}


