#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>
#define N 8

main()
{
 setlocale(LC_ALL, "Portuguese");
  int i, j, k, num, vetor[N];

  printf("Por favor, insira %d n�meros inteiros:\n", N);

  // Preencher o vetor com os n�meros fornecidos pelo usu�rio
  for (i = 0; i < N; i++) {
    scanf("%d", &num);

    // Encontrar a posi��o correta para inserir o n�mero
    for (j = 0; j < i; j++) {
      if (num < vetor[j]) {
        break;
      }
    }

    // Deslocar os elementos subsequentes para a direita
    for (k = i; k > j; k--) {
      vetor[k] = vetor[k - 1];
    }

    // Inserir o n�mero na posi��o correta
    vetor[j] = num;
  }

  printf("O vetor est� ordenado da seguinte forma:\n");

  // Imprimir o vetor ordenado
  for (i = 0; i < N; i++) {
    printf("%d ", vetor[i]);
  }

  printf("\n");

  return 0;
}

