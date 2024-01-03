#include <stdio.h>
#include <math.h>
#include <locale.h>

void preencher_matriz(int matriz[2][2], int tamanho);
void mostrar_matriz(int matriz[2][2], int tamanho);
float encontrar_maior(int matriz[2][2], int tamanho);
void multiplicar_elementos(int matriz[2][2], int tamanho);

main()
{
	setlocale(LC_ALL,"Portuguese");
	int matriz[2][2];
	printf("Preenchendo a matriz... \n");
	preencher_matriz(matriz, 2);
	mostrar_matriz(matriz, 2);
	printf("\n\nMultiplicando os valores da matriz pelo maior elemento... \n");
	multiplicar_elementos(matriz, 2);
	  
}

void preencher_matriz(int matriz[2][2], int tamanho){
    for (int i = 0; i < tamanho; i++) {
    	for(int j=0; j<tamanho; j++){
        printf("Digite o valor para a posição [%d][%d]: ", i,j);
        scanf("%d", &matriz[i][j]);
       } 
    }
}

void mostrar_matriz(int matriz[2][2], int tamanho){
	printf("Matriz digitada: ");
	for (int i = 0; i < tamanho; i++) {
		printf("\n");
    	for(int j=0; j<tamanho; j++){
        printf("%i ",matriz[i][j]);
       } 
    }
}

float encontrar_maior(int matriz[2][2], int tamanho){
	float maior;
	maior = matriz[0][0];
	for(int i=0; i<tamanho;i++){
		for(int j=0; i<tamanho;i++){
		if (matriz[i][j]>maior)
		maior = matriz[i][j];
	}
	}
	return maior;
}

void multiplicar_elementos(int matriz[2][2], int tamanho){
	float maior;
	int conta[2][2];
	maior= encontrar_maior(matriz, tamanho);
	for(int i=0; i<tamanho;i++){
		for(int j=0; j<tamanho;j++){
		conta[i][j] = matriz[i][j] * maior;
		}
	}
	printf("Nova matriz após a multiplicação: ");
	for(int i=0; i<tamanho;i++){
		printf("\n");
		for(int j=0; j<tamanho; j++){
		printf("%i ",conta[i][j]);
		}
	}
}
