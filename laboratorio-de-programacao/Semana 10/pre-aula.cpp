#include <stdio.h>
#include <locale.h>
#define PRODUTOS 5
#define LOJAS 4

void preencherProdutos(char produtos[][100]);
void preencherPrecos(float precos[][LOJAS], char produtos[][100]);
void preencherImpostos(float precos[][LOJAS], float impostos[][LOJAS]);
void preencherTransporte(float transporte[], char produtos[][100]);
void gerarRelatorio(char produtos[][100], float impostos[][LOJAS], float transporte[], float precos[][LOJAS]);

main() {
	setlocale(LC_ALL, "Portuguese");
    char produtos[PRODUTOS][100];
    float precos[PRODUTOS][LOJAS];
    float impostos[PRODUTOS][LOJAS];
    float transporte[PRODUTOS];

    printf("Preencha as informações dos produtos:\n");
    preencherProdutos(produtos);
    printf("\nPreencha os preços dos produtos nas lojas:\n");
    preencherPrecos(precos,produtos);
    printf("\nPreencha o custo do transporte para cada produto:\n");
    preencherTransporte(transporte, produtos);

    preencherImpostos(precos, impostos);

    gerarRelatorio(produtos, impostos, transporte, precos);

}

void preencherProdutos(char produtos[][100]) {
    int i;
    for (i = 0; i < PRODUTOS; i++) {
        printf("Digite o nome do produto %d: ", i + 1);
        scanf("%s", produtos[i]);
    }
}

void preencherPrecos(float precos[][LOJAS], char produtos[][100]) {
    int i, j;
    for (i = 0; i < PRODUTOS; i++) {
        for (j = 0; j < LOJAS; j++) {
            printf("Digite o preço do(a) *%s* na loja %d: ", produtos[i], j + 1);
            scanf("%f", &precos[i][j]);
        }
    }
}

void preencherImpostos(float precos[][LOJAS], float impostos[][LOJAS]) {
    int i, j;
    for (i = 0; i < PRODUTOS; i++) {
        for (j = 0; j < LOJAS; j++) {
            if (precos[i][j] <= 50)
                impostos[i][j] = 0.05 * precos[i][j];
            else if (precos[i][j] <= 100)
                impostos[i][j] = 0.1 * precos[i][j];
            else
                impostos[i][j] = 0.2 * precos[i][j];
        }
    }
}

void preencherTransporte(float transporte[], char produtos[][100]) {
    int i;
    for (i = 0; i < PRODUTOS; i++) {
        printf("Digite o custo do transporte para o(a) *%s*: ", produtos[i]);
        scanf("%f", &transporte[i]);
    }
}

void gerarRelatorio(char produtos[][100], float impostos[][LOJAS], float transporte[], float precos[][LOJAS]) {
    int i, j;
    printf("\nRELATÓRIO:\n");
    for (i = 0; i < PRODUTOS; i++) {
        printf("Produto: %s\n", produtos[i]);
        for (j = 0; j < LOJAS; j++) {
            printf("Loja: %d\n", j + 1);
            printf("Imposto a pagar: %.2f\n", impostos[i][j]);
            printf("Custo de transporte: %.2f\n", transporte[i]);
            printf("Preço: %.2f\n", precos[i][j]);
            printf("Preço final: %.2f\n", precos[i][j] + impostos[i][j] + transporte[i]);
            printf("\n");
        }
    }
}
