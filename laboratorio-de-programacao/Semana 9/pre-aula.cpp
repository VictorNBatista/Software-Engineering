#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>
#include <stdbool.h>

void preencher_vetor(int primos[10], int num);
void mostrar_vetor(int primos[10]);

bool ehPrimo(int num) {
    if (num <= 1) {
        return false;
    }
    
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    
    return true;
}

main() {
	setlocale(LC_ALL,"Portuguese");
	
    int primos[10];
    int num = 101;  
    
    preencher_vetor(primos,num);
    
    mostrar_vetor(primos);
    
}

void preencher_vetor(int primos[10], int num){
	int cont = 0;
	
	while (cont < 10) {
        if (ehPrimo(num)) {
            primos[cont] = num;
            cont++;
        }
        num++;
    }
}

void mostrar_vetor(int primos[10]){
	printf("Os dez primeiros números primos acima de 100 são:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", primos[i]);
    }
    printf("\n");
}
