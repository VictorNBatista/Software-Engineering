#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>

void substitui_negativos(int A[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (A[i] < 0) {
            A[i] = 0;
        }
    }
}

main()
{
 setlocale(LC_ALL, "Portuguese");
 int A[25];

    printf("Digite 25 números inteiros para o vetor A:\n");
    for (int i = 0; i < 25; i++) {
        scanf("%d", &A[i]);
    }

    printf("Vetor A original:\n");
    for (int i = 0; i < 25; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    substitui_negativos(A, 25);

    printf("Vetor A com os negativos substituídos por zero:\n");
    for (int i = 0; i < 25; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

}

