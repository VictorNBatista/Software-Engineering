#include <stdio.h>
#include <math.h>
#include <locale.h>

int tamanho = 10;

void preencher_vetor(int vetor[], int tamanho);
void distribuir_elementos(int vetor[], int vetorImpar[], int vetorPar[], int tamanho, int contImp, int contPar);
void mostrar_vetores(int vetorImpar[], int vetorPar[], int contImp, int contPar);


main()
{
	setlocale(LC_ALL,"Portuguese");
	int vetor[tamanho], vetorImpar[tamanho], vetorPar[tamanho],contImp,contPar;
	printf("Preenchendo o vetor...\n");
	preencher_vetor(vetor, tamanho);
	printf("\n\nDistribuindo os elementos...");
	distribuir_elementos(vetor,vetorImpar,vetorPar,tamanho,contImp,contPar);
}

void preencher_vetor(int vetor[], int tamanho){
	for(int i=0; i<tamanho;i++){
		printf("Digite o valor para a posição %d: ", i);
        scanf("%d", &vetor[i]);
	}
	
	printf("Vetor digitado: ");
	for (int i = 0; i < tamanho; i++) {
        printf("%i ", vetor[i]);
    }
}

void distribuir_elementos(int vetor[], int vetorImpar[], int vetorPar[], int tamanho, int contImp, int contPar){
	for(int i=0;i<tamanho;i++){
		if(vetor[i]%2 != 0){
			vetorImpar[contImp] = vetor[i];
			contImp++;
		}
		else{
			vetorPar[contPar] = vetor[i];
			contPar++;	
		}
	}
	mostrar_vetores(vetorImpar,vetorPar,contImp,contPar);
}

void mostrar_vetores(int vetorImpar[], int vetorPar[], int contImp, int contPar){
	printf("\nVetor Par: ");
	for(int i=0;i<contPar;i++){
		printf("%i ",vetorPar[i]);
	}
	printf("\nVetor ímpar: ");
	for(int i=0;i<contImp;i++){
		printf("%i ",vetorImpar[i]);
	}
}
