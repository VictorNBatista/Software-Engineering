#include <stdio.h>
#include <locale.h>
#define SIZE 4

void preencherMatriz(int matriz[SIZE][SIZE]);
void mostrarMatriz(int matriz[SIZE][SIZE]);
void mostrarDP(int matriz[SIZE][SIZE]);
void mostrarDS(int matriz[SIZE][SIZE]);
void mostrarDPeDS(int matriz[SIZE][SIZE]);

int main()
{
	setlocale(LC_ALL,"Portuguese");
    int matriz[SIZE][SIZE];

    printf("Preenchendo a matriz...\n");
    preencherMatriz(matriz);

    printf("\nMatriz preenchida:\n");
    mostrarMatriz(matriz);

    printf("\nValores da Diagonal Principal:\n");
    mostrarDP(matriz);

    printf("\nValores da Diagonal Secundária:\n");
    mostrarDS(matriz);

    printf("\nValores da Diagonal Principal e Diagonal Secundária:\n");
    mostrarDPeDS(matriz);

    return 0;
}

void preencherMatriz(int matriz[SIZE][SIZE])
{
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            printf("Digite o valor para a posição [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void mostrarMatriz(int matriz[SIZE][SIZE])
{
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

void mostrarDP(int matriz[SIZE][SIZE])
{
    int i,j;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (i == j)
            {
                printf("%d\t", matriz[i][j]);
            }
            else
            {
                printf("\t");
            }
        }
        printf("\n");
    }
}

void mostrarDS(int matriz[SIZE][SIZE])
{
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (i + j == SIZE - 1)
            {
                printf("%d\t", matriz[i][j]);
            }
            else
            {
                printf("\t");
            }
        }
        printf("\n");
    }
}

void mostrarDPeDS(int matriz[SIZE][SIZE])
{
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (i == j || i + j == SIZE - 1)
            {
                printf("%d\t", matriz[i][j]);
            }
            else
            {
                printf("\t");
            }
        }
        printf("\n");
    }
}

