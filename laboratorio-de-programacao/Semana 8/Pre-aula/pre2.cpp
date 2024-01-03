#include<stdio.h>
#include<math.h>
#include<locale.h>

void preencher_matriz(int matriz[][7]);
void encontrar_maior_linha(int matriz[][7], int vetor[]);
void encontrar_menor_coluna(int matriz[][7], int vetor[]);
void imprimir_matriz(int matriz[][7]);
void imprimir_vetor(int vetor[], int tamanho);

main() {
	setlocale(LC_ALL,"Portuguese");
    int matriz[7][7], maior_elemento_linha[7], menor_elemento_coluna[7];
    preencher_matriz(matriz);
    encontrar_maior_linha(matriz, maior_elemento_linha);
    encontrar_menor_coluna(matriz, menor_elemento_coluna);
    printf("Matriz:\n");
    imprimir_matriz(matriz);
    printf("Maior elemento de cada linha: ");
    imprimir_vetor(maior_elemento_linha, 7);
    printf("Menor elemento de cada coluna: ");
    imprimir_vetor(menor_elemento_coluna, 7);
}

void preencher_matriz(int matriz[][7]) {
    int i, j;
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 7; j++) {
            printf("Digite o valor para a posição [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void encontrar_maior_linha(int matriz[][7], int vetor[]) {
    int i, j;
    for (i = 0; i < 7; i++) {
        int maior = matriz[i][0];
        for (j = 1; j < 7; j++) {
            if (matriz[i][j] > maior) {
                maior = matriz[i][j];
            }
        }
        vetor[i] = maior;
    }
}

void encontrar_menor_coluna(int matriz[][7], int vetor[]) {
    int i, j;
    for (j = 0; j < 7; j++) {
        int menor = matriz[0][j];
        for (i = 1; i < 7; i++) {
            if (matriz[i][j] < menor) {
                menor = matriz[i][j];
            }
        }
        vetor[j] = menor;
    }
}

void imprimir_matriz(int matriz[][7]) {
    int i, j;
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 7; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void imprimir_vetor(int vetor[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}
