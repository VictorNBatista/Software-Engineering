#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>
#define N 8

main()
{
 setlocale(LC_ALL, "Portuguese");
  int i, j, k, num, vetor[N];

  printf("Por favor, insira %d números inteiros:\n", N);

  // Preencher o vetor com os números fornecidos pelo usuário
  for (i = 0; i < N; i++) {
    scanf("%d", &num);

    // Encontrar a posição correta para inserir o número
    for (j = 0; j < i; j++) {
      if (num < vetor[j]) {
        break;
      }
    }

    // Deslocar os elementos subsequentes para a direita
    for (k = i; k > j; k--) {
      vetor[k] = vetor[k - 1];
    }

    // Inserir o número na posição correta
    vetor[j] = num;
  }

  printf("O vetor está ordenado da seguinte forma:\n");

  // Imprimir o vetor ordenado
  for (i = 0; i < N; i++) {
    printf("%d ", vetor[i]);
  }

  printf("\n");

  return 0;
}

