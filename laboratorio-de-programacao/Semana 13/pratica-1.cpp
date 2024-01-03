#include <stdio.h>
#include <locale.h>
#define TAMANHO 15

int ehPrimo(int numero);

main() {
	setlocale(LC_ALL,"Portuguese");
    int vetor[TAMANHO];
    int vetorResultante[TAMANHO];
    int contador = 0;

    printf("Digite os %d números inteiros:\n", TAMANHO);
    for (int i = 0; i < TAMANHO; i++) {
        scanf("%d", &vetor[i]);
    }

    printf("Números primos encontrados:\n");
    for (int i = 0; i < TAMANHO; i++) {
        if (ehPrimo(vetor[i])) {
            vetorResultante[contador] = vetor[i];
            printf("%d ", vetorResultante[contador]);
            contador++;
        }
    }

    printf("\n");

}

int ehPrimo(int numero) {
    if (numero <= 1) {
        return 0;
    }

    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) {
            return 0;
        }
    }

    return 1;
}

