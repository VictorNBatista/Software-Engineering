#include <stdio.h>
#include <locale.h>
#define NUM_MESES 12

// Fun��o para encontrar o �ndice da maior temperatura
int indiceMaiorTemperatura(float *temperaturas){
    int i, indiceMaior = 0;
    for(i = 1; i < NUM_MESES; i++){
        if(*(temperaturas + i) > *(temperaturas + indiceMaior)){
            indiceMaior = i;
        }
    }
    return indiceMaior;
}

// Fun��o para encontrar o �ndice da menor temperatura
int indiceMenorTemperatura(float *temperaturas){
    int i, indiceMenor = 0;
    for(i = 1; i < NUM_MESES; i++){
        if(*(temperaturas + i) < *(temperaturas + indiceMenor)){
            indiceMenor = i;
        }
    }
    return indiceMenor;
}

// Fun��o para mostrar o m�s por extenso
void mostrarMesPorExtenso(int mes){
    switch(mes){
        case 0:
            printf("janeiro");
            break;
        case 1:
            printf("fevereiro");
            break;
        case 2:
            printf("mar�o");
            break;
        case 3:
            printf("abril");
            break;
        case 4:
            printf("maio");
            break;
        case 5:
            printf("junho");
            break;
        case 6:
            printf("julho");
            break;
        case 7:
            printf("agosto");
            break;
        case 8:
            printf("setembro");
            break;
        case 9:
            printf("outubro");
            break;
        case 10:
            printf("novembro");
            break;
        case 11:
            printf("dezembro");
            break;
    }
}

int main(){
    setlocale(LC_ALL,"Portuguese");
    float temperaturas[NUM_MESES];
    int i, indiceMaior, indiceMenor;

    // Recebe a temperatura m�dia de cada m�s
    for(i = 0; i < NUM_MESES; i++){
        printf("Digite a temperatura m�dia do m�s %d: ", i+1);
        scanf("%f", &*(temperaturas + i));
    }

    // Encontra o �ndice do m�s com a maior temperatura
    indiceMaior = indiceMaiorTemperatura(temperaturas);

    // Encontra o �ndice do m�s com a menor temperatura
    indiceMenor = indiceMenorTemperatura(temperaturas);

    // Mostra a maior temperatura do ano e o m�s correspondente
    printf("A maior temperatura do ano foi %.2f em ", *(temperaturas + indiceMaior));
    mostrarMesPorExtenso(indiceMaior);
    printf("\n");

    // Mostra a menor temperatura do ano e o m�s correspondente
    printf("A menor temperatura do ano foi %.2f em ", *(temperaturas + indiceMenor));
    mostrarMesPorExtenso(indiceMenor);
    printf("\n");

}

